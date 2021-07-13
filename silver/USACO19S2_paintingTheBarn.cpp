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

int arr[1010][1010], N, K, xa, ya, xb, yb, total = 0;

int main(){
	setIO("paintbarn");
  cin >> N >> K;

  memset(arr, 0, sizeof(arr));

  for (int i = 0; i < N; i++){
    cin >> xa >> ya >> xb >> yb;
    xa++; ya++; xb++; yb++;
    arr[xa][ya]++; arr[xb][yb]++;
    arr[xa][yb]--; arr[xb][ya]--;
  }

  for (int i = 1; i <= 1000; i++){
    for (int j = 1; j <= 1000; j++){
      arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
      total += arr[i][j] == K ? 1 : 0;
    }
  } 

  cout << total << "\n";

  return 0;
}