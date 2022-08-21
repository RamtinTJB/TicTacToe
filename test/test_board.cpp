#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../src/board.h"
#include <doctest.h>

SCENARIO("Check if the index is between 0 and 8") {
	GIVEN("Integers") {
		WHEN("The index is valid") {
			THEN("The function returns true") {
				CHECK(is_index_valid(6) == true);
				CHECK(is_index_valid(0) == true);
				CHECK(is_index_valid(8) == true);
			}
		}
		WHEN("The index is invalid") {
			THEN("The function returns false") {
				CHECK(is_index_valid(-1) == false);
				CHECK(is_index_valid(9) == false);
			}
		}
	}
}
