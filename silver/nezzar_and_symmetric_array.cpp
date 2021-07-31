#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, T, a, red = 0, curr;
vec1ll arr;
map<ll, ll> vis;
bool bad;


bool solve(){
  sort(arr.begin(), arr.end(), [](const ll&a, const ll&b){return a > b;});
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  N = arr.size();
  red = 0;

  for (int i = 0; i < N; i++) {
    if ((arr[i]-(2*red))%((N-i)*2)) return false;
    curr = (arr[i]-(2*red))/((N-i)*2);
    if (curr <= 0) return false;
    if (vis[curr]) return false;
    vis[curr]++;
    red += curr;
  }
  return true;
}


int main(){
  cin >> T;
  while (T--){
    cin >> N;
    bad = false;

    for (int i = 0; i < 2*N; i++){
      cin >> a;
      arr.push_back(a);
      vis[a]++;
    }
    
    for (int i = 0; i < 2*N; i++){
      bad = (arr[i] % 2 != 0 || vis[arr[i]] != 2) ? true : false;
      if (bad) break;
    }

    if (bad) cout << "NO\n";
    else{
      vis.clear();
      cout << (solve() ? "YES\n" : "NO\n");
    }
    arr.clear();
    vis.clear();
  }

  return 0;
}