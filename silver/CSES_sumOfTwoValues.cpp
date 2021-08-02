#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, X, a;
map<ll, ll> mapp;
vec1ll nums;
bool bad = true;

int main(){
  cin >> N >> X;

  for (int i = 0; i < N; i++){
    cin >> a;
    nums.push_back(a);
    mapp[X-a] = i+1;
  }

  for (int i = 1; i <= N; i++){
    if (mapp[nums[i-1]] && mapp[nums[i-1]] != i){
      cout << i << " " << mapp[nums[i-1]] << "\n";
      bad = false;
      break;
    }
  }
  if (bad) cout << "IMPOSSIBLE\n";
  return 0;
}