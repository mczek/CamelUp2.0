#include <Rcpp.h>
#include <list>
#include "Space.h"
#include "Die.h"
#include <vector>
#include <algorithm>




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
  std::list <Space> spaces;
  std::vector <Die> dice;
public:
  Board(int nSpaces){
    for(int i = 0; i < nSpaces; i++){
      spaces.push_back(Space(i));
    }
    resetDice();
  }

  int getNSpaces() {
    return spaces.size();
  }

  int getNDiceRemaining() {
    return dice.size();
  }

  void resetDice(){
    dice = std::vector <Die>();
    dice.push_back(Die("Green"));
    dice.push_back(Die("Blue"));
    dice.push_back(Die("White"));
    dice.push_back(Die("Yellow"));
    dice.push_back(Die("Orange"));
    std::random_shuffle(dice.begin(), dice.end());
  }

  Die selectDie(){
    Die selectedDie = dice.back();
    dice.pop_back();
    return selectedDie;
  }
};


// Approach 4: Module docstrings

RCPP_EXPOSED_CLASS(Board)
  RCPP_MODULE(board_cpp) {
    using namespace Rcpp;

    class_<Board>("Board")
      .constructor<int>()
      .method("getNSpaces", &Board::getNSpaces)
      .method("getNDiceRemaining", &Board::getNDiceRemaining)

    ;
  }
