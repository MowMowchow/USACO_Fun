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

ll N, a, rs[7], r, curr, c, final = 0;

int main(){
	setIO("div7");
	memset(rs, -1, sizeof(rs));

	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> curr;
		r = (r+curr)%7;

		if (rs[r] == -1){
			rs[r] = i;
		} else {
			final = max(final, i-rs[r]);
		}
	}

	cout << final << "\n";

  return 0;
}