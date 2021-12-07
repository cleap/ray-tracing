#include <iostream>
#include <glm/vec3.hpp> // glm::vec3
#include "color.hpp"

int main() {
	
	// Image
	
	const int IMAGE_WIDTH  = 256;
	const int IMAGE_HEIGHT = 256;

	// Render
	
	std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

	for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < IMAGE_WIDTH; ++i) {
			color pixel_color(double(i) / (IMAGE_WIDTH - 1), 
					  double(j) / (IMAGE_HEIGHT - 1),
					  0.25);
			write_color(std::cout, pixel_color);
		}
	}
}
