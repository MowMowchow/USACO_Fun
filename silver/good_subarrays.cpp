#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int cases;

int main(){
  cin >> cases;
  for (int c = 0; c < cases; c++){
    ll N, total = 0, arr[100011];
    map<ll, ll> mapp;
    string temp;
    cin >> N >> temp;
    memset(arr, 0, sizeof(arr));

    for (int i = 1; i <= N; i++) arr[i] = ((ll) temp[i-1]) + arr[i-1] - '0';

    for (int i = 0; i <= N; i++) {
      if (mapp.find(arr[i]-i) == mapp.end()) mapp[arr[i]-i] = 1;
      else mapp[arr[i]-i]++;
    }

    for (auto i = mapp.begin(); i != mapp.end(); i++){
      total += (i->second*(i->second-1))/2;
    }

    cout << total << "\n";

  }
  return 0;
}