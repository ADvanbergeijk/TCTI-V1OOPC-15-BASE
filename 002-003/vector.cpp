#include "vector.hpp"

/// compare 2 vectors
//
/// This operator tests if 2 vectors are exctly the same
/// and returns true if they are.
bool vector::operator == (const vector & rhs) const{
    return bool(( x == rhs.x ) && ( y == rhs.y));
}
/// an unchanged vector
//
/// This operator changes nothing to a vector.
vector vector::operator+()const{
    return vector(x,y);
}
/// add 2 vectors
//
/// This operator adds 2 vectors and returns the outcome.
vector vector::operator+(const vector & rhs) const{
    return vector( x+rhs.x,y+rhs.y);
}

/// flip vulues of vector
//
/// This operator makes the values of a vector negative when they
/// are positive and makes them positive when they are negative.
vector vector::operator-()const{
    return vector(x*-1,y*-1);
}

/// substract 2 vectors
//
/// This operator substracts 2 vectors and returns the outcome.
vector vector::operator-(const vector & rhs) const{
    return vector( x-rhs.x,y-rhs.y);
}

/// multiply a vector with an integer
//
/// This operator multiplies a vector with an integer and returns the outcome
vector vector::operator*(const int & rhs){
    x=x*rhs;
    y=y*rhs;
    return*this;
}

/// add a vector to a vector
//
/// This operator adds a vector to another vector.
vector vector::operator+=(const vector & rhs) {
    x=x+rhs.x;
    y=y+rhs.y;
    return*this;
}

/// substract a vector to a vector
//
/// This operator substracts a vector from another vector.
vector vector::operator-=(const vector & rhs) {
    x=x-rhs.x;
    y=y-rhs.y;
    return*this;
}

/// multiply a vector with an integer
//
/// This operator multiplies a vector with an integer.
vector &vector::operator*=(const int  rhs) {
    x=x*rhs;
    y=y*rhs;
    return*this;
}

/// divide a vector with an integer
//
/// This operator divides a vector with an integer.
vector &vector::operator/=(const int  rhs) {
    x=x/rhs;
    y=y/rhs;
    return*this;
}

/// divide a vector with an integer
//
/// This operator divides a vector with an integer and returns the outcome.
vector vector::operator/(const int & rhs){
    x=x/rhs;
    y=y/rhs;
    return*this;
}

/// output operator for a vector
//
/// This operator<< prints a constructor in the format
/// (x,y) where both values are printed as
/// decimal values.
std::ostream & operator<<( std::ostream & lhs, vector pos ){
   lhs <<"(" << pos.x << "," << pos.y << ")";
   return lhs;
}

/// multiply an integer whith a vector
//
/// This operator multiplies an integer with a vector and returns the outcome
vector operator*(const int lhs, const vector &rhs){
    return vector(rhs.x*lhs,rhs.y*lhs);
}