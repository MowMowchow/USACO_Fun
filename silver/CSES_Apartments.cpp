#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;


ll n, m, k, ans = 0, a, u, l, desired[200010], apartments[200010];
bool bad;


int main(){
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> desired[i];
  for (int i = 0; i < m; i++) cin >> apartments[i];

  sort(desired, desired+n);
  sort(apartments, apartments+m);
  int cn = 0, cm = 0;

  while (cn < n && cm < m){
    if (apartments[cm] + k < desired[cn]) cm++;
    else if (apartments[cm] - k > desired[cn]) cn++;
    else {cn++; cm++; ans++;}
  }

  cout << ans << "\n";

  return 0;
}
