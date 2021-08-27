#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


// keep track of largest gap for each height of snow 
// have a map with the key beiing the depth of the snow and then 
// first item being the max thus far and then next two being left and right 
// when doing a left keep r as -1 until you reach the next one of the same depth
// iterate over the map at the very end and check for the ones that still have -1 as the right and adjust accordingly

int main(){
	// setIO("snowboots");

  return 0;
}