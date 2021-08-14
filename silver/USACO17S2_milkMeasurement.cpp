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

ll N, G, day, id, amt, final = 0;
vec2ll updates;
map<ll, ll, greater<ll>> vtc;
map<ll, ll> ctv;

int main(){
	setIO("measurement");
  cin >> N >> G;

  for (int i = 0; i < N; i++){
    cin >> day >> id >> amt;
    updates.push_back({day, id, amt});
    ctv[id] = G;
  }

  sort(updates.begin(), updates.end());

  vtc[G] = N;

  for (auto u: updates){
    id = u[1]; amt = u[2];
    if (ctv[id] == vtc.begin()->first){ 
      vtc[ctv[id]]--;
      bool lastCow = false;
      if (vtc[ctv[id]] == 0){
        vtc.erase(ctv[id]);
        lastCow = true;
      }
      final++;
      ctv[id] += amt;
      vtc[ctv[id]]++;

      if (ctv[id] == vtc.begin()->first)
        if (lastCow && vtc[ctv[id]] < 2) final--;
    } else {
      vtc[ctv[id]]--;
      if (vtc[ctv[id]] == 0) vtc.erase(ctv[id]);
      ctv[id] += amt;
      vtc[ctv[id]]++;
      if (ctv[id] == vtc.begin()->first) final++; 
    }
  }

  cout << final << "\n";
  return 0;
}