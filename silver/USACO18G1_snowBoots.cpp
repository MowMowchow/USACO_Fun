#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

int N, B, snow[100010], d, r;
vector<vector<int>> boots;
bool cR[100010];

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


int bs(){
	int l = 0, r = B;

	while (l <= r){
		int mid = l+((r-l)/2);
	}
}


int main(){
	// setIO("snowboots");
	cin >> N >> B;

	for (int i = 0; i < N; i++) cin >> snow[i];

	for (int i = 0; i < B; i++){
		cin >> d >> r;
		boots.push_back({d, r});
	}

	sort(boots.begin(), boots.end()+B);




  return 0;
}