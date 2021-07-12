#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, K, a, b, arr[1000010];

int main(){
  cin >> N >> K;
  memset(arr, 0, sizeof(arr));

  for (int i = 0; i < K; i++){
    cin >> a >> b;
    arr[a]++; arr[b+1]--;
  }

  for (int i = 1; i <= N; i++) arr[i] += arr[i-1];

  sort(arr, arr+N+1);

  cout << arr[(N/2)+1] << "\n";

  return 0;
}