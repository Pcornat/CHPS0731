//#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <fstream>
#include "DeSerializer/deserializer.h"
#include "Camera/scene.h"

TEST_CASE("Deserializer : fillFields working.", "[deserializer]") {
	std::ifstream file("test.json");
	json j = json::parse(file);
	Scene sc;
	CHECK_NOTHROW(j.at("Scene").get_to(sc));
}