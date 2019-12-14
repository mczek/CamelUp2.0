#include <Rcpp.h>
#include <string>

class Camel {
private:
  std::string color;
  int space;
  int height;
public:
  Camel(std::string c);
  std::string getColor();

  int getSpace();

  int getHeight();

  void setSpace(int n);
  void setHeight(int n);

  Camel duplicate();

};


// RCPP_EXPOSED_CLASS(Camel)
//   RCPP_MODULE(camel_cpp) {
//     using namespace Rcpp;
//
//     class_<Camel>("Camel")
//       .constructor<std::string>()
//       .method("getColor", &Camel::getColor)
//       .method("getSpace", &Camel::getSpace)
//       .method("getHeight", &Camel::getHeight)
//       .method("setSpace", &Camel::setSpace)
//       .method("setHeight", &Camel::setHeight)
//       .method("duplicate", &Camel::duplicate)
//     ;
//   }
