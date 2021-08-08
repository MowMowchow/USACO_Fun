#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, curr = 0, K = 0, l, r, high, ans = INT_MAX;
string s;
map<char, int> vis;
vector<char> letters;
bool done = false;

int main(){
  cin >> N >> s;

  for (auto i: s)
    if (vis.find(i) == vis.end()){
      vis[i] = 0;
      K++;
      letters.push_back(i);
    }   

  int arr[K][N+1];
  memset(arr, -1, sizeof(arr)); 

  for (int i = 0; i < K; i++){
    for (int j = N-1; j >= 0; j--){
      if (s[j] == letters[i]) arr[i][j] = j;
      else arr[i][j] = arr[i][j+1];
    }
  } 

  for (int i = 0; i < N; i++){
    high = -1;
    for (int j = 0; j < K; j++){
      if (arr[j][i] == -1){
        done = true;
        break;
      } else high = max(high, arr[j][i]);
    }
    if (done) break;
    else ans = min(ans, high-i+1);
  }

  cout << ans << "\n";

  return 0;
}