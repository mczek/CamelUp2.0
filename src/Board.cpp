#include <Rcpp.h>
#include <list>
#include "Space.h"



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
  std::list <int> spaces;
public:
  Board(int nSpaces){
    for(int i = 0; i < nSpaces; i++){
      spaces.push_back(i);
    }
  }

  int getNSpaces() {
    return spaces.size();
  }
};


// Approach 4: Module docstrings

RCPP_EXPOSED_CLASS(Board)
  RCPP_MODULE(board_cpp) {
    using namespace Rcpp;

    class_<Board>("Board")
      .constructor<int>()
      .method("getNSpaces", &Board::getNSpaces)

    ;
  }
