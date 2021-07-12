#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll N, arr[200010], low[200010], high[200010], final;

int main(){
  cin >> N;
  memset(arr, 0, sizeof(arr));
  memset(low, 0, sizeof(low));
  memset(high, 0, sizeof(high));

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    arr[i] += arr[i-1];
  }

  low[0] = arr[0];
  high[N+1] = arr[N];
  final = arr[1];

  for (int i = 1; i <= N; i++) low[i] = min(arr[i], low[i-1]);
  
  for (int i = N; i > 0; i--) high[i] = max(arr[i], high[i+1]);
  
  for (int i = 1; i <= N; i++) final = max(final, high[i]-low[i-1]);

  cout << final << "\n";

  return 0;
}