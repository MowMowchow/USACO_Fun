#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;
 
ll N, X, a, l, r, curr = 0;
map <ll, ll> mapp;
vec2ll arr, ans;
bool bad = true, reset = false;
 
int main(){
  cin >> N >> X;
  for (int i = 1; i <= N; i++) {
    cin >> a;
    arr.push_back({a, i});
    mapp[X-arr[i-1][0]] = i;
  }
  
  sort(arr.begin(), arr.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0]>v2[0];});
 
  for (int i = 0; i < N-2; i++){
    l = i+1; r = N-1;
    while (l < r){
      curr = arr[l][0] + arr[r][0] + arr[i][0];
      if (curr == X){
        ans.push_back({arr[l][1], arr[r][1], arr[i][1]});
        bad = false;
        break;
      } else if (curr < X) r--;
      else l++;
    }
  }
 
  if (!bad) cout << ans[0][0] << " " << ans[0][1] << " " << ans[0][2] << "\n";
  else cout << "IMPOSSIBLE\n";
  return 0;
}