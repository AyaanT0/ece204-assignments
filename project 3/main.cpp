#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

// Function declarations
int main();
unsigned int roots( double coeffs[], unsigned int degree );
double  horner( double x, double coeffs[], unsigned int degree );
double dhorner( double x, double coeffs[], unsigned int degree );
double newton( double coeffs[], unsigned int degree );
double divide( double r, double poly[], unsigned int degree );
void print( double coeffs[], unsigned int complex_degree, unsigned int degree );

// Function definitions
int main() {
  std::cout.precision( 16 );

  // The output should be:
  //      Remaining polynomial:
  //          3+1x+1x^2
  //      Real roots:
  //          -2
  //          +1
  //          +3
  double p[6]{ 18, -9, -5, -4, -1, 1 };
  unsigned int degree{ roots( p, 5 ) };
  print( p, degree, 5 );

    //////////////////////////////////////////////
   // The sample input and output in Section 9 //
  //////////////////////////////////////////////
  double q0a[1]{ -14.1 };
  unsigned int c0a{ roots( q0a, 0 ) };
  print( q0a, c0a, 0 );
  // Expected output:
  // Remaining polynomial:
  //     -14.1
  // Real roots:

  double q1a[2]{ -5.0, 2.0 };
  unsigned int c1a{ roots( q1a, 1 ) };
  print( q1a, c1a, 1 );
  // Expected output:
  // Remaining polynomial:
  //     2
  // Real roots:
  //     +2.5

  double q2a[3]{ 5.0, 2.0, 2.0 };
  unsigned int c2a{ roots( q2a, 2 ) };
  print( q2a, c2a, 2 );
  // Expected output (no real roots):
  // Remaining polynomial:
  //     5+2x+2x^2
  // Real roots:

  double q2b[3]{ 5.0, 2.0, -2.0 };
  unsigned int c2b{ roots( q2b, 2 ) };
  print( q2b, c2b, 2 );
  // Expected output (two real roots):
  // Remaining polynomial:
  //     -2
  // Real roots:
  //     -1.1583123951777
  //     +2.1583123951777

  double q3a[4]{ -100.8, 8.4, -4.2, 4.2 };
  unsigned int c3a{ roots( q3a, 3 ) };
  print( q3a, c3a, 3 );
  // Expected output (one real and two complex roots):
  // Remaining polynomial:
  //     33.6+8.4x+4.2x^2
  // Real roots:
  //     +3




  // Question 1
  /*
  double p0a[1]{ 0.7 };
  unsigned int d0a{ roots( p0a, 0 ) };
  print( p0a, d0a, 0 );

  double p0b[1]{ 0.0 };
  unsigned int d0b{ roots( p0b, 0 ) };
  print( p0b, d0b, 0 );
  */


  // Question 2
  /*
  double p1a[2]{ 0.7, 0.5 };
  unsigned int d1a{ roots( p1a, 1 ) };
  print( p1a, d1a, 1 );

  double p1b[2]{ 0.7, -0.5 };
  unsigned int d1b{ roots( p1b, 1 ) };
  print( p1b, d1b, 1 );
  */


  // Question 3
  /*
  double p2a[3]{ 0.3, 0.1, 0.5 };
  unsigned int d2a{ roots( p2a, 2 ) };
  print( p2a, d2a, 2 );

  double p2b[3]{ 0.7, -0.5, -0.2 };
  unsigned int d2b{ roots( p2b, 2 ) };
  print( p2b, d2b, 2 );
  */


  // Question 4
  /*
  double p3a[4]{ -0.2, 0.3, -0.9, 0.3 };
  unsigned int d3a{ roots( p3a, 3 ) };
  print( p3a, d3a, 3 );

  double p3b[4]{ 0.1, 0.3, -0.9, 0.3 };
  unsigned int d3b{ roots( p3b, 3 ) };
  print( p3b, d3b, 3 );
  */


  // Question 5
  /*
  double p4a[5]{ -12.0, -8.4, 2.4, 0.0, 1.2 };
  unsigned int d4a{ roots( p4a, 4 ) };
  print( p4a, d4a, 4 );

  double p4b[5]{ -14.4, -19.2, -1.2, 4.8, 1.2 };
  unsigned int d4b{ roots( p4b, 4 ) };
  print( p4b, d4b, 4 );

  double p4c[5]{ -54.0, -37.8, -29.7, -8.1, -2.7 };
  unsigned int d4c{ roots( p4c, 4 ) };
  print( p4c, d4c, 4 );
  */


  // Question 6
  /*
  double p5a[6]{ -157.50, 68.25, 29.75, 12.25, -5.25, -3.5 };
  unsigned int d5a{ roots( p5a, 5 ) };
  print( p5a, d5a, 5 );

  double p5b[6]{ -16.2, 47.25, -22.275, -19.575, 8.1, 2.7 };
  unsigned int d5b{ roots( p5b, 5 ) };
  print( p5b, d5b, 5 );

  double p5c[6]{
    -739.3056852825, 379.9560444975, -216.18149622,
      63.3701740,    -19.2249,          4.1
  };
  unsigned int d5c{ roots( p5c, 5 ) };
  print( p5c, d5c, 5 );
  */


  // Question 7
  /*
  double p7[3]{ 0.7, -0.5, 0.0 };
  unsigned int d7{ roots( p7, 2 ) };
  print( p7, d7, 2 );
  */
  return 0;
}

