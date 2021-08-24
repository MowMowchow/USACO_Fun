#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, UN, a, b;
ll arr[400010], ans[200010];
vec1ll uni;
vec2ll coors;
map<ll, ll> vis, cm, cmRev;

int main(){
  memset(arr, 0, sizeof(arr));
  memset(ans, 0, sizeof(ans));

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> b; b++;
    if (!vis[a]){
      vis[a]++;
      uni.push_back(a);
    }
    if (!vis[b]){
      vis[b]++;
      uni.push_back(b);
    }
    coors.push_back({a, b});
  }

  sort(uni.begin(), uni.end());
  UN = uni.size();

  for (int i = 1; i <= UN; i++){
   cm[uni[i-1]] = i;
   cmRev[i] = uni[i-1];
  }

  for (auto p: coors){
    arr[cm[p[0]]]++;
    arr[cm[p[1]]]--;
  }

  for (int i = 1; i <= UN; i++) arr[i] += arr[i-1];

  for (int i = 0; i < UN; i++) ans[arr[i]] += cmRev[i+1]-cmRev[i];

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  } cout << "\n";
  
  return 0;
}