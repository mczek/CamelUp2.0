#include <Rcpp.h>
#include <stack>
#include "Camel.h"


class Space {
private:
  int position;
  std::stack <Camel> camels;
  int nCamels;
public:
  Space(int pos);

  int getPosition();

  void addCamel(Camel c);

  int getNCamels();
};

