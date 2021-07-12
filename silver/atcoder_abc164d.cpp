#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, total = 0, rs[2019], r = 0, pwr = 1;
string S;

int main(){
  cin >> S; N = S.size();

  memset(rs, 0, sizeof(rs));
  rs[0]++;
  
  for (int i = N-1; i >= 0; i--){
    r = (((S[i]-'0')*pwr)+r) % 2019;
    pwr = (pwr*10) % 2019; 
    rs[r]++;
  }

  for (int i = 0; i < 2019; i++){
    total += (rs[i]*(rs[i]-1))/2;
  }

  cout << total << "\n";

  return 0;
}