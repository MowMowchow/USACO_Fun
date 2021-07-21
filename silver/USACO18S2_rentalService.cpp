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

ll N, M, R, a, b, curr = 0, final = 0;
vec1ll rent, cows;
deque<vec1ll> buy;

int main(){
	setIO("rental");

  cin >> N >> M >> R;
  for (int i = 0; i < N; i++){
    cin >> a;
    cows.push_back(a);
  }
  for (int i = 0; i < M; i++){
    cin >> a >> b;
    buy.push_back({a, b});
  }
  for (int i = 0; i < R; i++){
    cin >> a;
    rent.push_back(a);
  }

  sort(cows.begin(), cows.end(), [](const ll&x, const ll&y){return x > y;});
  sort(rent.begin(), rent.end(), [](const ll&x, const ll&y){return x > y;});
  sort(buy.begin(), buy.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[1] > v2[1];});

  for (int i = 1; i < R; i++) rent[i] += rent[i-1];

  for (int i = 0; i < N; i++){
    while (cows[i] && !buy.empty()){
      if (cows[i] >= buy[0][0]){
        curr += buy[0][0]*buy[0][1];
        cows[i] -= buy[0][0];
        buy.pop_front(); 
      } else if (cows[i] < buy[0][0]){
        curr += cows[i]*buy[0][1];
        buy[0][0] -= cows[i];
        cows[i] = 0;
      }
    }
    int j = R-i-1 > -1 ? R-i-1 : 0;
    final = max(final, curr+rent[j]);
  } 

  cout << final << "\n";

  return 0;
}