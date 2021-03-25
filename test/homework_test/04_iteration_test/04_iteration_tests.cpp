#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dna.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Verify get_gc_content", "check for all g's and c's and then find the GC-content") {
	REQUIRE(get_gc_content("AGCTATAG") == .375);
	REQUIRE(get_gc_content("CGCTATAG") == .50);
}
TEST_CASE("Verify get_reverse_string", "Reverse the string") {
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
}
TEST_CASE("Verify get_dna_complement", "Reverse the string then swap all a's and t's and also swap all g's and c's") {
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
}
