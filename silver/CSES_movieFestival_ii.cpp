#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

int n, k, a, b, ans = 0;
multiset<int> arr;
vector<vector<int>> times;


int main(){
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    times.push_back({a, b});
  }

  for (int i = 0; i < k; i++) arr.insert(0);

  sort(times.begin(), times.end(), [](const vec1i&aa, const vec1i&bb){return aa[1] < bb[1];});

  for (int i = 0; i < n; i++){
    auto next = arr.upper_bound(times[i][0]);
    if (next != begin(arr)) {
      arr.erase(--next);
      arr.insert(times[i][1]);
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}