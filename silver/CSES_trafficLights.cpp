#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

multiset<ll> coors, spaces;
ll X, N, a;

int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  cin >> X >> N;
  coors.insert(0); coors.insert(X);
  spaces.insert(X);
  for (int i = 0; i < N; i++){
    cin >> a;
    auto t1 = coors.upper_bound(a), t2 = coors.lower_bound(a);
    t1--; 
    ll tempSpace = *t2-*t1;
    spaces.erase(spaces.find(tempSpace));
    spaces.insert(a-(*t1)); spaces.insert(*t2-a);
    auto tempAns = spaces.end();
    cout << *(--tempAns) << " "; 
    coors.insert(a);
  } cout << "\n";
  return 0;
}