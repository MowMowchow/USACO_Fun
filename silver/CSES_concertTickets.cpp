#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

multiset<ll> tickets, maxes;
int N, M;
ll a;

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    cin >> a;
    tickets.insert(a);
  }
  for (int i = 0; i < M; i++){
    cin >> a;
    auto temp = tickets.upper_bound(a);
    if (temp != tickets.begin()){
      temp--;
      cout << *temp << "\n";
      tickets.erase(temp);
    } else cout << "-1\n";
  }
  return 0;
}