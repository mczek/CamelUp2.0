#include <Rcpp.h>
using namespace Rcpp;

//' Multiplies two doubles
//'
//' @param v1 First value
//' @param v2 Second value
//' @return Product of v1 and v2
//' @export
// [[Rcpp::export]]
int RandomNum(int N) {
  int val = rand() % 3 + 1;
  return val;
}
