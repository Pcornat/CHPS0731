CXX = g++
CXXFLAGS = -pipe -march=native -std=c++17 -Wall -Wextra -O3 -fopenmp -I../include
LDLIBS = -lstdc++ -lm
LDFLAGS = -pipe -O3 -fopenmp

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o) png/lodepng.o

EXE = prog

.PHONY:	clean mrproper

all:	depend $(EXE)

$(EXE): depend $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# makedepend: le package xutils-dev doit être installé
#EDIT personnel : (sous Ubuntu/Debian c'est valide)
depend:
	@makedepend -- $(CXXFLAGS) -- -Y $(SRCS) 2> /dev/null

clean:
	rm -f *.o

mrproper:	clean
	rm -f $(EXE)

# DO NOT DELETE THIS LINE

mesh.o: Objects/Mesh/mesh.h Objects/objet.h intersection.h Materials/material.h Objects/Mesh/GeometricModel.h Objects/Mesh/OBJLoader.h
mesh.o: Objects/plan.hpp Camera/rayon.h Camera/scene.h Objects/Mesh/bounding_box.h
bounding_box.o: Objects/Mesh/bounding_box.h Objects/objet.h intersection.h Materials/material.h Objects/plan.hpp
bounding_box.o: Camera/rayon.h Camera/scene.h
image.o: Image/image.h png/lodepng.h
plan.o: Objects/plan.hpp Objects/objet.h intersection.h Materials/material.h Camera/rayon.h Camera/scene.h Materials/phong.h
plan.o: Lights/light.h
scene.o: Camera/scene.h
phong.o: Materials/phong.h Materials/material.h intersection.h Lights/light.h Camera/rayon.h Camera/scene.h
sphere.o: Objects/sphere.hpp Objects/objet.h intersection.h Materials/material.h Camera/rayon.h Camera/scene.h
sphere.o: Materials/phong.h Lights/light.h
triangle.o: Objects/triangle.h Objects/objet.h intersection.h Materials/material.h Camera/rayon.h Camera/scene.h
light.o: Lights/light.h Camera/rayon.h Camera/scene.h intersection.h
intersection.o: intersection.h
rayon.o: Camera/rayon.h Camera/scene.h intersection.h Objects/objet.h Materials/material.h
camera.o: Camera/camera.h Camera/scene.h Camera/rayon.h intersection.h Image/image.h
texture.o: Materials/texture.h Materials/material.h intersection.h Objects/Mesh/mesh.h Objects/objet.h
texture.o: Objects/Mesh/GeometricModel.h Objects/Mesh/OBJLoader.h Objects/plan.hpp Camera/rayon.h Camera/scene.h
texture.o: Objects/Mesh/bounding_box.h
main.o: Image/image.h Camera/camera.h Camera/scene.h Camera/rayon.h intersection.h Objects/objet.h Materials/material.h
main.o: Objects/sphere.hpp Objects/plan.hpp Materials/phong.h Lights/light.h Lights/plan_light.h Objects/Mesh/mesh.h
main.o: Objects/Mesh/GeometricModel.h Objects/Mesh/OBJLoader.h Objects/Mesh/bounding_box.h
GeometricModel.o: Objects/Mesh/GeometricModel.h Objects/Mesh/OBJLoader.h
OBJLoader.o: Objects/Mesh/OBJLoader.h Objects/Mesh/GeometricModel.h
plan_light.o: Lights/plan_light.h Lights/light.h Camera/rayon.h Camera/scene.h intersection.h
