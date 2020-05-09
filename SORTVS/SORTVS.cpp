
#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>
typedef long long ll;

using namespace std;


// sorting from 0 to n-1

vector<int> arr;
vector<vector<int>> pairs;
vector<pair<int,int>> sorted;
int flag = 1;

int find_path(int at, int reach, vector<int> visited, vector<int> array) {
  if (at == reach) {
    /*if (flag) {
      arr = array;
      flag = 0;
    }*/
    return 0;
  }
  int min = INT_MAX;
  for (int i = 0; i < arr.size(); i++) {
    if (pairs[at][i] == 0 && visited[i] == 0) {
      vector<int> temp_visit = visited;
      temp_visit[i] = 1;
      vector<int> temp = array;
      int t = temp[at];
      temp[at] = temp[i];
      temp[i] = t;
      int l = find_path(i, reach, temp_visit, temp);
      min = min > l ? l : min;
    }
  }
  return min;
}

int main() {
  int t;
  cin >> t;
  
  while (t--) {
    int cost = 0;
    int n, m;
    cin >> n >> m;
    arr.clear();
    arr = vector<int> (n, 0);
    pairs.clear();
    pairs = vector<vector<int>> (n, vector<int> (n, 1));
    sorted.clear();
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sorted.push_back(make_pair(arr[i], i));
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      pairs[a-1][b-1] = 0;
      pairs[b-1][a-1] = 0;
    }
    //sorted = arr;
    sort(sorted.begin(), sorted.end());
    
    for (int i = 0; i < n; i++) {
      flag = 1;
      if (arr[i] == i+1) {
        continue;
      }
      vector<int> visited(n, 0);
      visited[sorted[i].second] = 1;
      int c = find_path(sorted[i].second, i, visited, arr);
      if (c == 0) {
        arr[sorted[i].second] = arr[i];
        arr[i] = i+1;
        sorted[arr[sorted[i].second] - 1].second = sorted[i].second;
        sorted[i].second = i;
      }
    }

    for (int i = 0; i < n; i++) {
      flag = 1;
      if (arr[i] == i+1) {
        continue;
      }
      vector<int> visited(n, 0);
      visited[sorted[i].second] = 1;
      int c = find_path(sorted[i].second, i, visited, arr);
      if (c == 0) {
        arr[sorted[i].second] = arr[i];
        arr[i] = i+1;
        sorted[arr[sorted[i].second] - 1].second = sorted[i].second;
        sorted[i].second = i;
      } else {
        cost++;
        int temp = arr[i];
        int want = sorted[i].second+1;
        vector<int> visited(n, 0);
        visited[sorted[want-1].second] = 1;
        int cost2 = find_path(sorted[want-1].second, i, visited, arr);
        if (cost2 == 0) {
          arr[i] = want;
          arr[sorted[want-1].second] = temp;
          sorted[arr[i]-1].second = i;
          sorted[arr[sorted[want-1].second] - 1].second = sorted[want-1].second;
        }
        arr[sorted[i].second] = arr[i];
        arr[i] = i+1;
        sorted[arr[sorted[i].second] - 1].second = sorted[i].second;
        sorted[i].second = i;
      }
    }
    cout << cost << "\n";
  }
  return 0;
}



