#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

ll T, h, w, N, ans[200010];
vec2ll ppl1, ppl2 ;

int bs(ll x){
  int l = 0, r = N-1, mid, ans = -1;
  while (l <= r){
    mid = l+(r-l)/2;
    if (ppl2[mid][0] >= x) l = mid+1;
    else{
      ans = mid;
      r = mid-1;
    }
  }
  return ans;
}

int main(){
  cin >> T;
  while (T--){
    cin >> N;
    
    memset(ans, 0, sizeof(ans));
    ppl1.clear();
    ppl2.clear();

    for (int i = 1; i <= N; i++){
      cin >> h >> w;
      ppl1.push_back({h, w, i, 0, 0});  // h, w, ind, min w, ind for min w, 
      ppl2.push_back({w, h, i, 0, 0});  // w, h, ind, min h, ind for min h, 
    }

    sort(ppl1.begin(), ppl1.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0]==v2[0]?v1[1]<v2[1]:v1[0]>v2[0];});
    sort(ppl2.begin(), ppl2.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[0]==v2[0]?v1[1]<v2[1]:v1[0]>v2[0];});

    ppl1[N-1][3] = ppl1[N-1][1];
    ppl1[N-1][4] = ppl1[N-1][2];
    for (int i = N-2; i >= 0; i--){ 
      ppl1[i][3] = ppl1[i+1][3];
      ppl1[i][4] = ppl1[i+1][4];
      if (ppl1[i][1] < ppl1[i][3]){
        ppl1[i][3] = ppl1[i][1];
        ppl1[i][4] = ppl1[i][2];
      }
    }

    for (int i = 0; i < N; i++) ans[ppl1[i][2]-1] = ppl1[i][1] > ppl1[i][3] ? ppl1[i][4] : -1;

    //cout << "!!!!\n";
    //for (auto t: ppl1) cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << " " << t[4] << "\n";
    //cout << "!!!!\n";
    
  
    
    ppl2[N-1][3] = ppl2[N-1][1];
    ppl2[N-1][4] = ppl2[N-1][2];
    for (int i = N-2; i >= 0; i--){ 
      ppl2[i][3] = ppl2[i+1][3];
      ppl2[i][4] = ppl2[i+1][4];
      if (ppl2[i][1] < ppl2[i][3]){
        ppl2[i][3] = ppl2[i][1];
        ppl2[i][4] = ppl2[i][2];
      }
    }
  
    // cout << "!!!!\n";
    // for (auto t: ppl2) cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << " " << t[4] << "\n";
    // cout << "!!!!\n";

    // cout << "bs for: " << 3 << " gives index: " << bs(3) << "\n"; 
    for (int i = 0; i < N; i++) 
      if (ans[ppl2[i][2]-1] == -1)
      
        ans[ppl2[i][2]-1] = ppl1[i][1] > ppl2[bs(ppl1[i][0])][3] ? ppl2[i][4] : -1;

    for (int i = 0; i < N; i++) cout << ans[i] << " "; cout << "\n";
  }
  return 0;
}