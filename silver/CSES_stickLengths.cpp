#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, l, r, med, ans, arr[200010];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  sort(arr, arr+N);
  l = (N % 2) ? N/2 : N/2 - 1;
  r = N/2;

  med = (arr[l]+arr[r])/2;

  for (int i = 0; i < N; i++) ans += abs(med-arr[i]);

  cout << ans << "\n";

  return 0;
}