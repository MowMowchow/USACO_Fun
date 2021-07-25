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

ll N, M, R, a, b, bArr[100010], final = 0, rent[100010];
vec1ll cows;
deque<vec1ll> buy;

int main(){
	setIO("rental");

  memset(bArr, 0, sizeof(bArr));
  memset(rent, 0, sizeof(rent));

  cin >> N >> M >> R;
  for (int i = 0; i < N; i++){
    cin >> a;
    cows.push_back(a);
  }
  for (int i = 0; i < M; i++){
    cin >> a >> b;
    buy.push_back({a, b});
  }
  for (int i = 0; i < R; i++){
    cin >> rent[i];
  }

  sort(cows.begin(), cows.end(), [](const ll&x, const ll&y){return x > y;});
  sort(rent, rent + R);
  sort(buy.begin(), buy.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[1] > v2[1];});

  for (int i = R-2; i >= 0; i--) rent[i] += rent[i+1];
  
  for (int i = 1; i <= N; i++){
    while (cows[i-1] <= 0 || !buy.empty()){
      if (cows[i-1] >= buy[0][0]){ // bought all
        cows[i-1] -= buy[0][0];
        bArr[i] += buy[0][0]*buy[0][1];
        buy.pop_front();
      } else if (cows[i-1] < buy[0][0]){
        buy[0][0] -= cows[i-1];
        bArr[i] += cows[i-1]*buy[0][1];
        break;
      } 
      if (cows[i-1] <= 0) break;
    }
    bArr[i] += bArr[i-1];
  }

  int diff = max(N-R, (ll) 0);

  // cout << "~~~~~~~~~~~~~~~~~~~~~\n";

  // for (int i = 0; i <= N; i++) cout << bArr[i] << " "; cout << "\n";
  // for (int i = 0; i <= N; i++) cout << rent[i] << " "; cout << "\n";
  
  for (int i = 0; i <= N; i++)
    if (i >= diff) bArr[i] += rent[i-diff];


  for (int i = 0; i <= N; i++) final = max(final, bArr[i]);
  
  // for (int i = 0; i <= N; i++) cout << bArr[i] << " "; cout << "\n";



  cout << final << "\n";

  return 0;
}