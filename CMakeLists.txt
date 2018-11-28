cmake_minimum_required(VERSION 3.10)

include_directories(.)
include_directories(./png)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -march=native -std=c++14 -Wall -Wextra -fopenmp")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++ -lm -fopenmp")

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
		OBJLoader.h
		plan_light.cpp
		plan_light.h
		mesh.cpp
		mesh.h
		bounding_box.cpp
		bounding_box.h perlin.cpp perlin.h)