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

int N, elsie[50010], bessie[50010], lag = 0, ans = 0;
map<int, int> elsieMap;
map<int, int> bessieMap;


int main(){
	setIO("cardgame");
  memset(bessie, 0, sizeof(bessie));

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> elsie[i];
    elsieMap[elsie[i]]++;
  }
  for (int i = 1; i <= N*2; i++) {
    if (!elsieMap[i]){
      bessieMap[i]++;
      bessie[lag] = i;
      lag++;
    }
  }

  int firstHalf[N/2], secondHalf[N/2];

  for (int i = 0; i < N/2; i++){
    firstHalf[i] = elsie[i];
    secondHalf[i] = elsie[i+N/2];
  }

  sort(firstHalf, firstHalf+N/2);
  sort(secondHalf, secondHalf+N/2);

  for (int i = N/2-1; i >= 0; i--) {
    if (firstHalf[i] < bessieMap.rbegin()->first) {
      ans++;
      bessieMap.erase(bessieMap.rbegin()->first);
    }
  }

  for (int i = 0; i < N/2; i++){
    if (secondHalf[i] > bessieMap.begin()->first){
      ans++;
      bessieMap.erase(bessieMap.begin()->first);
    }
  }

  cout << ans << "\n";

  return 0;
}