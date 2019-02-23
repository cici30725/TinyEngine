#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 MVP;

out vec2 TexCoord;
void main()
{
   gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);
   TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}

#shader fragment
#version 330 core
in vec2 TexCoord;

out vec4 FragColor;

struct Material {
	sampler2D texture_diffuse1;
};

uniform Material material;

void main()
{
	FragColor = texture(material.texture_diffuse1, TexCoord);
}