#include <Rcpp.h>
#include <vector>
#include "Space.h"

class Board {
private:
  std::vector<Space> spaces;
public:
  Board(int nSpaces);
};

