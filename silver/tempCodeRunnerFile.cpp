#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll N, arr[200010], gcds[200010], low1 = LONG_LONG_MAX, low2 = LONG_LONG_MAX;
map<ll, ll> mapp;

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
  
  for (int i = 0; i < N; i++) gcds[i] = gcd(arr[i], arr[(i+1)%N]);

  for (int i = 0; i <= N; i++){
    if (mapp.find(gcds[i]) == mapp.end()) mapp[gcds[i]] = 1;
    else mapp[gcds[i]]++;
  }

  for (auto i = mapp.begin(); i != mapp.end(); i++){
    if (i->first != 0 && i->first < low1){
      low2 = low1;
      low1 = i->first;
    } else if (i->first != 0 && i->first < low2) low2 = i->first;
  }

  if (low2 == LONG_LONG_MAX) low2 = max(arr[0], arr[1]);

  cout << (mapp[low1] == (ll) 2 ? low2 : low1) << "\n";

  return 0;
}