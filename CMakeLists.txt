cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(RayTracer)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	set(OpenCV_DIR "$ENV{HOME}/Codes/softs/debug/lib64/cmake/opencv4/")
	find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs)
	include_directories(${OpenCV_INCLUDE_DIRS})
else ()
	find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs)
	include_directories(${OpenCV_INCLUDE_DIRS})
endif ()
find_package(OpenMP REQUIRED)

include_directories(.)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LINKER_OPTIONS
	PRIVATE -Wl,--sort-common,--as-needed)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set(COMPILE_FLAGS
		-pipe
		-march=skylake
		-mtune=skylake
		-Wall
		-Wextra
		-Wpessimizing-move
		-Wredundant-move
		-flto
		-fuse-linker-plugin
		-fuse-ld=gold)
	set(LINKER_OPTIONS
		-flto
		-fuse-linker-plugin
		-fuse-ld=gold
		${LINKER_OPTIONS})

	set(LINKER_FLAGS
		stdc++
		stdc++fs
		m)
endif ()


set(OBJECTS_SRC
	Objects/sphere.hpp
	Objects/sphere.cpp
	Objects/plan.hpp
	Objects/plan.cpp
	Objects/objet.h
	Objects/objet.cpp
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
	Configuration/json.hpp)

set(DESIGN_PATTERNS_SRC
	DeSerializer/deserializer.cpp
	DeSerializer/deserializer.h)

set(TEST_SRC
	Tests/catch_trick.cpp
	Tests/tests_config.cpp
	${CONFIGURATION_SRC})

add_executable(RayTrace
			   png/lodepng.h
			   png/lodepng.cpp
			   intersection.cpp
			   intersection.h
			   main.cpp
			   ${CAMERA_SRC}
			   ${CONFIGURATION_SRC}
			   ${IMAGE_SRC}
			   ${OBJECTS_SRC}
			   ${MATERIALS_SRC}
			   ${LIGHTS_SRC}
			   ${TRANSFORMER_SRC}
			   ${DESIGN_PATTERNS_SRC})

target_compile_definitions(RayTrace PRIVATE $<$<CONFIG:Debug>:_GLIBCXX_DEBUG>)
target_compile_options(RayTrace PRIVATE ${COMPILE_FLAGS} ${OpenMP_CXX_FLAGS})
target_link_options(RayTrace PRIVATE ${LINKER_OPTIONS})
target_link_libraries(RayTrace ${LINKER_FLAGS} ${OpenCV_LIBS} OpenMP::OpenMP_CXX)

add_executable(TestRayTrace ${TEST_SRC}
			   png/lodepng.h
			   png/lodepng.cpp
			   intersection.cpp
			   intersection.h
			   ${CAMERA_SRC}
			   ${CONFIGURATION_SRC}
			   ${IMAGE_SRC}
			   ${OBJECTS_SRC}
			   ${MATERIALS_SRC}
			   ${LIGHTS_SRC}
			   ${TRANSFORMER_SRC}
			   ${DESIGN_PATTERNS_SRC})
target_compile_definitions(TestRayTrace PRIVATE $<$<CONFIG:Debug>:_GLIBCXX_DEBUG>)
target_compile_options(TestRayTrace PRIVATE ${COMPILE_FLAGS} ${OpenMP_CXX_FLAGS})
target_link_options(TestRayTrace PRIVATE ${LINKER_OPTIONS})
target_link_libraries(TestRayTrace ${LINKER_FLAGS} ${OpenCV_LIBS} OpenMP::OpenMP_CXX)
