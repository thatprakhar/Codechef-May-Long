
#include <iostream>
#include <vector>

using namespace std;


int main() {
  int t;
  cin >> t;
  
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int max = 0;
    int min = n+1;
    for (int i = 0; i < n; i++) {
      int l = i;
      int r = i;
      while (l > 0) {
        if (arr[l] - arr[l-1] <= 2) {
          l--;
        } else {
          break;
        }
      }
      while (r < n-1) {
        if (arr[r+1] - arr[r] <= 2) {
          r++;
        } else {
          break;
        }
      }
      int t = r - l  +1;
      if (t > max) {
        max = t;
      }
      if (t < min) {
        min = t;
      }
    }
    cout << min << " " << max << "\n";
  }
  
  return 0;
}
