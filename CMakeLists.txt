cmake_minimum_required(VERSION 3.10)

project(RayTracer)

find_package(OpenCV REQUIRED)

include_directories(.)
include_directories(../include)
include_directories(Materials Objects Image Camera Lights png Objects/Mesh Transformer)

set(CMAKE_CXX_STANDARD 17)

set(COMPILE_FLAGS
		PRIVATE -pipe
		PRIVATE -march=native
		PRIVATE -Wall
		PRIVATE -Wextra
		PRIVATE -fopenmp
		PRIVATE -O3)

set(LINKER_FLAGS
		-Wl,--as-needed
		-lstdc++
		-lm
		-fopenmp)

set(OBJECTS_SRC
		Objects/sphere.hpp
		Objects/sphere.cpp
		Objects/plan.hpp
		Objects/plan.cpp
		Objects/objet.h
		Objects/objet.cpp
		Objects/triangle.h
		Objects/triangle.cpp
		Objects/Mesh/bounding_box.h
		Objects/Mesh/bounding_box.cpp
		Objects/Mesh/mesh.h
		Objects/Mesh/mesh.cpp
		Objects/Mesh/GeometricModel.h
		Objects/Mesh/GeometricModel.cpp
		Objects/Mesh/OBJLoader.h
		Objects/Mesh/OBJLoader.cpp)

set(MATERIALS_SRC
		Materials/material.h
		Materials/material.cpp
		Materials/phong.h
		Materials/phong.cpp
		Materials/perlin.h
		Materials/perlin.cpp
		Materials/texture.h
		Materials/texture.cpp)

set(IMAGE_SRC
		Image/image_glm.h
		Image/image_glm.cpp
		Image/image_cv.cpp
		Image/image_cv.h
		Image/base_image.h
		Image/base_image.cpp)

set(TRANSFORMER_SRC
		)

set(CAMERA_SRC
		Camera/scene.h
		Camera/scene.cpp
		Camera/rayon.h
		Camera/rayon.cpp
		Camera/camera.h
		Camera/camera.cpp)

set(LIGHTS_SRC
		Lights/light.h
		Lights/light.cpp
		Lights/plan_light.h
		Lights/plan_light.cpp)

add_executable(RayTrace
		png/lodepng.h
		png/lodepng.cpp
		post_process.h
		post_process.cpp
		intersection.cpp
		intersection.h
		main.cpp
		${CAMERA_SRC}
		${IMAGE_SRC}
		${OBJECTS_SRC}
		${MATERIALS_SRC}
		${LIGHTS_SRC}
		${TRANSFORMER_SRC})

target_compile_options(RayTrace ${COMPILE_FLAGS})
target_link_libraries(RayTrace ${LINKER_FLAGS} ${OpenCV_LIBS})