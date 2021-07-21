#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

vec2ll coors;
int N;
ll a, b, final = 0;

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> b;
    coors.push_back({a, 1});
    coors.push_back({b+1, -1});
  }

  sort(coors.begin(), coors.end());

  for (int i = 1; i < coors.size(); i++){
    coors[i][1] += coors[i-1][1];
    final = max(final, coors[i][1]);
  }

  cout << final << "\n";

  return 0;
}