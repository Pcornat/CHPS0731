CXX = g++
CXXFLAGS = -pipe -march=native -std=c++11 -Wall -Wextra -O3
LDLIBS = -lstdc++ -lm
LDFLAGS = -pipe -O3

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

sphere.o: sphere.hpp objet.h intersection.h material.h rayon.h scene.h
intersection.o: intersection.h
image.o: image.h png/lodepng.h
scene.o: scene.h
phong.o: phong.h material.h intersection.h light.h scene.h rayon.h
light.o: light.h
rayon.o: rayon.h scene.h intersection.h objet.h material.h
camera.o: camera.h scene.h rayon.h intersection.h image.h
main.o: image.h camera.h scene.h rayon.h intersection.h objet.h material.h
main.o: sphere.hpp phong.h light.h
plan.o: plan.hpp objet.h intersection.h material.h
