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

// ylmax: max y from left | yrmax: max y from left | ylmin, yrmin
// xumax: max x from up | xdmax: max x from down | xumin, xdmin
ll N, x, y, sy, sx, total, final = LONG_LONG_MAX;
ll ylmax[50010], yrmax[50010], ylmin[50010], yrmin[50010], xumax[50010], xdmax[50010], xumin[50010], xdmin[50010];
vec2ll coors;

int main(){
	setIO("split");

	cin >> N;

	memset(ylmax, 0, sizeof(ylmax));
	memset(yrmax, 0, sizeof(yrmax));
	memset(xumax, 0, sizeof(xumax));
	memset(xdmax, 0, sizeof(xdmax));

	for (int i = 0; i < N; i++){
		cin >> x >> y;
		coors.push_back({x, y});
	}

	for (int i = 0; i <= N+2; i++){
		ylmin[i] = LONG_LONG_MAX;
		yrmin[i] = LONG_LONG_MAX;
		xumin[i] = LONG_LONG_MAX;
		xdmin[i] = LONG_LONG_MAX;
	}

	sort(coors.begin(), coors.end());

	for (int i = 1; i <= N; i++){
		ylmax[i] = max(ylmax[i-1], coors[i-1][1]);
		ylmin[i] = min(ylmin[i-1], coors[i-1][1]);
	}
	for (int i = N; i > 0; i--){
		yrmax[i] = max(yrmax[i+1], coors[i-1][1]);
		yrmin[i] = min(yrmin[i+1], coors[i-1][1]);
	}

	sort(coors.begin(), coors.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[1] < v2[1];});

	for (int i = 1; i <= N; i++){
		xdmax[i] = max(xdmax[i-1], coors[i-1][0]);
		xdmin[i] = min(xdmin[i-1], coors[i-1][0]);
	}

	for (int i = N; i > 0; i--){
		xumax[i] = max(xumax[i+1], coors[i-1][0]);
		xumin[i] = min(xumin[i+1], coors[i-1][0]);
	}

	sy = coors[0][1];
	for (int i = 1; i < N; i++){
		final = min(final, (xdmax[i]-xdmin[i])*(coors[i-1][1]-sy) + (xumax[i+1]-xumin[i+1])*(coors[N-1][1]-coors[i][1]));
	}

	sort(coors.begin(), coors.end());

	sx = coors[0][0];	
	for (int i = 1; i < N; i++){
		final = min(final, (ylmax[i]-ylmin[i])*(coors[i-1][0]-sx) + (yrmax[i+1]-yrmin[i+1])*(coors[N-1][0]-coors[i][0]));
	}
	
	total = (ylmax[N]-ylmin[N])*(xdmax[N]-xdmin[N]);
	cout << total-final << "\n"; 
  return 0;
}