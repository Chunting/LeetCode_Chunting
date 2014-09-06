#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-9;

pair<double, int> get_sci(double x) {
  int k = 0;
  int sgn = 0;
  if (x > 0)
    sgn = 1;
  else if (x < 0)
    sgn = -1;
  x = fabs(x);
  if (x < 1) {
    while (x < 1) {
      x *= 10;
      k--;
    }
  } else if (x > 10) {
    while (x > 10) {
      x /= 10;
      k++;
    }
  }
  return make_pair(sgn * x, k);
}

vector<double> get_axis(double x_min, double x_max) {
  double scale = x_max - x_min;
  pair<double, int> sci;
  sci = get_sci(scale);
  int k = sci.second;
  double delta = 1 * pow((double)10, (double)k);
  vector<double> ret;
  sci = get_sci(x_min);
  double x_lower = floor(sci.first * pow((double)10, (double)sci.second - k)) * pow((double)10,(double) k);
  cout<< "x_lower: " << x_lower<< endl;
  sci = get_sci(x_max);
  double x_upper = ceil(sci.first * pow((double)10, (double)sci.second - k)) * pow((double)10,(double) k);
  cout<< "x_upper: " << x_upper<< endl;
  ret.push_back(x_lower);
  double now = x_lower;
  while (now + eps < x_upper) {
    now += delta;
    ret.push_back(now);
  }
  return ret;
}

void test(double a, double b) {
  cout << "----start test----" << endl;
  cout << "a: " << a << " b: " << b << endl;
  vector<double> ret = get_axis(a, b);
  cout << "result:" << endl;
  for (size_t i = 0; i < ret.size(); ++i)
    cout << ret[i] << ' ';
  cout << endl << endl;
}
/*
int main() {
  test(123.123, 7890.789);
  test(0.123, 0.7890789);
  test(999, 1400);
  test(-7890.123, -123.789);
  test(-0.723, -0.1190789);
  test(-1400, -888);
  // unsolved problem
  test(-1400, 0.9);
}
*/
