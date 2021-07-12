#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll N, rs[200100], r = 0, total = 0, curr;

int main(){
  cin >> N;

  memset(rs, 0, sizeof(rs));
  rs[0]++;

  for (int i = 0; i < N; i++){
    cin >> curr;
    r = (r+curr)%N;
    r += r < 0 ? N : 0;
    rs[r]++;
  }

  for (int i = 0; i < N; i++) total += (rs[i]*(rs[i]-1))/2;

  cout << total << "\n";

  return 0;
}