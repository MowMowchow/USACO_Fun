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

ll N, K, a, final = 0, NR;
vec1ll arr, ans;
vec2ll ranges;


int bs(ll x){
  ll l = 0, r = NR-1, mid, ans = -1;
  while(l <= r){
    mid = l+(r-l)/2;
    if (ranges[mid][0] <= x) l = mid+1;
    else{
      ans = mid;
      r = mid-1;
    }
  }
  return ans;
}

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
      if (r < N-1) r++;
      else {
        ranges.push_back({l, r-1, r-l});
        l++;
      }
    } else {
      if (r > 0)
        if (arr[r-1]-arr[l] <= K)
          ranges.push_back({l, r-1, r-l});
      l++;
    }
    if (l == N-1) break;
  }

  NR = ranges.size();

  sort(ranges.begin(), ranges.end());

  for (int i = NR-2; i >= 0; i--) ranges[i][2] = max(ranges[i][2], ranges[i+1][2]);

  for (int i = 0; i < NR; i++){
    ll res = bs(ranges[i][1]);
    if (res != -1)
      final = max(final, (ranges[i][1]-ranges[i][0]+1)+ranges[res][2]);
  }

  cout << final << "\n";

  return 0;
}