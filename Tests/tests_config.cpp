//
// Created by Florent on 25/01/2019.
//

#include <catch/catch.hpp>
#include <Configuration/configuration.h>
#include <fstream>


TEST_CASE("Configuration : check file extension", "[configuration][file extension]") {
	REQUIRE_THROWS(Configuration("coucou.son"));
	REQUIRE_THROWS(Configuration("coucou"));
	REQUIRE_NOTHROW(Configuration("coucou.json"));
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