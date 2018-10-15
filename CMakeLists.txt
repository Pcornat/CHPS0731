cmake_minimum_required(VERSION 3.10)

include_directories(.)
include_directories(./png)

add_executable(RayTrace
		png/lodepng.h
		png/lodepng.cpp
		camera.cpp
		camera.h
		objet.cpp
		objet.h
		material.cpp
		material.h
		phong.cpp
		phong.hpp
		plan.cpp
		plan.hpp
		rayon.cpp
		rayon.h
		scene.cpp
		scene.h
		sphere.cpp
		sphere.hpp
		image.cpp
		image.h
		intersection.cpp
		intersection.h
		light.cpp
		light.h
		main.cpp
		triangle.cpp
		triangle.h
		GeometricModel.cpp
		GeometricModel.h
		OBJLoader.cpp
		OBJLoader.h)