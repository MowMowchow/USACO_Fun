#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, Q, a, b, arr1[100100], arr2[100100], arr3[100100];

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
  setIO("bcount");

  cin >> N >> Q;
  memset(arr1, 0, sizeof(arr1));
  memset(arr2, 0, sizeof(arr1));
  memset(arr3, 0, sizeof(arr1));

  for (int i = 1; i <= N; i++){
    cin >> a;
    if (a == 1){
      arr1[i]++;
    } else if (a == 2) {
      arr2[i]++;
    } else {
      arr3[i]++;
    }
  }

  for (int i = 1; i <= N; i++) {
    arr1[i] += arr1[i-1];
    arr2[i] += arr2[i-1];
    arr3[i] += arr3[i-1];
  }

  for (int i = 0; i < Q; i++){
    cin >> a >> b;
    cout << arr1[b]-arr1[a-1] << " " << arr2[b]-arr2[a-1] << " " << arr3[b]-arr3[a-1] << "\n";
  }

  return 0;
}
