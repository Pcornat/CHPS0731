CXX = g++
CXXFLAGS = -pipe -march=native -std=c++11 -Wall -Wextra -O3 -fopenmp -I../include
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

sphere.o: sphere.hpp objet.h intersection.h material.h rayon.h scene.h
sphere.o: phong.hpp light.h
intersection.o: intersection.h
plan.o: plan.hpp objet.h intersection.h material.h rayon.h scene.h phong.hpp
plan.o: light.h
scene.o: scene.h
phong.o: phong.hpp material.h intersection.h light.h scene.h rayon.h
triangle.o: triangle.h objet.h intersection.h material.h rayon.h scene.h
image.o: image.h png/lodepng.h
light.o: light.h
rayon.o: rayon.h scene.h intersection.h objet.h material.h
camera.o: camera.h scene.h rayon.h intersection.h image.h
main.o: image.h camera.h scene.h rayon.h intersection.h objet.h material.h
main.o: sphere.hpp triangle.h plan.hpp phong.hpp light.h plan_light.h
GeometricModel.o: GeometricModel.h glm/glm.hpp glm/detail/_fixes.hpp
GeometricModel.o: glm/detail/setup.hpp glm/simd/platform.h glm/fwd.hpp
GeometricModel.o: glm/detail/qualifier.hpp glm/detail/setup.hpp glm/vec2.hpp
GeometricModel.o: glm/./ext/vector_bool2.hpp glm/./detail/type_vec2.hpp
GeometricModel.o: glm/./detail/qualifier.hpp glm/./detail/type_vec2.inl
GeometricModel.o: glm/./detail/./compute_vector_relational.hpp
GeometricModel.o: glm/./ext/vector_bool2_precision.hpp
GeometricModel.o: glm/./ext/vector_float2.hpp
GeometricModel.o: glm/./ext/vector_float2_precision.hpp
GeometricModel.o: glm/./ext/vector_double2.hpp
GeometricModel.o: glm/./ext/vector_double2_precision.hpp
GeometricModel.o: glm/./ext/vector_int2.hpp
GeometricModel.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
GeometricModel.o: glm/./ext/vector_uint2.hpp
GeometricModel.o: glm/./ext/vector_uint2_precision.hpp glm/vec3.hpp
GeometricModel.o: glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
GeometricModel.o: glm/./detail/type_vec3.inl
GeometricModel.o: glm/./detail/compute_vector_relational.hpp
GeometricModel.o: glm/./ext/vector_bool3_precision.hpp
GeometricModel.o: glm/./ext/vector_float3.hpp
GeometricModel.o: glm/./ext/vector_float3_precision.hpp
GeometricModel.o: glm/./ext/vector_double3.hpp
GeometricModel.o: glm/./ext/vector_double3_precision.hpp
GeometricModel.o: glm/./ext/vector_int3.hpp
GeometricModel.o: glm/./ext/vector_int3_precision.hpp
GeometricModel.o: glm/./ext/vector_uint3.hpp
GeometricModel.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
GeometricModel.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
GeometricModel.o: glm/./detail/type_vec4.inl
GeometricModel.o: glm/./ext/vector_bool4_precision.hpp
GeometricModel.o: glm/./ext/vector_float4.hpp
GeometricModel.o: glm/./ext/vector_float4_precision.hpp
GeometricModel.o: glm/./ext/vector_double4.hpp
GeometricModel.o: glm/./ext/vector_double4_precision.hpp
GeometricModel.o: glm/./ext/vector_int4.hpp
GeometricModel.o: glm/./ext/vector_int4_precision.hpp
GeometricModel.o: glm/./ext/vector_uint4.hpp
GeometricModel.o: glm/./ext/vector_uint4_precision.hpp glm/mat2x2.hpp
GeometricModel.o: glm/./ext/matrix_double2x2.hpp glm/./detail/type_mat2x2.hpp
GeometricModel.o: glm/./detail/type_vec2.hpp glm/./detail/type_mat2x2.inl
GeometricModel.o: glm/./matrix.hpp glm/./mat2x3.hpp
GeometricModel.o: glm/././ext/matrix_double2x3.hpp
GeometricModel.o: glm/././detail/type_mat2x3.hpp glm/././detail/type_vec3.hpp
GeometricModel.o: glm/././detail/type_mat2x3.inl
GeometricModel.o: glm/././ext/matrix_double2x3_precision.hpp
GeometricModel.o: glm/././ext/matrix_float2x3.hpp
GeometricModel.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
GeometricModel.o: glm/././ext/matrix_double2x4.hpp
GeometricModel.o: glm/././detail/type_mat2x4.hpp glm/././detail/type_vec4.hpp
GeometricModel.o: glm/././detail/type_mat2x4.inl
GeometricModel.o: glm/././ext/matrix_double2x4_precision.hpp
GeometricModel.o: glm/././ext/matrix_float2x4.hpp
GeometricModel.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
GeometricModel.o: glm/././ext/matrix_double3x2.hpp
GeometricModel.o: glm/././detail/type_mat3x2.hpp
GeometricModel.o: glm/././detail/type_mat3x2.inl
GeometricModel.o: glm/././ext/matrix_double3x2_precision.hpp
GeometricModel.o: glm/././ext/matrix_float3x2.hpp
GeometricModel.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
GeometricModel.o: glm/././ext/matrix_double3x3.hpp
GeometricModel.o: glm/././detail/type_mat3x3.hpp
GeometricModel.o: glm/././detail/type_mat3x3.inl
GeometricModel.o: glm/././ext/matrix_double3x3_precision.hpp
GeometricModel.o: glm/././ext/matrix_float3x3.hpp
GeometricModel.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
GeometricModel.o: glm/././ext/matrix_double3x4.hpp
GeometricModel.o: glm/././detail/type_mat3x4.hpp
GeometricModel.o: glm/././detail/type_mat3x4.inl
GeometricModel.o: glm/././ext/matrix_double3x4_precision.hpp
GeometricModel.o: glm/././ext/matrix_float3x4.hpp
GeometricModel.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
GeometricModel.o: glm/././ext/matrix_double4x2.hpp
GeometricModel.o: glm/././detail/type_mat4x2.hpp
GeometricModel.o: glm/././detail/type_mat4x2.inl
GeometricModel.o: glm/././ext/matrix_double4x2_precision.hpp
GeometricModel.o: glm/././ext/matrix_float4x2.hpp
GeometricModel.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
GeometricModel.o: glm/././ext/matrix_double4x3.hpp
GeometricModel.o: glm/././detail/type_mat4x3.hpp
GeometricModel.o: glm/././detail/type_mat4x3.inl
GeometricModel.o: glm/././ext/matrix_double4x3_precision.hpp
GeometricModel.o: glm/././ext/matrix_float4x3.hpp
GeometricModel.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
GeometricModel.o: glm/././ext/matrix_double4x4.hpp
GeometricModel.o: glm/././detail/type_mat4x4.hpp
GeometricModel.o: glm/././detail/type_mat4x4.inl
GeometricModel.o: glm/././ext/matrix_double4x4_precision.hpp
GeometricModel.o: glm/././ext/matrix_float4x4.hpp
GeometricModel.o: glm/././ext/matrix_float4x4_precision.hpp
GeometricModel.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
GeometricModel.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
GeometricModel.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
GeometricModel.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
GeometricModel.o: glm/./detail/type_vec4.hpp
GeometricModel.o: glm/./detail/func_exponential.inl
GeometricModel.o: glm/./vector_relational.hpp
GeometricModel.o: glm/./detail/func_vector_relational.inl
GeometricModel.o: glm/./detail/_vectorize.hpp glm/./common.hpp
GeometricModel.o: glm/./detail/func_common.inl
GeometricModel.o: glm/./detail/compute_common.hpp
GeometricModel.o: glm/./ext/matrix_double2x2_precision.hpp
GeometricModel.o: glm/./ext/matrix_float2x2.hpp
GeometricModel.o: glm/./ext/matrix_float2x2_precision.hpp
GeometricModel.o: glm/trigonometric.hpp glm/detail/func_trigonometric.inl
GeometricModel.o: glm/exponential.hpp glm/common.hpp glm/packing.hpp
GeometricModel.o: glm/detail/func_packing.inl glm/detail/type_half.hpp
GeometricModel.o: glm/detail/type_half.inl glm/geometric.hpp glm/matrix.hpp
GeometricModel.o: glm/vector_relational.hpp glm/integer.hpp
GeometricModel.o: glm/detail/func_integer.inl OBJLoader.h
OBJLoader.o: OBJLoader.h GeometricModel.h glm/glm.hpp glm/detail/_fixes.hpp
OBJLoader.o: glm/detail/setup.hpp glm/simd/platform.h glm/fwd.hpp
OBJLoader.o: glm/detail/qualifier.hpp glm/detail/setup.hpp glm/vec2.hpp
OBJLoader.o: glm/./ext/vector_bool2.hpp glm/./detail/type_vec2.hpp
OBJLoader.o: glm/./detail/qualifier.hpp glm/./detail/type_vec2.inl
OBJLoader.o: glm/./detail/./compute_vector_relational.hpp
OBJLoader.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
OBJLoader.o: glm/./ext/vector_float2_precision.hpp
OBJLoader.o: glm/./ext/vector_double2.hpp
OBJLoader.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
OBJLoader.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
OBJLoader.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
OBJLoader.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp
OBJLoader.o: glm/./detail/type_vec3.hpp glm/./detail/type_vec3.inl
OBJLoader.o: glm/./detail/compute_vector_relational.hpp
OBJLoader.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
OBJLoader.o: glm/./ext/vector_float3_precision.hpp
OBJLoader.o: glm/./ext/vector_double3.hpp
OBJLoader.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
OBJLoader.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
OBJLoader.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
OBJLoader.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
OBJLoader.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
OBJLoader.o: glm/./ext/vector_float4.hpp
OBJLoader.o: glm/./ext/vector_float4_precision.hpp
OBJLoader.o: glm/./ext/vector_double4.hpp
OBJLoader.o: glm/./ext/vector_double4_precision.hpp glm/./ext/vector_int4.hpp
OBJLoader.o: glm/./ext/vector_int4_precision.hpp glm/./ext/vector_uint4.hpp
OBJLoader.o: glm/./ext/vector_uint4_precision.hpp glm/mat2x2.hpp
OBJLoader.o: glm/./ext/matrix_double2x2.hpp glm/./detail/type_mat2x2.hpp
OBJLoader.o: glm/./detail/type_vec2.hpp glm/./detail/type_mat2x2.inl
OBJLoader.o: glm/./matrix.hpp glm/./mat2x3.hpp
OBJLoader.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
OBJLoader.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
OBJLoader.o: glm/././ext/matrix_double2x3_precision.hpp
OBJLoader.o: glm/././ext/matrix_float2x3.hpp
OBJLoader.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
OBJLoader.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
OBJLoader.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
OBJLoader.o: glm/././ext/matrix_double2x4_precision.hpp
OBJLoader.o: glm/././ext/matrix_float2x4.hpp
OBJLoader.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
OBJLoader.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
OBJLoader.o: glm/././detail/type_mat3x2.inl
OBJLoader.o: glm/././ext/matrix_double3x2_precision.hpp
OBJLoader.o: glm/././ext/matrix_float3x2.hpp
OBJLoader.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
OBJLoader.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
OBJLoader.o: glm/././detail/type_mat3x3.inl
OBJLoader.o: glm/././ext/matrix_double3x3_precision.hpp
OBJLoader.o: glm/././ext/matrix_float3x3.hpp
OBJLoader.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
OBJLoader.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
OBJLoader.o: glm/././detail/type_mat3x4.inl
OBJLoader.o: glm/././ext/matrix_double3x4_precision.hpp
OBJLoader.o: glm/././ext/matrix_float3x4.hpp
OBJLoader.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
OBJLoader.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
OBJLoader.o: glm/././detail/type_mat4x2.inl
OBJLoader.o: glm/././ext/matrix_double4x2_precision.hpp
OBJLoader.o: glm/././ext/matrix_float4x2.hpp
OBJLoader.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
OBJLoader.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
OBJLoader.o: glm/././detail/type_mat4x3.inl
OBJLoader.o: glm/././ext/matrix_double4x3_precision.hpp
OBJLoader.o: glm/././ext/matrix_float4x3.hpp
OBJLoader.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
OBJLoader.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
OBJLoader.o: glm/././detail/type_mat4x4.inl
OBJLoader.o: glm/././ext/matrix_double4x4_precision.hpp
OBJLoader.o: glm/././ext/matrix_float4x4.hpp
OBJLoader.o: glm/././ext/matrix_float4x4_precision.hpp
OBJLoader.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
OBJLoader.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
OBJLoader.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
OBJLoader.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
OBJLoader.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
OBJLoader.o: glm/./vector_relational.hpp
OBJLoader.o: glm/./detail/func_vector_relational.inl
OBJLoader.o: glm/./detail/_vectorize.hpp glm/./common.hpp
OBJLoader.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
OBJLoader.o: glm/./ext/matrix_double2x2_precision.hpp
OBJLoader.o: glm/./ext/matrix_float2x2.hpp
OBJLoader.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
OBJLoader.o: glm/detail/func_trigonometric.inl glm/exponential.hpp
OBJLoader.o: glm/common.hpp glm/packing.hpp glm/detail/func_packing.inl
OBJLoader.o: glm/detail/type_half.hpp glm/detail/type_half.inl
OBJLoader.o: glm/geometric.hpp glm/matrix.hpp glm/vector_relational.hpp
OBJLoader.o: glm/integer.hpp glm/detail/func_integer.inl
plan_light.o: plan_light.h light.h
