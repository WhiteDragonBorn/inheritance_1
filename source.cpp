#include "pair.h"

using namespace comp_pair;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  Pair test = Pair(2, 3);
  Pair test_2(3, 4);

  // cout << test + test;

  Complex ct(3, 4);
  Complex cd(2, 1);

  cout << ct + cd << endl;
  cout << ct / cd << endl;
  cout << 2.0 * ct << ct * 2.9;
}