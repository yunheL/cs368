#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  // http://www.cplusplus.com/reference/ios/fixed/?kw=fixed
  // 
  // Output:
  // default:
  // 3.1416
  // 2006
  // 1e-10
  //
  // fixed:
  // 3.14159
  // 2006.00000
  // 0.00000
  //
  // scientific:
  // 3.14159e+00
  // 2.00600e+03
  // 1.00000e-10

  double a = 3.1415926534;
  double b = 2006.0;
  double c = 1.0e-10;

  std::cout.precision(5);

  std::cout << "default:\n";
  std::cout << a << '\n' << b << '\n' << c << '\n';

  std::cout << '\n';

  std::cout << "fixed:\n" << std::fixed;
  std::cout << a << '\n' << b << '\n' << c << '\n';

  std::cout << '\n';

  std::cout << "scientific:\n" << std::scientific;
  std::cout << a << '\n' << b << '\n' << c << '\n';


  // boolalpha
  //
  // Output
  // true
  // 1
  // false
  // 0
  bool bb = true;
  std::cout << std::boolalpha << bb << '\n';
  std::cout << std::noboolalpha << bb << '\n';
  std::cout << std::boolalpha << !bb << '\n';
  std::cout << std::noboolalpha << !bb << '\n';

}
