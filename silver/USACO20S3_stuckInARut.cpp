#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;


ll N, p[1010][2], ans[1010], NS, ES, x, y;  // parent, val
vec2ll north, east;
string c;

void compress(int cow, int depth){
  if (p[cow][0] != cow){
    ans[p[cow][0]] += depth;
    compress(p[cow][0], depth+1);
  }
}

int main(){
  cin >> N;
  memset(ans, 0, sizeof(ans));

  for (int i = 1; i <= N; i++){
    cin >> c >> x >> y;
    if (c == "N") north.push_back({x, y, i});
    else east.push_back({x, y, i});
    p[i][0] = i;
    p[i][1] = LONG_LONG_MAX;
  } 

  NS = north.size(); ES = east.size();

  sort(north.begin(), north.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];});
  sort(east.begin(), east.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[1]==v2[1]?v1[0]>v2[0]:v1[1]<v2[1];});

  for (int i = 0; i < NS; i++){
    for (int j = 0; j < ES; j++){
      if (north[i][0] >= east[j][0] && north[i][1] <= east[j][1]){
        if (east[j][1]-north[i][1] < north[i][0]-east[j][0] && p[east[j][2]][1] > north[i][0]-east[j][0] && p[north[i][2]][0] == north[i][2]){ // north stops east
          p[east[j][2]][1] = north[i][0]-east[j][0];
          p[east[j][2]][0] = north[i][2]; 
          ans[north[i][2]] += ans[east[j][2]]+1;
        }
        else if (north[i][0]-east[j][0] < east[j][1]-north[i][1] && p[north[i][2]][1] > east[j][1]-north[i][1] && p[east[j][2]][0] == east[j][2]){ // east stops north
          p[north[i][2]][1] = east[j][1]-north[i][1];
          p[north[i][2]][0] = east[j][2];
          ans[east[j][2]] += ans[north[i][2]]+1;
        }
      }
    }
  }

  for (int i = 1; i <= N; i++)
    cout << ans[i] << "\n"; 

  return 0;
}