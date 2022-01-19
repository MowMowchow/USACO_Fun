#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll n, a, d, currTime = 0, ans = 0;
vector<vector<ll>> arr;

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a >> d;
    arr.push_back({a, d});
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++){
    currTime += arr[i][0];
    ans += arr[i][1]-currTime;
  }

  cout << ans << "\n";

  return 0;
}