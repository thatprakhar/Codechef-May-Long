
#include <iostream>
#include <cmath>
typedef long long ll;

using namespace std;


int main() {
  int t;
  cin >> t;
  
  while (t--) {
    ll x, y, l ,r;
    cin >> x >> y >> l >> r;
    if (x ==0 || y == 0) {
      cout << "0\n" ;
      continue;
    }
    ll z = 0;
    for (int i = 0; i < 40; i++) {
      if (((1L << i) & x) || ((1L << i) & y)) {
        z += (1L << i);
      }
    }

    cout << z << "\n";
  }
  
  return 0;
}
