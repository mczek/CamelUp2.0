#include <Rcpp.h>
#include <string>


// Define die class

//' @name Die
//' @title Encapsulates a double
//' @description Type the name of the class to see its methods
//' @field new Constructor
//' @field mult Multiply by another Double object \itemize{
//' \item Paramter: other - The other Double object
//' \item Returns: product of the values
//' }
//' @export
class Die {
private:
  std::string color;
  int value;
public:
  Die(std::string c){
    color = c;
    value = 0;
  }

  std::string getColor() {
    return color;
  }

  int getValue(){
    return value;
  }

  int roll(){
    value = rand() % 3 + 1;
    return value;
  }
};


// Approach 4: Module docstrings

RCPP_EXPOSED_CLASS(Die)
  RCPP_MODULE(die_cpp) {
    using namespace Rcpp;

    class_<Die>("Die")
      .constructor<std::string>()
      .method("getColor", &Die::getColor)
      .method("getValue", &Die::getValue)
      .method("roll", &Die::roll)
    ;
  }
