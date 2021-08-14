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

ll N, a, t, T = 0, w = 0;
vec2ll cows;

int main(){
	// setIO("convention2");

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> t;
    cows.push_back({a, t, i}); // finishes at a+t inclusive -> next goes at a+t+1
  }

  sort(cows.begin(), cows.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0]==v2[0]?v1[2] < v2[2]:v1[0]<v2[0];});
  // have a waiting queue and each time you use a cow update the queue
  
  for (auto c: cows){
    if (c[0] > T){ // if the cow does not have to wait
      T = c[0]+c[1]; // set to next avail time
    } else { // if the cow has to wait
      w += T-c[0]; 
      T += c[1];
    }
    cout << "checking cow: " << c[2] << " spending: " << c[0] << " to " << c[1] << " | T: " << T << " | w: " << w <<  "\n";
  }

  cout << w << "\n";

  return 0;
}