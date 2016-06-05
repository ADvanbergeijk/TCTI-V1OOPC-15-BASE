#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "ostream"
/// vector ADT
//
/// This is an ADT that implements vectors.
/// The x and y are stored as two (signed) integers.
/// The appropriate constructors and operators are provided.
class vector {
public:
   int x;
   int y; 
   
   /// constructor from explicit values
   //
   /// This constructor initializes a vector from its x and y.
   vector( int x, int y ): 
      x( x ), y( y )
   {}
   
   vector(){}
bool operator == (const vector & rhs) const;
vector operator+() const ; 
vector operator+(const vector &rhs) const;

vector operator-()const;
vector operator-(const vector & rhs) const;

vector operator*(const int & rhs);

vector operator+=(const vector & rhs) ;
vector operator-=(const vector & rhs) ;
vector operator/(const int & rhs) ;

vector &operator*=(const int  rhs) ;
vector &operator/=(const int  rhs) ;
};

vector operator*(const int lhs, const vector &rhs);

std::ostream & operator<<( std::ostream & lhs, vector pos );

#endif