#ifndef COLOR_H
#define COLOR_H

#include <glm/vec3.hpp>
#include <iostream>

using color = glm::vec3;

void write_color(std::ostream &out, color pixel_color) {
	out << int(255.999 * pixel_color.r) << ' '
	    << int(255.999 * pixel_color.g) << ' '
	    << int(255.999 * pixel_color.b) << '\n';
}

#endif
