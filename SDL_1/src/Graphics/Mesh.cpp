#include "pch.h"
#include "Mesh.h"


Mesh::Mesh(std::vector<Vertex>&& vertices, std::vector<unsigned int>&& indices, std::vector<Texture>&& textures)
	:vec_Verticies(std::move(vertices))
	,vec_Indices(std::move(indices))
	,vec_Textures(std::move(textures))
{
	SetupMesh();
}


Mesh::~Mesh()
{
}

void Mesh::SetupMesh() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vec_Verticies.size(), &vec_Verticies[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * vec_Indices.size(), &vec_Indices[0], GL_STATIC_DRAW);

	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	// Normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

	// Texture Coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TextureCoord));

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

}

void Mesh::Draw(Shader& shader) {
	int diffuseCount = 1;
	int specularCount = 1;
	for (unsigned int i = 0; i < vec_Textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);	// Activate texture unit before binding

		std::string number;
		std::string name = vec_Textures[i].type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseCount++);
		else if (name == "texture_specular")
			number = std::to_string(specularCount++);

		glBindTexture(GL_TEXTURE_2D, vec_Textures[i].id);	// Bind Texture
		shader.SetUniform1i(i, ("material." + name + number).c_str());	// Assign the number of the texture unit to the uniform
		//glBindTexture(GL_TEXTURE_2D, vec_Textures[i].id);	// Bind Texture
	}
	glActiveTexture(GL_TEXTURE0);	// Unbind it to default

	// Draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, vec_Indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
