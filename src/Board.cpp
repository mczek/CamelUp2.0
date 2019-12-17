#include <Rcpp.h>
#include <vector>
#include "Space.h"
using namespace Rcpp;
// Define board class

//' @name Board
//' @title Encapsulates a double
//' @description Type the name of the class to see its methods
//' @field new Constructor
//' @field mult Multiply by another Double object \itemize{
//' \item Paramter: other - The other Double object
//' \item Returns: product of the values
//' }
//' @export
class Board {
private:
  int nSpaces;
  std::vector<Space> spaces;
public:
  Board(int n){
    nSpaces = n;
  }
};

RCPP_MODULE(board_cpp){
  class_<Board>("Board")
  .constructor<int>()
  ;
}
