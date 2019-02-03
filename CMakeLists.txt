cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(RayTracer)

find_package(OpenCV REQUIRED)
find_package(OpenMP REQUIRED)

include_directories(.)
include_directories(Materials Objects Image Camera Lights png Objects/Mesh Transformer Configuration Interfaces)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Intel")
	set(COMPILE_FLAGS
			PRIVATE -Wall
			PRIVATE -Wextra-tokens)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set(COMPILE_FLAGS
			PRIVATE -pipe
			PRIVATE -march=native
			PRIVATE -Wall
			PRIVATE -Wextra)
endif ()

set(LINKER_FLAGS
		-Wl,--as-needed
		-lstdc++
		-lstdc++fs
		-lm)

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

set(CONFIGURATION_SRC
		Configuration/configuration.cpp
		Configuration/configuration.h
		Configuration/json.hpp)

set(INTERFACE_SRC
		Interfaces/from_json.cpp Interfaces/from_json.h)

set(DESIGN_PATTERNS_SRC
		)

set(TEST_SRC
		Tests/catch_trick.cpp
		Tests/tests_config.cpp
		${CONFIGURATION_SRC})

add_executable(RayTrace
		png/lodepng.h
		png/lodepng.cpp
		post_process.h
		post_process.cpp
		intersection.cpp
		intersection.h
		main.cpp
		${CAMERA_SRC}
		${CONFIGURATION_SRC}
		${INTERFACE_SRC}
		${IMAGE_SRC}
		${OBJECTS_SRC}
		${MATERIALS_SRC}
		${LIGHTS_SRC}
		${TRANSFORMER_SRC})

message("-- OpenMP link : ${OpenMP_CXX_LIBRARIES}")

target_compile_options(RayTrace ${COMPILE_FLAGS} ${OpenMP_CXX_FLAGS})
target_link_libraries(RayTrace ${LINKER_FLAGS} ${OpenCV_LIBS} ${OpenMP_CXX_LIBRARIES})

add_executable(TestRayTrace ${TEST_SRC} ${OBJECTS_SRC} ${INTERFACE_SRC})
target_compile_options(TestRayTrace ${COMPILE_FLAGS})
target_link_libraries(TestRayTrace ${LINKER_FLAGS})
