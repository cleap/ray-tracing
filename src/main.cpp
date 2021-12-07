#include <iostream>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/geometric.hpp>
#include <glm/gtx/norm.hpp>
#include "color.hpp"
#include "ray.hpp"

double hit_sphere(const glm::dvec3& center, double radius, const ray& r) {
	glm::dvec3 oc = r.origin() - center;
	auto a = glm::length2(r.direction());
	auto half_b = glm::dot(oc, r.direction());
	auto c = glm::length2(oc) - radius*radius;
	auto discriminant = half_b*half_b - a*c;
	if (discriminant < 0) {
		return -1.0;
	} else {
		return (-half_b - sqrt(discriminant)) / a;
	}
}

color ray_color(const ray& r) {
	auto t = hit_sphere(glm::dvec3(0, 0, -1), 0.5, r);
	if (t > 0.0) {
		glm::dvec3 N = glm::normalize(r.at(t) - glm::dvec3(0, 0, -1));
		return 0.5*color(N.x+1, N.y+1, N.z+1);
	}
	glm::vec3 unit_direction = glm::normalize(r.direction());
	t = 0.5 * (unit_direction.y + 1.0);
	return (1.0 - t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {
	
	// Image
	
	const auto ASPECT_RATIO = 16.0 / 9.0;
	const int IMAGE_WIDTH  = 400;
	const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

	// Camera
	
	auto viewport_height = 2.0;
	auto viewport_width = ASPECT_RATIO * viewport_height;
	auto focal_length = 1.0;

	auto origin = glm::dvec3(0, 0, 0);
	auto horizontal = glm::dvec3(viewport_width, 0, 0);
	auto vertical = glm::dvec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal/2.0 - vertical/2.0 - glm::dvec3(0, 0, focal_length);

	// Render
	
	std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

	for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < IMAGE_WIDTH; ++i) {
			auto u = double(i) / (IMAGE_WIDTH-1);
			auto v = double(j) / (IMAGE_HEIGHT-1);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}
}
