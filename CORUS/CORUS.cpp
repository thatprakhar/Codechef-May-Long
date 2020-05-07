
#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;


int main() {
  int t;
  cin >> t;
  
  while (t--) {
    
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    
    map<char,ll> char_count;
    
    for (int i = 0; i < n; i++) {
      if (char_count.count(str[i]) == 0) {
        char_count.insert({str[i], 1});
      } else {
        char_count.at(str[i]) += 1;
      }
    }
    map<char,ll>::iterator it;
    
    for (int i = 0; i < q; i++) {
      ll c, ans = 0;
      cin >> c;
      for (it = char_count.begin(); it != char_count.end(); it++) {
        if (it->second > c) {
          ans += (it->second - c);
        }
      }
      cout << ans << "\n";
    }
    
  }
  
  return 0;
}
