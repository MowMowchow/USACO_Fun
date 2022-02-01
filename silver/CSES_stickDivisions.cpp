#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, x, a, ans = 0;
vector<ll> arr;

int main(){
  cin >> N >> x;
  for (int i = 0; i < x; i++){
    cin >> a;
    arr.push_back(a);
  }

  sort(arr.begin(), arr.end(), [](const ll&x, const ll&y){return x > y;});

  for (int i = 0; i < x; i++){
    if (i < x-1) {
      cout << "adding | N: " << N << " | ans: " << ans << "\n";
      ans += N;
    }
    N -= arr[i];
  }

  cout << ans << "\n";

  return 0;
}