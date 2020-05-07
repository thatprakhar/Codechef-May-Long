
#include <iostream>
#include <cmath>
#include <vector>

typedef long long ll;

using namespace std;


int main() {
  int t;
  cin >> t;
  
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    vector<pair<int,int>> pairs;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i =0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      pairs.push_back(make_pair(a, b));
    }
    
    int cost = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == i + 1) {
        continue;
      } else {
        int temp = arr[arr[i] - 1];
        arr[arr[i]-1] = arr[i];
        arr[i] = temp;
        cost++;
        i--;
      }
    }
    cout << cost << "\n";
  }
  
  return 0;
}

