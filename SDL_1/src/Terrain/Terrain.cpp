#include "pch.h"
#include "Terrain.h"
#include "stb_image.h"

Terrain::Terrain(const std::string& filepath) {
	int w, h, c;
	stbi_uc* data = stbi_load(filepath.c_str(), &w, &h, &c, 1);

	if(data)
		std::cout << "width:" << w << " height:" << h << " channels:" << c << std::endl;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			std::cout << (unsigned int)data[y * w + x] << " ";
		}
		std::cout << "\n";
	}

}