#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;
 
int n, nS = 0, ins, arr[200010], stacks[200010];
 
int bs(int x){
  int l = 0, r = nS, mid;
  while (l < r){
    mid = l+(r-l)/2;
    if (stacks[mid] > x) r = mid;
    else l = mid+1;
  }
  return l;
}
 
int main(){
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
 
  stacks[0] = arr[0];
  nS++;
  for (int i = 1; i < n; i++){
    if (arr[i] >= stacks[nS-1]){
      stacks[nS] = arr[i];
      nS++;
    } else {
      ins = bs(arr[i]);
      if (stacks[ins] == arr[i]) ins++;
      stacks[ins] = arr[i];
    }
  }
 
  cout << nS << "\n";
 
  return 0;
}