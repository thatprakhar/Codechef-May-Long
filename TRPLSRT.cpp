
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

typedef long long ll;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    vector<int> indexes(n+1,0);
    vector<pair<int,int>> sorted;
    vector<int> s(n,0);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      s[i] = arr[i];
      sorted.push_back(make_pair(arr[i], i));
    }
    sort(sorted.begin(), sorted.end());
    sort(s.begin(), s.end());
    //new index -> value, original idx
    
    
    vector<vector<int>> ans;
    int flag = 0;
    
    if (arr == s) {
      cout << "0\n";
      continue;
    }
    
    for (int i = 0; i < n; i++) {
      if (arr[i] == i+1) {
        continue;
      }
      int first = i;
      int sec = arr[first] - 1;
      int third = sorted[i].second;
      if (sec == third) {
        continue;
      }
      int temp = arr[first];
      int temp_2 = arr[sec];
      arr[first] = arr[third];
      arr[sec] = temp;
      arr[third] = temp_2;
      sorted[arr[first]-1].second = first;
      sorted[arr[sec]-1].second = sec;
      sorted[arr[third]-1].second = third;
      ans.push_back({first+1, sec+1, third+1});
    }
    
    for (int i = 0; i < n; i++) {
      if (arr[i] == i+1) {
        continue;
      }
      int first = i;
      int sec = arr[first] - 1;
      int third = sorted[i].second;
      if (sec == third) {
        sec = -1;
        for (int j = 0; j < n; j++) {
          if (j != third && arr[j] != j+1 && j != first) {
            sec = j;
            break;
          }
        }
      }
      if (sec == -1) {
        break;
      }
      int temp = arr[first];
      int temp_2 = arr[sec];
      arr[first] = arr[third];
      arr[sec] = temp;
      arr[third] = temp_2;
      sorted[arr[first]-1].second = first;
      sorted[arr[sec]-1].second = sec;
      sorted[arr[third]-1].second = third;
      ans.push_back({first+1, sec+1, third+1});
    }
    if (arr==s) {
      flag = 1;
    }
    if (flag && ans.size() <= k) {
      cout << ans.size() << "\n";
      for (auto a : ans) {
        cout << a[0] << " " << a[1] << " " << a[2] << "\n";
      }
    } else {
      cout << "-1\n";
    }

  }
  return 0;
}

