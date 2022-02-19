#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll a, b, arr[2510][2510], N, total = 0;
vec2ll coors;

int main(){
  cin >> N;
  
  memset(arr, 0, sizeof(arr));

  for (int i = 0; i < N; i++){
    cin >> a >> b;
    coors.push_back({a, b});
  }

  sort(coors.begin(), coors.end());
  for (int i = 1; i <= N; i++) coors[i-1][0] = i;
  sort(coors.begin(), coors.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[1]<v2[1];});
  for (int i = 1; i <= N; i++) coors[i-1][1] = i;

  for (int i = 0; i < N; i++) arr[coors[i][0]][coors[i][1]]++;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];

  for (int i = 0; i < N; i++){
    for (int j = i; j < N; j++){
      ll x1 = min(coors[i][0], coors[j][0]),
         y1 = min(coors[i][1], coors[j][1]),
         x2 =  max(coors[i][0], coors[j][0]),
         y2 =  max(coors[i][1], coors[j][1]);

      total += 
      (arr[x1][y2]-arr[0][y2]-arr[x1][y1-1]+arr[0][y1-1])*
      (arr[N][y2]-arr[x2-1][y2]-arr[N][y1-1]+arr[x2-1][y1-1]);
    }
  }

  cout << total+1 << "\n";

  return 0;
}
