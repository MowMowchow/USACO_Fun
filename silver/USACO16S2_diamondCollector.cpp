#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

ll N, K, a, final = 0;
vec1ll arr, ans;


int main(){
	setIO("diamond");

  cin >> N >> K;
  for (int i = 0; i < N; i++){
    cin >> a;
    arr.push_back(a);
  }

  sort(arr.begin(), arr.end());

  ll l = 0, r = 0;

  while (l <= r){
    if (arr[r]-arr[l] <= K){
      r++;
      if (r == N-1){
        ans.push_back(r-l);
        break;
      }
    } else {
      ans.push_back({r-l});
      l = r;
    }
  }

  sort(ans.begin(), ans.end(), [](const ll&a, const ll&b){return a > b;});

  cout << ans[0]+ans[1] << "\n";

  return 0;
}