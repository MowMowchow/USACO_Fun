#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll N, X, curr, final = 0, arr[200100];
map<ll, int> mapp;

int main(){
  cin >> N >> X;

  memset(arr, 0, sizeof(arr));
  mapp[0] = X == 0 ? 0 : 1;
  
  for (int i = 1; i <= N; i++){
    cin >> curr;
    arr[i] += curr + arr[i-1];
    
    if (mapp.find(arr[i]) == mapp.end()) mapp[arr[i]] = 1;
    else mapp[arr[i]]++;

    if (mapp.find(arr[i]-X) != mapp.end()) final += mapp[arr[i]-X];
  }

  cout << final << "\n";

  return 0;
}