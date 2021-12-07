#ifndef COLOR_H
#define COLOR_H

#include <glm/vec3.hpp>
#include <iostream>

using color = glm::dvec3;

void write_color(std::ostream &out, color pixel_color) {
	out << static_cast<int>(255.999 * pixel_color.r) << ' '
	    << static_cast<int>(255.999 * pixel_color.g) << ' '
	    << static_cast<int>(255.999 * pixel_color.b) << '\n';
}

#endif
