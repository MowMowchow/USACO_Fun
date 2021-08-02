#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

int N, cnt = 0, l, r, curr = 0;
ll x, a, arr[200010];

int main(){
  cin >> N >> x;

  for (int i = 0; i < N; i++) cin >> arr[i];
  
  l = 0; r = 0;

  while (l <= r){
    if (r < N && curr + arr[r] <= x){
      curr += arr[r];
      r++;
      if (curr == x) cnt++;
    } else {
      curr -= arr[l];
      l++;
    }
  }
  cout << cnt << "\n"; 
  return 0;
}