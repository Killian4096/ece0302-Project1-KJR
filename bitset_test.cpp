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


TEST_CASE( "Good Test", "[bitset]" ) {
    Bitset b(15);  
    REQUIRE(b.good());
    b.test(-1);
    REQUIRE(!(b.good()));
}

TEST_CASE( "Set Tests", "[bitset]" ) {
    Bitset b("000");
    REQUIRE(b.good());
    b.set(0);
    REQUIRE(b.test(0));
}

TEST_CASE( "Reset Tests", "[bitset]" ) {
    Bitset b("111");
    REQUIRE(b.good());
    b.reset(0);
    REQUIRE(!(b.test(0)));
}

TEST_CASE( "Toggle Tests", "[bitset]" ) {
    Bitset b("010");
    REQUIRE(b.good());
    b.toggle(0);
    b.toggle(1);
    REQUIRE(b.test(0));
    REQUIRE(!(b.test(1)));
}

TEST_CASE( "Test Tests", "[bitset]" ) {
    Bitset b("10");
    REQUIRE(b.good());
    REQUIRE(b.test(1));
    REQUIRE(!(b.test(0)));
}



TEST_CASE( "Invalid Tests", "[bitset]" ) {
    Bitset a("000");
    Bitset b("000");
    Bitset c("000");
    Bitset d("000");
    a.set(-1);
    b.reset(-1);
    c.toggle(-1);
    REQUIRE(!(d.test(-1)));
    REQUIRE(!(a.good()));
    REQUIRE(!(b.good()));
    REQUIRE(!(c.good()));
    REQUIRE(!(d.good()));
}

TEST_CASE( "AsString", "[bitset]" ) {
    std::string s = "011011";
    Bitset b(s);
    std::string t = b.asString();
    REQUIRE(s.compare(t)==0);
}