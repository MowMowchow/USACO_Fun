#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, NS = 0, NC, M, Q, usage, curr, rep, k, l, r, ans;
map<char, int> letMap;
vector<char> letters;
vec3i pre;
string S;
char C;


int solve(int m, char c){
  k = letMap[c]-1;
  NC = pre[k].size();
  l = 0; r = 0; curr = pre[k][0][0]; usage = pre[k][0][1]; ans = 0;

  while (l < NC && r < NC){
    if (usage <= m){
      ans = max(ans, curr+(0 < l ? 1 : 0)+(usage > 0 || pre[k][r][1] == 0 ? m-usage : 0));
      r++;
      if (r == NC) break;
      usage += pre[k][r][1];
      curr += pre[k][r][0];
    } else {
      usage -= pre[k][l][1];
      curr -= pre[k][l][0];
      l++;
    }
  }
  return min(max(ans, m+(NC > 0 ? 1 : 0)), N);
}


int main(){

  cin >> N >> S >> Q;
  
  for (int i = 0; i < N; i++) {
    if (!letMap[S[i]]){
      letMap[S[i]] = NS+1;
      letters.push_back(S[i]);
      NS++;
      vec2i temp;
      pre.push_back(temp);
    }
  }

  for (int i = 0; i < NS; i++){
    curr = 0; rep = 0;
    for (int j = 0; j < N; j++){
      if (letters[i] == S[j]){
        if (curr > 0) pre[i].push_back({curr+1, curr});
        else {
          rep++;
          if (j+1 > N-1 || (j < N && S[j+1] != S[j])){
            pre[i].push_back({rep, 0});
            rep = 0;
          }
        }
        curr = 0;
      } else curr++;
      if (j == N-1 && curr > 0) pre[i].push_back({curr, curr});
    }
  }
  
  for (int i = 0; i < Q; i++){
    cin >> M >> C;
    if (letMap[C]) cout << solve(M, C) << "\n";
    else cout << M << "\n";
  }

 return 0;
}