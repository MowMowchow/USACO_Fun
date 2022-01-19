#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

int n, x, l, r, ans = 0, arr[200010];

int main(){
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);

  l = 0;
  r = n-1;

  while (l <= r){
    if (arr[l]+arr[r] <= x && l < r){
      l++;
      r--;
    } else r--; 
    ans++;
  }

  cout << ans << "\n";

  return 0;
}