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

int N, a, low = 0, high, l, r;
vec1i arr;

int main(){
	setIO("herding");
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	high = (arr[N-1]-arr[0])-min(arr[N-1]-arr[N-2], arr[1]-arr[0])-(N-2);

	l = 0, r = 0;
	if (arr[N-1]-arr[1] == N-2 && arr[1]-arr[0] > 2 || arr[N-2]-arr[0] == N-2 && arr[N-1]-arr[N-2] > 2)	low = N-2;
	else  
		while (l < N){
			if (r < N && arr[r]-arr[l] < N){
				low = max(low, (r-l)+1);
				r++;
			} else l++;
		}

	if (low == 0) low = N;

	cout << N-low << "\n" << high << "\n";

  return 0;
}