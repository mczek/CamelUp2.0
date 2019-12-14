#include <Rcpp.h>
#include <string>


// Define camel class

//' @name Camel
//' @title Encapsulates a double
//' @description Type the name of the class to see its methods
//' @field new Constructor
//' @field mult Multiply by another Double object \itemize{
//' \item Paramter: other - The other Double object
//' \item Returns: product of the values
//' }
//' @export
class Camel {
private:
  std::string color;
  int space;
  int height;
public:
  Camel(std::string c){
    color = c;
    space = 0;
    height = 0;
  }

  std::string getColor() {
    return color;
  }

  int getSpace(){
    return space;
  }

  int getHeight(){
    return height;
  }

  void setSpace(int n){
    space = n;
  }

  void setHeight(int n){
    height = n;
  }

  Camel duplicate(){
    Camel newCamel = Camel(color);
    newCamel.setSpace(space);
    newCamel.setHeight(height);
    return newCamel;
  }

};


RCPP_EXPOSED_CLASS(Camel)
  RCPP_MODULE(camel_cpp) {
    using namespace Rcpp;

    class_<Camel>("Camel")
      .constructor<std::string>()
      .method("getColor", &Camel::getColor)
      .method("getSpace", &Camel::getSpace)
      .method("getHeight", &Camel::getHeight)
      .method("setSpace", &Camel::setSpace)
      .method("setHeight", &Camel::setHeight)
      .method("duplicate", &Camel::duplicate)
    ;
  }
