#include "ostream"
#include "catch_with_main.hpp"
#include "vector.hpp"

TEST_CASE( "make a vector posetive" ){
   vector v( 3, 10 );
   v = +v; 
   REQUIRE( v == vector( 3, 10 ) );     
}
TEST_CASE( "add vector with another vector" ){
   vector v( 3, 10 );
   vector v2( 3, 10 );
   vector x = v + v2; 
   REQUIRE( x == vector( 6, 20 ) );     
}
TEST_CASE( "add vector with a vector" ){
   vector v( 3, 10 );
   vector v2( 3, 10 );
   v += v2; 
   REQUIRE( v == vector( 6, 20 ) );     
}
TEST_CASE( "make a vector negative" ){
   vector v( 3, 10 );
   v = -v; 
   REQUIRE( v == vector( -3, -10 ) );     
}
TEST_CASE( "takes vector from a vector" ){
   vector v( 3, 10 );
   vector v2( 3, 10 );
   v -= v2; 
   REQUIRE( v == vector( 0, 0 ) );     
}
TEST_CASE( "takes vector from another vector" ){
   vector v( 3, 10 );
   vector v2( 3, 10 );
   vector x = v - v2; 
   REQUIRE( x == vector( 0, 0 ) );     
}
TEST_CASE( "multiplies vector and another number" ){
   vector v( 3, 10 );
   vector x = v * 2; 
   REQUIRE( x == vector( 6, 20 ) );     
}
TEST_CASE( "multiplies vector and a number" ){
   vector v( 3, 10 );
   v *= 2; 
   REQUIRE( v == vector( 6, 20 ) );     
}
TEST_CASE( "multiplies number and a vector" ){
   vector v( 3, 10 );
   vector x = 2 * v; 
   REQUIRE( x == vector( 6, 20 ) );     
}
TEST_CASE( "divides a vector with another number" ){
   vector v( 4, 10 );
   vector x = v /2; 
   REQUIRE( x == vector( 2, 5 ) );     
}
TEST_CASE( "divides a vector with a number" ){
   vector v( 4, 10 );
   v /= 2; 
   REQUIRE( v == vector( 2, 5 ) );     
}
TEST_CASE( "constructor, two_parameters" ){
   vector v( 3, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(3,4)" );   
}
