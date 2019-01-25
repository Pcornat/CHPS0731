cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(RayTracer)

find_package(OpenCV REQUIRED)
find_package(OpenMP REQUIRED)

include_directories(.)
include_directories(../../include)
include_directories(Materials Objects Image Camera Effects Lights png Objects/Mesh Transformer)

set(CMAKE_CXX_STANDARD 17)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Intel")
	set(COMPILE_FLAGS
			PRIVATE -Wall
			PRIVATE -Wextra-tokens)

	set(CMAKE_CXX_FLAGS_RELEASE
			-Ofast
			-DNDEBUG)

	set(CMAKE_CXX_FLAGS_DEBUG
			-g3)

	set(LINKER_FLAGS
			-Wl,--as-needed
			-shared-intel
			-lm)

elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set(COMPILE_FLAGS
			PRIVATE -pipe
			PRIVATE -march=native
			PRIVATE -Wall
			PRIVATE -Wextra)

	set(LINKER_FLAGS
			-Wl,--as-needed
			-lstdc++
			-lm)
endif ()

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

set(TREE_SRC
		Tree/k_dtree.cpp Tree/k_dtree.h Tree/k_dnode.cpp Tree/k_dnode.h Tree/kd_tree_iterator.cpp Tree/kd_tree_iterator.h)

set(CAMERA_SRC
		Camera/scene.h
		Camera/scene.cpp
		Camera/rayon.h
		Camera/rayon.cpp
		Camera/camera.h
		Camera/camera.cpp)

set(EFFECTS_SRC
		Effects/post_process.h
		Effects/post_process.cpp
		Effects/effect.h
		Effects/histogram_equaliser_cv.cpp
		Effects/histogram_equaliser_cv.h)

set(LIGHTS_SRC
		Lights/light.h
		Lights/light.cpp
		Lights/plan_light.h
		Lights/plan_light.cpp Tree/k_dtree.cpp Tree/k_dtree.h)

add_executable(RayTrace
		png/lodepng.h
		png/lodepng.cpp
		intersection.cpp
		intersection.h
		main.cpp
		${CAMERA_SRC}
		${IMAGE_SRC}
		${OBJECTS_SRC}
		${MATERIALS_SRC}
		${LIGHTS_SRC}
		${TRANSFORMER_SRC}
		${TREE_SRC}
		${EFFECTS_SRC})

target_compile_options(RayTrace ${COMPILE_FLAGS} ${OpenMP_CXX_FLAGS})
target_link_libraries(RayTrace ${LINKER_FLAGS} ${OpenMP_CXX_LIBRARIES} ${OpenCV_LIBS})