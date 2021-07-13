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


int arr[810][810], N, NN, K, final = 0;


int main(){
	setIO("lazy");

  cin >> N >> K;
  NN = N*2;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      cin >> arr[i+j][N-i+j];

  for (int i = 0; i <= NN; i++)
    for (int j = 0; j <= NN; j++)
      arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];

  for (int i = 1; i <= NN; i++)
    for (int j = 1; j <= NN; j++)
      final = max(final, arr[i][j]-arr[max(0, i-2*K-1)][j]-arr[i][max(0, j-2*K-1)]+arr[max(0, i-2*K-1)][max(0, j-2*K-1)]);

  cout << final << "\n";

  return 0;
}