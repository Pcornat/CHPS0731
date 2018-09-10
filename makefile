CXX = g++
CXXFLAGS = -pipe -Wall -Wextra -O3
LDLIBS = -lstdc++ -lm
LDFLAGS = -pipe -O3

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o) png/lodepng.o

EXE = prog

.PHONY:	clean mrproper

all:	clean depend $(EXE)

$(EXE): depend $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# makedepend: le package xutils-dev doit être installé
#EDIT personnel :(sous Ubuntu/Debian c'est valide)
depend:
	@makedepend -- $(CXXFLAGS) -- -Y $(SRCS) 2> /dev/null
#	$(OBJS) = $(wildcard *.o) $(wildcard */*.o)

clean:
#rm -f $(OBJS)
	rm -f *.o

mrproper:	clean
	rm -f $(EXE)

# DO NOT DELETE THIS LINE

objet.o: rayon.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
objet.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
objet.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
objet.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
objet.o: glm/./detail/type_vec2.inl
objet.o: glm/./detail/./compute_vector_relational.hpp
objet.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
objet.o: glm/./ext/vector_float2_precision.hpp glm/./ext/vector_double2.hpp
objet.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
objet.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
objet.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
objet.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
objet.o: glm/./detail/type_vec3.inl
objet.o: glm/./detail/compute_vector_relational.hpp
objet.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
objet.o: glm/./ext/vector_float3_precision.hpp glm/./ext/vector_double3.hpp
objet.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
objet.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
objet.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
objet.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
objet.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
objet.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
objet.o: glm/./ext/vector_double4.hpp glm/./ext/vector_double4_precision.hpp
objet.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
objet.o: glm/./ext/vector_uint4.hpp glm/./ext/vector_uint4_precision.hpp
objet.o: glm/mat2x2.hpp glm/./ext/matrix_double2x2.hpp
objet.o: glm/./detail/type_mat2x2.hpp glm/./detail/type_vec2.hpp
objet.o: glm/./detail/type_mat2x2.inl glm/./matrix.hpp glm/./mat2x3.hpp
objet.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
objet.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
objet.o: glm/././ext/matrix_double2x3_precision.hpp
objet.o: glm/././ext/matrix_float2x3.hpp
objet.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
objet.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
objet.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
objet.o: glm/././ext/matrix_double2x4_precision.hpp
objet.o: glm/././ext/matrix_float2x4.hpp
objet.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
objet.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
objet.o: glm/././detail/type_mat3x2.inl
objet.o: glm/././ext/matrix_double3x2_precision.hpp
objet.o: glm/././ext/matrix_float3x2.hpp
objet.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
objet.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
objet.o: glm/././detail/type_mat3x3.inl
objet.o: glm/././ext/matrix_double3x3_precision.hpp
objet.o: glm/././ext/matrix_float3x3.hpp
objet.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
objet.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
objet.o: glm/././detail/type_mat3x4.inl
objet.o: glm/././ext/matrix_double3x4_precision.hpp
objet.o: glm/././ext/matrix_float3x4.hpp
objet.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
objet.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
objet.o: glm/././detail/type_mat4x2.inl
objet.o: glm/././ext/matrix_double4x2_precision.hpp
objet.o: glm/././ext/matrix_float4x2.hpp
objet.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
objet.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
objet.o: glm/././detail/type_mat4x3.inl
objet.o: glm/././ext/matrix_double4x3_precision.hpp
objet.o: glm/././ext/matrix_float4x3.hpp
objet.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
objet.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
objet.o: glm/././detail/type_mat4x4.inl
objet.o: glm/././ext/matrix_double4x4_precision.hpp
objet.o: glm/././ext/matrix_float4x4.hpp
objet.o: glm/././ext/matrix_float4x4_precision.hpp
objet.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
objet.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
objet.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
objet.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
objet.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
objet.o: glm/./vector_relational.hpp glm/./detail/func_vector_relational.inl
objet.o: glm/./detail/_vectorize.hpp glm/./common.hpp
objet.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
objet.o: glm/./ext/matrix_double2x2_precision.hpp
objet.o: glm/./ext/matrix_float2x2.hpp
objet.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
objet.o: glm/detail/func_trigonometric.inl glm/exponential.hpp glm/common.hpp
objet.o: glm/packing.hpp glm/detail/func_packing.inl glm/detail/type_half.hpp
objet.o: glm/detail/type_half.inl glm/geometric.hpp glm/matrix.hpp
objet.o: glm/vector_relational.hpp glm/integer.hpp
objet.o: glm/detail/func_integer.inl scene.h intersection.h objet.h
objet.o: material.h
intersection.o: intersection.h glm/glm.hpp glm/detail/_fixes.hpp
intersection.o: glm/detail/setup.hpp glm/simd/platform.h glm/fwd.hpp
intersection.o: glm/detail/qualifier.hpp glm/detail/setup.hpp glm/vec2.hpp
intersection.o: glm/./ext/vector_bool2.hpp glm/./detail/type_vec2.hpp
intersection.o: glm/./detail/qualifier.hpp glm/./detail/type_vec2.inl
intersection.o: glm/./detail/./compute_vector_relational.hpp
intersection.o: glm/./ext/vector_bool2_precision.hpp
intersection.o: glm/./ext/vector_float2.hpp
intersection.o: glm/./ext/vector_float2_precision.hpp
intersection.o: glm/./ext/vector_double2.hpp
intersection.o: glm/./ext/vector_double2_precision.hpp
intersection.o: glm/./ext/vector_int2.hpp glm/./ext/vector_int2_precision.hpp
intersection.o: glm/./detail/setup.hpp glm/./ext/vector_uint2.hpp
intersection.o: glm/./ext/vector_uint2_precision.hpp glm/vec3.hpp
intersection.o: glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
intersection.o: glm/./detail/type_vec3.inl
intersection.o: glm/./detail/compute_vector_relational.hpp
intersection.o: glm/./ext/vector_bool3_precision.hpp
intersection.o: glm/./ext/vector_float3.hpp
intersection.o: glm/./ext/vector_float3_precision.hpp
intersection.o: glm/./ext/vector_double3.hpp
intersection.o: glm/./ext/vector_double3_precision.hpp
intersection.o: glm/./ext/vector_int3.hpp glm/./ext/vector_int3_precision.hpp
intersection.o: glm/./ext/vector_uint3.hpp
intersection.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
intersection.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
intersection.o: glm/./detail/type_vec4.inl
intersection.o: glm/./ext/vector_bool4_precision.hpp
intersection.o: glm/./ext/vector_float4.hpp
intersection.o: glm/./ext/vector_float4_precision.hpp
intersection.o: glm/./ext/vector_double4.hpp
intersection.o: glm/./ext/vector_double4_precision.hpp
intersection.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
intersection.o: glm/./ext/vector_uint4.hpp
intersection.o: glm/./ext/vector_uint4_precision.hpp glm/mat2x2.hpp
intersection.o: glm/./ext/matrix_double2x2.hpp glm/./detail/type_mat2x2.hpp
intersection.o: glm/./detail/type_vec2.hpp glm/./detail/type_mat2x2.inl
intersection.o: glm/./matrix.hpp glm/./mat2x3.hpp
intersection.o: glm/././ext/matrix_double2x3.hpp
intersection.o: glm/././detail/type_mat2x3.hpp glm/././detail/type_vec3.hpp
intersection.o: glm/././detail/type_mat2x3.inl
intersection.o: glm/././ext/matrix_double2x3_precision.hpp
intersection.o: glm/././ext/matrix_float2x3.hpp
intersection.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
intersection.o: glm/././ext/matrix_double2x4.hpp
intersection.o: glm/././detail/type_mat2x4.hpp glm/././detail/type_vec4.hpp
intersection.o: glm/././detail/type_mat2x4.inl
intersection.o: glm/././ext/matrix_double2x4_precision.hpp
intersection.o: glm/././ext/matrix_float2x4.hpp
intersection.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
intersection.o: glm/././ext/matrix_double3x2.hpp
intersection.o: glm/././detail/type_mat3x2.hpp glm/././detail/type_mat3x2.inl
intersection.o: glm/././ext/matrix_double3x2_precision.hpp
intersection.o: glm/././ext/matrix_float3x2.hpp
intersection.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
intersection.o: glm/././ext/matrix_double3x3.hpp
intersection.o: glm/././detail/type_mat3x3.hpp glm/././detail/type_mat3x3.inl
intersection.o: glm/././ext/matrix_double3x3_precision.hpp
intersection.o: glm/././ext/matrix_float3x3.hpp
intersection.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
intersection.o: glm/././ext/matrix_double3x4.hpp
intersection.o: glm/././detail/type_mat3x4.hpp glm/././detail/type_mat3x4.inl
intersection.o: glm/././ext/matrix_double3x4_precision.hpp
intersection.o: glm/././ext/matrix_float3x4.hpp
intersection.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
intersection.o: glm/././ext/matrix_double4x2.hpp
intersection.o: glm/././detail/type_mat4x2.hpp glm/././detail/type_mat4x2.inl
intersection.o: glm/././ext/matrix_double4x2_precision.hpp
intersection.o: glm/././ext/matrix_float4x2.hpp
intersection.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
intersection.o: glm/././ext/matrix_double4x3.hpp
intersection.o: glm/././detail/type_mat4x3.hpp glm/././detail/type_mat4x3.inl
intersection.o: glm/././ext/matrix_double4x3_precision.hpp
intersection.o: glm/././ext/matrix_float4x3.hpp
intersection.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
intersection.o: glm/././ext/matrix_double4x4.hpp
intersection.o: glm/././detail/type_mat4x4.hpp glm/././detail/type_mat4x4.inl
intersection.o: glm/././ext/matrix_double4x4_precision.hpp
intersection.o: glm/././ext/matrix_float4x4.hpp
intersection.o: glm/././ext/matrix_float4x4_precision.hpp
intersection.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
intersection.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
intersection.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
intersection.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
intersection.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
intersection.o: glm/./vector_relational.hpp
intersection.o: glm/./detail/func_vector_relational.inl
intersection.o: glm/./detail/_vectorize.hpp glm/./common.hpp
intersection.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
intersection.o: glm/./ext/matrix_double2x2_precision.hpp
intersection.o: glm/./ext/matrix_float2x2.hpp
intersection.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
intersection.o: glm/detail/func_trigonometric.inl glm/exponential.hpp
intersection.o: glm/common.hpp glm/packing.hpp glm/detail/func_packing.inl
intersection.o: glm/detail/type_half.hpp glm/detail/type_half.inl
intersection.o: glm/geometric.hpp glm/matrix.hpp glm/vector_relational.hpp
intersection.o: glm/integer.hpp glm/detail/func_integer.inl
scene.o: scene.h
image.o: image.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
image.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
image.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
image.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
image.o: glm/./detail/type_vec2.inl
image.o: glm/./detail/./compute_vector_relational.hpp
image.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
image.o: glm/./ext/vector_float2_precision.hpp glm/./ext/vector_double2.hpp
image.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
image.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
image.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
image.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
image.o: glm/./detail/type_vec3.inl
image.o: glm/./detail/compute_vector_relational.hpp
image.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
image.o: glm/./ext/vector_float3_precision.hpp glm/./ext/vector_double3.hpp
image.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
image.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
image.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
image.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
image.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
image.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
image.o: glm/./ext/vector_double4.hpp glm/./ext/vector_double4_precision.hpp
image.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
image.o: glm/./ext/vector_uint4.hpp glm/./ext/vector_uint4_precision.hpp
image.o: glm/mat2x2.hpp glm/./ext/matrix_double2x2.hpp
image.o: glm/./detail/type_mat2x2.hpp glm/./detail/type_vec2.hpp
image.o: glm/./detail/type_mat2x2.inl glm/./matrix.hpp glm/./mat2x3.hpp
image.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
image.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
image.o: glm/././ext/matrix_double2x3_precision.hpp
image.o: glm/././ext/matrix_float2x3.hpp
image.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
image.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
image.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
image.o: glm/././ext/matrix_double2x4_precision.hpp
image.o: glm/././ext/matrix_float2x4.hpp
image.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
image.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
image.o: glm/././detail/type_mat3x2.inl
image.o: glm/././ext/matrix_double3x2_precision.hpp
image.o: glm/././ext/matrix_float3x2.hpp
image.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
image.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
image.o: glm/././detail/type_mat3x3.inl
image.o: glm/././ext/matrix_double3x3_precision.hpp
image.o: glm/././ext/matrix_float3x3.hpp
image.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
image.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
image.o: glm/././detail/type_mat3x4.inl
image.o: glm/././ext/matrix_double3x4_precision.hpp
image.o: glm/././ext/matrix_float3x4.hpp
image.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
image.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
image.o: glm/././detail/type_mat4x2.inl
image.o: glm/././ext/matrix_double4x2_precision.hpp
image.o: glm/././ext/matrix_float4x2.hpp
image.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
image.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
image.o: glm/././detail/type_mat4x3.inl
image.o: glm/././ext/matrix_double4x3_precision.hpp
image.o: glm/././ext/matrix_float4x3.hpp
image.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
image.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
image.o: glm/././detail/type_mat4x4.inl
image.o: glm/././ext/matrix_double4x4_precision.hpp
image.o: glm/././ext/matrix_float4x4.hpp
image.o: glm/././ext/matrix_float4x4_precision.hpp
image.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
image.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
image.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
image.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
image.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
image.o: glm/./vector_relational.hpp glm/./detail/func_vector_relational.inl
image.o: glm/./detail/_vectorize.hpp glm/./common.hpp
image.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
image.o: glm/./ext/matrix_double2x2_precision.hpp
image.o: glm/./ext/matrix_float2x2.hpp
image.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
image.o: glm/detail/func_trigonometric.inl glm/exponential.hpp glm/common.hpp
image.o: glm/packing.hpp glm/detail/func_packing.inl glm/detail/type_half.hpp
image.o: glm/detail/type_half.inl glm/geometric.hpp glm/matrix.hpp
image.o: glm/vector_relational.hpp glm/integer.hpp
image.o: glm/detail/func_integer.inl png/lodepng.h
light.o: light.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
light.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
light.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
light.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
light.o: glm/./detail/type_vec2.inl
light.o: glm/./detail/./compute_vector_relational.hpp
light.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
light.o: glm/./ext/vector_float2_precision.hpp glm/./ext/vector_double2.hpp
light.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
light.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
light.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
light.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
light.o: glm/./detail/type_vec3.inl
light.o: glm/./detail/compute_vector_relational.hpp
light.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
light.o: glm/./ext/vector_float3_precision.hpp glm/./ext/vector_double3.hpp
light.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
light.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
light.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
light.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
light.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
light.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
light.o: glm/./ext/vector_double4.hpp glm/./ext/vector_double4_precision.hpp
light.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
light.o: glm/./ext/vector_uint4.hpp glm/./ext/vector_uint4_precision.hpp
light.o: glm/mat2x2.hpp glm/./ext/matrix_double2x2.hpp
light.o: glm/./detail/type_mat2x2.hpp glm/./detail/type_vec2.hpp
light.o: glm/./detail/type_mat2x2.inl glm/./matrix.hpp glm/./mat2x3.hpp
light.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
light.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
light.o: glm/././ext/matrix_double2x3_precision.hpp
light.o: glm/././ext/matrix_float2x3.hpp
light.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
light.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
light.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
light.o: glm/././ext/matrix_double2x4_precision.hpp
light.o: glm/././ext/matrix_float2x4.hpp
light.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
light.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
light.o: glm/././detail/type_mat3x2.inl
light.o: glm/././ext/matrix_double3x2_precision.hpp
light.o: glm/././ext/matrix_float3x2.hpp
light.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
light.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
light.o: glm/././detail/type_mat3x3.inl
light.o: glm/././ext/matrix_double3x3_precision.hpp
light.o: glm/././ext/matrix_float3x3.hpp
light.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
light.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
light.o: glm/././detail/type_mat3x4.inl
light.o: glm/././ext/matrix_double3x4_precision.hpp
light.o: glm/././ext/matrix_float3x4.hpp
light.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
light.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
light.o: glm/././detail/type_mat4x2.inl
light.o: glm/././ext/matrix_double4x2_precision.hpp
light.o: glm/././ext/matrix_float4x2.hpp
light.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
light.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
light.o: glm/././detail/type_mat4x3.inl
light.o: glm/././ext/matrix_double4x3_precision.hpp
light.o: glm/././ext/matrix_float4x3.hpp
light.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
light.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
light.o: glm/././detail/type_mat4x4.inl
light.o: glm/././ext/matrix_double4x4_precision.hpp
light.o: glm/././ext/matrix_float4x4.hpp
light.o: glm/././ext/matrix_float4x4_precision.hpp
light.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
light.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
light.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
light.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
light.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
light.o: glm/./vector_relational.hpp glm/./detail/func_vector_relational.inl
light.o: glm/./detail/_vectorize.hpp glm/./common.hpp
light.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
light.o: glm/./ext/matrix_double2x2_precision.hpp
light.o: glm/./ext/matrix_float2x2.hpp
light.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
light.o: glm/detail/func_trigonometric.inl glm/exponential.hpp glm/common.hpp
light.o: glm/packing.hpp glm/detail/func_packing.inl glm/detail/type_half.hpp
light.o: glm/detail/type_half.inl glm/geometric.hpp glm/matrix.hpp
light.o: glm/vector_relational.hpp glm/integer.hpp
light.o: glm/detail/func_integer.inl
rayon.o: rayon.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
rayon.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
rayon.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
rayon.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
rayon.o: glm/./detail/type_vec2.inl
rayon.o: glm/./detail/./compute_vector_relational.hpp
rayon.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
rayon.o: glm/./ext/vector_float2_precision.hpp glm/./ext/vector_double2.hpp
rayon.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
rayon.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
rayon.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
rayon.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
rayon.o: glm/./detail/type_vec3.inl
rayon.o: glm/./detail/compute_vector_relational.hpp
rayon.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
rayon.o: glm/./ext/vector_float3_precision.hpp glm/./ext/vector_double3.hpp
rayon.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
rayon.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
rayon.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
rayon.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
rayon.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
rayon.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
rayon.o: glm/./ext/vector_double4.hpp glm/./ext/vector_double4_precision.hpp
rayon.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
rayon.o: glm/./ext/vector_uint4.hpp glm/./ext/vector_uint4_precision.hpp
rayon.o: glm/mat2x2.hpp glm/./ext/matrix_double2x2.hpp
rayon.o: glm/./detail/type_mat2x2.hpp glm/./detail/type_vec2.hpp
rayon.o: glm/./detail/type_mat2x2.inl glm/./matrix.hpp glm/./mat2x3.hpp
rayon.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
rayon.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
rayon.o: glm/././ext/matrix_double2x3_precision.hpp
rayon.o: glm/././ext/matrix_float2x3.hpp
rayon.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
rayon.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
rayon.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
rayon.o: glm/././ext/matrix_double2x4_precision.hpp
rayon.o: glm/././ext/matrix_float2x4.hpp
rayon.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
rayon.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
rayon.o: glm/././detail/type_mat3x2.inl
rayon.o: glm/././ext/matrix_double3x2_precision.hpp
rayon.o: glm/././ext/matrix_float3x2.hpp
rayon.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
rayon.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
rayon.o: glm/././detail/type_mat3x3.inl
rayon.o: glm/././ext/matrix_double3x3_precision.hpp
rayon.o: glm/././ext/matrix_float3x3.hpp
rayon.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
rayon.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
rayon.o: glm/././detail/type_mat3x4.inl
rayon.o: glm/././ext/matrix_double3x4_precision.hpp
rayon.o: glm/././ext/matrix_float3x4.hpp
rayon.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
rayon.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
rayon.o: glm/././detail/type_mat4x2.inl
rayon.o: glm/././ext/matrix_double4x2_precision.hpp
rayon.o: glm/././ext/matrix_float4x2.hpp
rayon.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
rayon.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
rayon.o: glm/././detail/type_mat4x3.inl
rayon.o: glm/././ext/matrix_double4x3_precision.hpp
rayon.o: glm/././ext/matrix_float4x3.hpp
rayon.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
rayon.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
rayon.o: glm/././detail/type_mat4x4.inl
rayon.o: glm/././ext/matrix_double4x4_precision.hpp
rayon.o: glm/././ext/matrix_float4x4.hpp
rayon.o: glm/././ext/matrix_float4x4_precision.hpp
rayon.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
rayon.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
rayon.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
rayon.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
rayon.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
rayon.o: glm/./vector_relational.hpp glm/./detail/func_vector_relational.inl
rayon.o: glm/./detail/_vectorize.hpp glm/./common.hpp
rayon.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
rayon.o: glm/./ext/matrix_double2x2_precision.hpp
rayon.o: glm/./ext/matrix_float2x2.hpp
rayon.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
rayon.o: glm/detail/func_trigonometric.inl glm/exponential.hpp glm/common.hpp
rayon.o: glm/packing.hpp glm/detail/func_packing.inl glm/detail/type_half.hpp
rayon.o: glm/detail/type_half.inl glm/geometric.hpp glm/matrix.hpp
rayon.o: glm/vector_relational.hpp glm/integer.hpp
rayon.o: glm/detail/func_integer.inl scene.h intersection.h objet.h
rayon.o: material.h
camera.o: camera.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
camera.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
camera.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
camera.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
camera.o: glm/./detail/type_vec2.inl
camera.o: glm/./detail/./compute_vector_relational.hpp
camera.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
camera.o: glm/./ext/vector_float2_precision.hpp glm/./ext/vector_double2.hpp
camera.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
camera.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
camera.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
camera.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
camera.o: glm/./detail/type_vec3.inl
camera.o: glm/./detail/compute_vector_relational.hpp
camera.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
camera.o: glm/./ext/vector_float3_precision.hpp glm/./ext/vector_double3.hpp
camera.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
camera.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
camera.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
camera.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
camera.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
camera.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
camera.o: glm/./ext/vector_double4.hpp glm/./ext/vector_double4_precision.hpp
camera.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
camera.o: glm/./ext/vector_uint4.hpp glm/./ext/vector_uint4_precision.hpp
camera.o: glm/mat2x2.hpp glm/./ext/matrix_double2x2.hpp
camera.o: glm/./detail/type_mat2x2.hpp glm/./detail/type_vec2.hpp
camera.o: glm/./detail/type_mat2x2.inl glm/./matrix.hpp glm/./mat2x3.hpp
camera.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
camera.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
camera.o: glm/././ext/matrix_double2x3_precision.hpp
camera.o: glm/././ext/matrix_float2x3.hpp
camera.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
camera.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
camera.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
camera.o: glm/././ext/matrix_double2x4_precision.hpp
camera.o: glm/././ext/matrix_float2x4.hpp
camera.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
camera.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
camera.o: glm/././detail/type_mat3x2.inl
camera.o: glm/././ext/matrix_double3x2_precision.hpp
camera.o: glm/././ext/matrix_float3x2.hpp
camera.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
camera.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
camera.o: glm/././detail/type_mat3x3.inl
camera.o: glm/././ext/matrix_double3x3_precision.hpp
camera.o: glm/././ext/matrix_float3x3.hpp
camera.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
camera.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
camera.o: glm/././detail/type_mat3x4.inl
camera.o: glm/././ext/matrix_double3x4_precision.hpp
camera.o: glm/././ext/matrix_float3x4.hpp
camera.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
camera.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
camera.o: glm/././detail/type_mat4x2.inl
camera.o: glm/././ext/matrix_double4x2_precision.hpp
camera.o: glm/././ext/matrix_float4x2.hpp
camera.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
camera.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
camera.o: glm/././detail/type_mat4x3.inl
camera.o: glm/././ext/matrix_double4x3_precision.hpp
camera.o: glm/././ext/matrix_float4x3.hpp
camera.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
camera.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
camera.o: glm/././detail/type_mat4x4.inl
camera.o: glm/././ext/matrix_double4x4_precision.hpp
camera.o: glm/././ext/matrix_float4x4.hpp
camera.o: glm/././ext/matrix_float4x4_precision.hpp
camera.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
camera.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
camera.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
camera.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
camera.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
camera.o: glm/./vector_relational.hpp glm/./detail/func_vector_relational.inl
camera.o: glm/./detail/_vectorize.hpp glm/./common.hpp
camera.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
camera.o: glm/./ext/matrix_double2x2_precision.hpp
camera.o: glm/./ext/matrix_float2x2.hpp
camera.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
camera.o: glm/detail/func_trigonometric.inl glm/exponential.hpp
camera.o: glm/common.hpp glm/packing.hpp glm/detail/func_packing.inl
camera.o: glm/detail/type_half.hpp glm/detail/type_half.inl glm/geometric.hpp
camera.o: glm/matrix.hpp glm/vector_relational.hpp glm/integer.hpp
camera.o: glm/detail/func_integer.inl scene.h rayon.h intersection.h image.h
main.o: image.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
main.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
main.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
main.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
main.o: glm/./detail/type_vec2.inl
main.o: glm/./detail/./compute_vector_relational.hpp
main.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
main.o: glm/./ext/vector_float2_precision.hpp glm/./ext/vector_double2.hpp
main.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
main.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
main.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
main.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp glm/./detail/type_vec3.hpp
main.o: glm/./detail/type_vec3.inl glm/./detail/compute_vector_relational.hpp
main.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
main.o: glm/./ext/vector_float3_precision.hpp glm/./ext/vector_double3.hpp
main.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
main.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
main.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
main.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
main.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
main.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
main.o: glm/./ext/vector_double4.hpp glm/./ext/vector_double4_precision.hpp
main.o: glm/./ext/vector_int4.hpp glm/./ext/vector_int4_precision.hpp
main.o: glm/./ext/vector_uint4.hpp glm/./ext/vector_uint4_precision.hpp
main.o: glm/mat2x2.hpp glm/./ext/matrix_double2x2.hpp
main.o: glm/./detail/type_mat2x2.hpp glm/./detail/type_vec2.hpp
main.o: glm/./detail/type_mat2x2.inl glm/./matrix.hpp glm/./mat2x3.hpp
main.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
main.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
main.o: glm/././ext/matrix_double2x3_precision.hpp
main.o: glm/././ext/matrix_float2x3.hpp
main.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
main.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
main.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
main.o: glm/././ext/matrix_double2x4_precision.hpp
main.o: glm/././ext/matrix_float2x4.hpp
main.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
main.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
main.o: glm/././detail/type_mat3x2.inl
main.o: glm/././ext/matrix_double3x2_precision.hpp
main.o: glm/././ext/matrix_float3x2.hpp
main.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
main.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
main.o: glm/././detail/type_mat3x3.inl
main.o: glm/././ext/matrix_double3x3_precision.hpp
main.o: glm/././ext/matrix_float3x3.hpp
main.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
main.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
main.o: glm/././detail/type_mat3x4.inl
main.o: glm/././ext/matrix_double3x4_precision.hpp
main.o: glm/././ext/matrix_float3x4.hpp
main.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
main.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
main.o: glm/././detail/type_mat4x2.inl
main.o: glm/././ext/matrix_double4x2_precision.hpp
main.o: glm/././ext/matrix_float4x2.hpp
main.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
main.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
main.o: glm/././detail/type_mat4x3.inl
main.o: glm/././ext/matrix_double4x3_precision.hpp
main.o: glm/././ext/matrix_float4x3.hpp
main.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
main.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
main.o: glm/././detail/type_mat4x4.inl
main.o: glm/././ext/matrix_double4x4_precision.hpp
main.o: glm/././ext/matrix_float4x4.hpp
main.o: glm/././ext/matrix_float4x4_precision.hpp
main.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
main.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
main.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
main.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
main.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
main.o: glm/./vector_relational.hpp glm/./detail/func_vector_relational.inl
main.o: glm/./detail/_vectorize.hpp glm/./common.hpp
main.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
main.o: glm/./ext/matrix_double2x2_precision.hpp
main.o: glm/./ext/matrix_float2x2.hpp glm/./ext/matrix_float2x2_precision.hpp
main.o: glm/trigonometric.hpp glm/detail/func_trigonometric.inl
main.o: glm/exponential.hpp glm/common.hpp glm/packing.hpp
main.o: glm/detail/func_packing.inl glm/detail/type_half.hpp
main.o: glm/detail/type_half.inl glm/geometric.hpp glm/matrix.hpp
main.o: glm/vector_relational.hpp glm/integer.hpp glm/detail/func_integer.inl
main.o: camera.h scene.h rayon.h intersection.h objet.h material.h light.h
material.o: material.h glm/glm.hpp glm/detail/_fixes.hpp glm/detail/setup.hpp
material.o: glm/simd/platform.h glm/fwd.hpp glm/detail/qualifier.hpp
material.o: glm/detail/setup.hpp glm/vec2.hpp glm/./ext/vector_bool2.hpp
material.o: glm/./detail/type_vec2.hpp glm/./detail/qualifier.hpp
material.o: glm/./detail/type_vec2.inl
material.o: glm/./detail/./compute_vector_relational.hpp
material.o: glm/./ext/vector_bool2_precision.hpp glm/./ext/vector_float2.hpp
material.o: glm/./ext/vector_float2_precision.hpp
material.o: glm/./ext/vector_double2.hpp
material.o: glm/./ext/vector_double2_precision.hpp glm/./ext/vector_int2.hpp
material.o: glm/./ext/vector_int2_precision.hpp glm/./detail/setup.hpp
material.o: glm/./ext/vector_uint2.hpp glm/./ext/vector_uint2_precision.hpp
material.o: glm/vec3.hpp glm/./ext/vector_bool3.hpp
material.o: glm/./detail/type_vec3.hpp glm/./detail/type_vec3.inl
material.o: glm/./detail/compute_vector_relational.hpp
material.o: glm/./ext/vector_bool3_precision.hpp glm/./ext/vector_float3.hpp
material.o: glm/./ext/vector_float3_precision.hpp
material.o: glm/./ext/vector_double3.hpp
material.o: glm/./ext/vector_double3_precision.hpp glm/./ext/vector_int3.hpp
material.o: glm/./ext/vector_int3_precision.hpp glm/./ext/vector_uint3.hpp
material.o: glm/./ext/vector_uint3_precision.hpp glm/vec4.hpp
material.o: glm/./ext/vector_bool4.hpp glm/./detail/type_vec4.hpp
material.o: glm/./detail/type_vec4.inl glm/./ext/vector_bool4_precision.hpp
material.o: glm/./ext/vector_float4.hpp glm/./ext/vector_float4_precision.hpp
material.o: glm/./ext/vector_double4.hpp
material.o: glm/./ext/vector_double4_precision.hpp glm/./ext/vector_int4.hpp
material.o: glm/./ext/vector_int4_precision.hpp glm/./ext/vector_uint4.hpp
material.o: glm/./ext/vector_uint4_precision.hpp glm/mat2x2.hpp
material.o: glm/./ext/matrix_double2x2.hpp glm/./detail/type_mat2x2.hpp
material.o: glm/./detail/type_vec2.hpp glm/./detail/type_mat2x2.inl
material.o: glm/./matrix.hpp glm/./mat2x3.hpp
material.o: glm/././ext/matrix_double2x3.hpp glm/././detail/type_mat2x3.hpp
material.o: glm/././detail/type_vec3.hpp glm/././detail/type_mat2x3.inl
material.o: glm/././ext/matrix_double2x3_precision.hpp
material.o: glm/././ext/matrix_float2x3.hpp
material.o: glm/././ext/matrix_float2x3_precision.hpp glm/./mat2x4.hpp
material.o: glm/././ext/matrix_double2x4.hpp glm/././detail/type_mat2x4.hpp
material.o: glm/././detail/type_vec4.hpp glm/././detail/type_mat2x4.inl
material.o: glm/././ext/matrix_double2x4_precision.hpp
material.o: glm/././ext/matrix_float2x4.hpp
material.o: glm/././ext/matrix_float2x4_precision.hpp glm/./mat3x2.hpp
material.o: glm/././ext/matrix_double3x2.hpp glm/././detail/type_mat3x2.hpp
material.o: glm/././detail/type_mat3x2.inl
material.o: glm/././ext/matrix_double3x2_precision.hpp
material.o: glm/././ext/matrix_float3x2.hpp
material.o: glm/././ext/matrix_float3x2_precision.hpp glm/./mat3x3.hpp
material.o: glm/././ext/matrix_double3x3.hpp glm/././detail/type_mat3x3.hpp
material.o: glm/././detail/type_mat3x3.inl
material.o: glm/././ext/matrix_double3x3_precision.hpp
material.o: glm/././ext/matrix_float3x3.hpp
material.o: glm/././ext/matrix_float3x3_precision.hpp glm/./mat3x4.hpp
material.o: glm/././ext/matrix_double3x4.hpp glm/././detail/type_mat3x4.hpp
material.o: glm/././detail/type_mat3x4.inl
material.o: glm/././ext/matrix_double3x4_precision.hpp
material.o: glm/././ext/matrix_float3x4.hpp
material.o: glm/././ext/matrix_float3x4_precision.hpp glm/./mat4x2.hpp
material.o: glm/././ext/matrix_double4x2.hpp glm/././detail/type_mat4x2.hpp
material.o: glm/././detail/type_mat4x2.inl
material.o: glm/././ext/matrix_double4x2_precision.hpp
material.o: glm/././ext/matrix_float4x2.hpp
material.o: glm/././ext/matrix_float4x2_precision.hpp glm/./mat4x3.hpp
material.o: glm/././ext/matrix_double4x3.hpp glm/././detail/type_mat4x3.hpp
material.o: glm/././detail/type_mat4x3.inl
material.o: glm/././ext/matrix_double4x3_precision.hpp
material.o: glm/././ext/matrix_float4x3.hpp
material.o: glm/././ext/matrix_float4x3_precision.hpp glm/./mat4x4.hpp
material.o: glm/././ext/matrix_double4x4.hpp glm/././detail/type_mat4x4.hpp
material.o: glm/././detail/type_mat4x4.inl
material.o: glm/././ext/matrix_double4x4_precision.hpp
material.o: glm/././ext/matrix_float4x4.hpp
material.o: glm/././ext/matrix_float4x4_precision.hpp
material.o: glm/./detail/func_matrix.inl glm/./geometric.hpp
material.o: glm/./detail/type_vec3.hpp glm/./detail/func_geometric.inl
material.o: glm/./exponential.hpp glm/./detail/type_vec1.hpp
material.o: glm/./detail/type_vec1.inl glm/./detail/type_vec2.hpp
material.o: glm/./detail/type_vec4.hpp glm/./detail/func_exponential.inl
material.o: glm/./vector_relational.hpp
material.o: glm/./detail/func_vector_relational.inl
material.o: glm/./detail/_vectorize.hpp glm/./common.hpp
material.o: glm/./detail/func_common.inl glm/./detail/compute_common.hpp
material.o: glm/./ext/matrix_double2x2_precision.hpp
material.o: glm/./ext/matrix_float2x2.hpp
material.o: glm/./ext/matrix_float2x2_precision.hpp glm/trigonometric.hpp
material.o: glm/detail/func_trigonometric.inl glm/exponential.hpp
material.o: glm/common.hpp glm/packing.hpp glm/detail/func_packing.inl
material.o: glm/detail/type_half.hpp glm/detail/type_half.inl
material.o: glm/geometric.hpp glm/matrix.hpp glm/vector_relational.hpp
material.o: glm/integer.hpp glm/detail/func_integer.inl intersection.h
