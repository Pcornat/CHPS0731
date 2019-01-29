//
// Created by Florent on 25/01/2019.
//

#include <catch/catch.hpp>
#include <Configuration/configuration.h>
#include <fstream>


TEST_CASE("Configuration : check constructor", "[configuration][constructor]") {
	REQUIRE_THROWS_WITH(Configuration("coucou.son"), "No file extension found or wrong extension.");
	REQUIRE_THROWS_WITH(Configuration("coucou"), "No file extension found or wrong extension.");
	REQUIRE_THROWS_WITH(Configuration("coucou.json"), "File does not exist.");
	REQUIRE_NOTHROW(Configuration("test.json"));
}

TEST_CASE("Configuration : writing with ofstream and operator<<", "[configuration][operator<<]") {
	bool throwing = false;

	try {
		std::ofstream ofs("test.json");
		Configuration conf("test.json");
		//TODO : continuer configuration.

	} catch (const std::exception& e) {

	}

}