// Find all real roots of polynomial
unsigned int roots( double coeffs[], unsigned int degree ) {
  if (degree == 0) return 0; // Const has no roots
  if (coeffs[degree] == 0.0) throw std::invalid_argument("leading coeff can't be zero"); // Leading coeff must be nonzero

  unsigned int deg = degree;

  // Loop to find root, divide, and reduce degree
  while (deg > 0) {
    double root = newton(coeffs, deg);
    if (std::isnan(root)) break; // No real roots found by newtons method

    divide(root, coeffs, deg); //divide polynomial by x-r
    coeffs[deg] = root; // store the root at the correct index
    deg--; // reduce the degree
  }
  std::sort(coeffs + deg + 1, coeffs + degree + 1); // Sort the real roots at indices n + 1 in ascending order
  return deg;
}

// Newton's method to approx a root
double newton( double coeffs[], unsigned int degree ) {
  if (degree == 0) return NAN; // Const has no roots
  if (coeffs[degree] == 0.0) throw std::invalid_argument("leading coeff can't be zero"); // Leading coeff must be nonzero

  double init_guess = 211.19343; // Student number is 21119343 (arbitrary initial guess)

  // Iterate to find convergence and determine root
  for (int i = 0; i < 1000; i++) { // Max iterations arbitrarily set to 1000
    double f = horner(init_guess, coeffs, degree);
    if (std::abs(f) < 1e-9) return init_guess; // If (close to) zero, found root

    double df = dhorner(init_guess, coeffs, degree);
    if (std::abs(df) < 1e-9) return NAN; // If derivative is (close to) zero then Newton's method will not work

    double new_guess = init_guess - f / df; // Update the guess (newtons method formula)
    if (std::abs(new_guess - init_guess) < 1e-9) return new_guess; // If step size is super close to zero, converged
    init_guess = new_guess;
  }
  return NAN; // If we have done all iterations without convergence, we return a failure
}

// The polynomial division algorithm is implemented for you. 
double divide( double r, double poly[], unsigned int degree ) {
  double s{ poly[degree] };

  for ( unsigned int k{ degree }; k > 0; --k ) {
    double t{ poly[k - 1] + r*s };
    poly[k - 1] = s;
    s = t;
  }

  return s;
}

// Horner's rule is implemented here for you
double horner( double x, double coeffs[], unsigned int degree ) {
  double result{ coeffs[degree] };

  for ( unsigned int k{ degree }; k > 0; ) {
    --k;
    result = result*x + coeffs[k];
  }

  return result;
}

// Horner's rule to eval the derivative of a polynomial at x
double dhorner( double x, double coeffs[], unsigned int degree ) {
  if (degree == 0) return 0.0;

  // Start with the leading coeff
  double result = degree * coeffs[degree];

  // Horner's rule used for the remaining terms
  for (unsigned int k = degree - 1; k > 0; k--) {
    // Multiply coeffs by corresponding degree k
    result = result * x + k * coeffs[k];
  }
  return result;
}

void print(
    double coeffs[],
    unsigned int complex_degree,
    unsigned int degree
) {
    // Store the current value of precision
    // and set the precision to 16 digits
    std::streamsize old_precision{ std::cout.precision( 16 ) };
  
    std::cout << "Remaining polynomial:" << std::endl;
    std::cout << "\t" << coeffs[0];

    // Show a "+" sign in front of all positive floating-point numbers
    std::cout << std::showpos;
  
    if ( complex_degree >= 1 ) {
        std::cout << coeffs[1] << "x";
    }

    for ( unsigned int k{ 2 }; k <= complex_degree; ++k ) {
        std::cout << coeffs[k] << "x^" << k;
    }
        
    std::cout << std::endl << "Real roots:" << std::endl;

    for ( unsigned int k{ complex_degree + 1 }; k <= degree; ++k ) {
        std::cout << "\t" << coeffs[k] << std::endl;
    }

    // Stop showing the leading "+"
    std::cout << std::noshowpos << std::endl;

    // Restore the original value of precision
    std::cout.precision( old_precision );
}