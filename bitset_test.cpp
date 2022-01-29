#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction valid", "[bitset]" ) {

    Bitset b(10);  
    REQUIRE(b.size() == 10);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction invalid", "[bitset]" ) {

    Bitset b(-1);
    REQUIRE(b.size() == -1);
    REQUIRE(!(b.good()));
}

TEST_CASE( "Test bitset construction string valid", "[bitset]" ) {
    std::string s = "1100";
    Bitset b(s);
    REQUIRE(b.good());
    for(int i=0;i<s.size();i++){
        REQUIRE(b.test(i) == s[s.size()-1-i]-'0');
    }
}

TEST_CASE( "Test bitset construction string invalid", "[bitset]" ) {
    std::string s = "1120";
    Bitset b(s);
    REQUIRE(!(b.good()));
}

TEST_CASE( "Size", "[bitset]" ) {
    Bitset b(15);  
    REQUIRE(b.size() == 15);
}

TEST_CASE( "Size", "[bitset]" ) {
    Bitset b(15);  
    REQUIRE(b.size() == 15);
}

TEST_CASE( "Good Test", "[bitset]" ) {
    Bitset b(15);  
    REQUIRE(b.good());
    b.test(-1);
    REQUIRE(!(b.good()));
}

TEST_CASE( "Setter Tests", "[bitset]" ) {
    Bitset b(15);  
    REQUIRE(b.good());
    b.test(-1);
    REQUIRE(!(b.good()));
}


