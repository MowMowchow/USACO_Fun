#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, M, a, final = 0;
vec1ll c, t;


int lower(ll x){
  int l = 0, r = t.size()-1, mid, ans = -1;
  while (l <= r){
    mid = l+(r-l)/2;
    if (t[mid] < x) l = mid+1;
    else {
      ans = mid;
      r = mid-1;
    }
  }
  return ans;
}


int upper (ll x){
  int l = 0, r = t.size()-1, mid, ans = -1;
  while (l <= r){
    mid = l+(r-l)/2;
    if (t[mid] > x) r = mid-1;
    else {
      ans = mid;
      l = mid+1;
    }
  }
  return ans;
}


int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    cin >> a;
    c.push_back(a);
  }
  for (int i = 0; i < M; i++){
    cin >> a;
    t.push_back(a);
  } 

  for (int i = 0; i < N; i++){
    ll r1 = upper(c[i]), r2 = lower(c[i]);
    r1 = r1 == -1 ? LONG_LONG_MAX : c[i]-t[r1];
    r2 = r2 == -1 ? LONG_LONG_MAX : t[r2]-c[i];
    final = max(final, min(r1, r2));
  }

  cout << final << "\n";

  return 0;
}