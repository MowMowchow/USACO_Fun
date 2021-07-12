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


int N, K, B, arr[100100], a, final = INT_MAX;

int main(){
	setIO("maxcross");
  cin >> N >> K >> B;
  memset(arr, 0, sizeof(arr));

  for (int i = 0; i < B; i++){
    cin >> a;
    arr[a]++;
  }

  for (int i = 1; i <= N; i++) arr[i] += arr[i-1];

  for (int i = K; i <= N; i++) final = min(final, arr[i]-arr[i-K]);

  cout << final << "\n";

  return 0;
}