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

ll N, a, t, T = 0, w = 0, cowsProcessed = 0, k = 0;
vec2ll cows;
map<ll, int> cowsHit;
priority_queue<vec1ll, vec2ll, greater<vec1ll>> wq;

int main(){
	setIO("convention2");

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> t;
    cows.push_back({a, t, i+1});
  }

  sort(cows.begin(), cows.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0]==v2[0]?v1[2] < v2[2]:v1[0]<v2[0];});

  while (cowsProcessed < N){
    if (!wq.empty()){
      cowsProcessed++;
      vec1ll curr = wq.top();
      wq.pop();
      cowsHit[curr[0]] = 1;
      if (curr[1] > T) {
        T = curr[1] + curr[2];
      } else {
        w = max(w, T-curr[1]);
        T += curr[2];
      }
      while (k < N && cows[k][0] <= T){
        wq.push({cows[k][2], cows[k][0], cows[k][1]});
        k++;
      }
    } else if (k < N && !cowsHit[cows[k][2]]){
      cowsHit[cows[k][2]] = 1;
      cowsProcessed++;
      if (cows[k][0] > T){ 
        T = cows[k][0] + cows[k][1];
        k++;
      } else {
        w = max(w, T-cows[k][0]);
        T += cows[k][1];
        k++;
      }
      while (k < N && cows[k][0] <= T){
        wq.push({cows[k][2], cows[k][0], cows[k][1]});
        k++;
      }
    }
  }

  cout << w << "\n";

  return 0;
}