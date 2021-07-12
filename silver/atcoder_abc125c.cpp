#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll N, arr[200010], l[200010], r[200010], final = 0;

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));

  l[0] = arr[0];
  r[N-1] = arr[N-1];

  for (int i = 1; i < N; i++) l[i] = gcd(l[i-1], arr[i]);
  for (int i = N-2; i >= 0; i--) r[i] = gcd(r[i+1], arr[i]);

  for (int i = 1; i <= N-1; i++) final = max(final, gcd(l[i-1], r[i+1]));

  final = max(final, max(l[N-1], r[1]));  

  cout << final << "\n";

  return 0;
}