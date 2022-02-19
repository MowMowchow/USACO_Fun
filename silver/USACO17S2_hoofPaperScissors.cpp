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

int N, final = 0, H[100100], P[100100], S[100100];
string a;

int main(){
	setIO("hps");
	memset(H, 0, sizeof(H));
	memset(P, 0, sizeof(P));
	memset(S, 0, sizeof(S));

	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> a;
		if (a == "P") H[i]++;
		else if (a == "S") P[i]++;	
		else S[i]++;
	}
  
	for (int i = 1; i <= N; i++) {
		H[i] += H[i-1];
		S[i] += S[i-1];
		P[i] += P[i-1];
	}

	for (int i = 1; i < N; i++){
		final = max(final, max(H[i], max(S[i], P[i])) + max(H[N]-H[i], max(S[N]-S[i], P[N]-P[i])));
	}

	cout << final << "\n";

  return 0;
}
