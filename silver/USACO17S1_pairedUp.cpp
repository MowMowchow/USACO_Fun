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

int N;
ll final = 0, x, y, amt;
deque<vec1ll> cows;

int main(){
	setIO("pairup");

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> x >> y;
    cows.push_back({y, x});
  }

  sort(cows.begin(), cows.end());

  while (!cows.empty()){
    N = cows.size();
    final = max(final, cows[0][0]+cows[N-1][0]);
    amt = min(cows[0][1], cows[N-1][1]);
    cows[0][1] -= amt; cows[N-1][1] -= amt;
    if (cows[0][1] <= 0) cows.pop_front();
    N = cows.size();
    if (!cows.empty() && cows[N-1][1] <= 0) cows.pop_back();
  }

  cout << final << "\n";
  return 0;
}