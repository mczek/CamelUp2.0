#include <Rcpp.h>


// Define class

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


// Approach 4: Module docstrings

RCPP_EXPOSED_CLASS(Double)
  RCPP_MODULE(double_cpp) {
    using namespace Rcpp;

    class_<Double>("Double")
      .constructor<double>()
      .method("mult", &Double::mult)
    ;
  }
