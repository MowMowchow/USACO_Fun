#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, x, a, b, ans = 0;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
  cin >> x >> N;
  for (ll i = 0; i < N; i++) {
    cin >> a;
    pq.push(a);
  }

  while (pq.size() > 1){
    a = pq.top(); pq.pop();
    b = pq.top(); pq.pop();
    ans += a+b;
    pq.push(a+b);
  }

  cout << ans << "\n";

  return 0;
}