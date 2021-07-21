#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

vec2ll coors;
ll a, b, cows[100010], low = LONG_LONG_MAX, total = 0;
int N;
map<ll, int> cowSpot;
map<int, bool> currCows;

int main(){
	setIO("lifeguards");
  cin >> N;

  for (int i = 1; i <= N; i++){
    cin >> a >> b;
    coors.push_back({a, 1});
    coors.push_back({b, -1});
    cowSpot[a] = i; cowSpot[b] = i;
  }

  sort(coors.begin(), coors.end());
  for (int i = 1; i < N*2; i++) coors[i][1] += coors[i-1][1];
  
  for (int i = 0; i < 2*N-1; i++){
    if (currCows.find(cowSpot[coors[i][0]]) == currCows.end()) currCows[cowSpot[coors[i][0]]] = true;
    else currCows.erase(cowSpot[coors[i][0]]);
    if (coors[i][1] == 1)
      for (const auto &cow: currCows)
        cows[cow.first] += coors[i+1][0]-coors[i][0];
    if (coors[i][1] > 0) total += coors[i+1][0]-coors[i][0];
  }  

  for (int i = 1; i <= N; i++) low = min(low, cows[i]);

  cout << total-low << "\n";

  return 0;
}