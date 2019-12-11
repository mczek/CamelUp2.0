#include <Rcpp.h>

// Approach 1: Standalone functions

//' Multiplies two doubles
//'
//' @param v1 First value
//' @param v2 Second value
//' @return Product of v1 and v2
//' @export
// [[Rcpp::export]]
double mult( double v1, double v2 ) {return v1*v2;}

// Approach 2: Nested items inside fields

//' @name Double
//' @title Encapsulates a double
//' @description Type the name of the class to see its methods
//' @field new Constructor
//' @field mult Multiply by another Double object \itemize{
//' \item Paramter: other - The other Double object
//' \item Returns: product of the values
//' }
//' @export
class Double {
public:
  Double( double v ) : value(v) {}
  double mult( const Double& other ) {return value * other.value;}
private:
  double value;
};

// Approach 3: Stand-alone pages for individual class methods

//' @name Double$new
//' @title Constructs a new Double object
//' @param v A value to encapsulate

// Approach 4: Module docstrings

RCPP_EXPOSED_CLASS(Double)
  RCPP_MODULE(double_cpp) {
    using namespace Rcpp;

    class_<Double>("Double")
      .constructor<double>("Wraps a double")
      .method("mult", &Double::mult, "Multiply by another Double object")
    ;
  }
