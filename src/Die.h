#include <Rcpp.h>
#include <string>

class Die {
private:
  std::string color;
  int value;
public:
  Die(std::string c);

  std::string getColor() ;

  int getValue();

  int roll();
};

