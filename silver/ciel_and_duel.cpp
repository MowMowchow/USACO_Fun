#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, M, arr[110], a, ans = 0, ans2 = 0;
string s;
vector<int> atk, def;
vector<vector<int>> all;
deque<int> d;
unordered_map<int, int> used;


int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s >> a;
    if (s == "ATK") atk.push_back(a);
    else def.push_back(a);
    all.push_back({a, s == "ATK" ? 1 : 0});
  }
  for (int i = 0; i < M; i++){
    cin >> a;
    arr[i] = a;
    d.push_back(a);
  }

  sort(arr, arr+M);
  sort(d.begin(), d.end());
  sort(atk.begin(), atk.end());
  sort(def.begin(), def.end());
  sort(all.begin(), all.end());

  int beatAtk = 0, beatAtk2 = 0, beatDef = 0, beatDef2 = 0, Na = atk.size(), Nd = def.size();
  for (int i = M-1; i >= 0 && beatAtk < Na; i--){
    if (arr[i] >= atk[beatAtk]){
      ans += arr[i]-atk[beatAtk];
      beatAtk++;
    }
  }

  int beatAll = 0;
  for (int i = 0; i < M; i++){
    if (beatAll == N) break;
    else {
      if (all[beatAll][1]){
        if (all[beatAll][0] <= arr[i]){
          beatAll++;
        }
      }
      else {
        if (all[beatAll][0] < arr[i]){
          beatAll++;
        }
      }
    }
  }

  if (beatAll >= N){
    beatAll = 0;
    for (int i = 0; i < M && beatAll < Nd; i++){
      if (arr[i] > def[beatAll]){
        used[i]++;
        beatAll++;
      }
    }
    beatAll = 0;
    for (int i = 0; i < M && beatAll < Na; i++){
      if (arr[i] >= atk[beatAll] && !used[i]){
        ans2 += arr[i]-atk[beatAll];
        used[i]++;
        beatAll++;
      }
    }
    if (beatAll == Na) for(int i = 0; i < M; i++) if (!used[i]) ans2 += arr[i];
  }

  cout << max(ans, ans2) << "\n";

  return 0;
}