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

int N, total = 0;
ll a, b, mx = -1;
vec2ll mtns;

int main(){
	setIO("mountains");
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> b;
    mtns.push_back({a-b, a+b});
  }

  sort(mtns.begin(), mtns.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0] == v2[0] ? v1[1]>v2[1] : v1[0]<v2[0];});

  for (int i = 0; i < N; i++){
    if (mx >= mtns[i][1]) total++;
    mx = max(mx, mtns[i][1]);
  }

  cout << max(N-total, 1) << "\n";

  return 0;
}