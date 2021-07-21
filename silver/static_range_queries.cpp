#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

int N, Q, arr[100010], v;
ll l, r;
vec2ll updates;
vec2ll queries;
vec1ll ogCoors;
map<ll, bool> registered;
map<ll, int> lCoors, rCoors, coorMap;

int main(){
  cin >> N >> Q;
  memset(arr, 0, sizeof(arr));

  for (int i = 0; i < N; i++){
    cin >> l >> r >> v;
    updates.push_back({l, r, v});
    if (registered.find(l) == registered.end()){
      registered[l] = true;
      ogCoors.push_back(l);
    }
    if (registered.find(r) == registered.end()){
      registered[r] = true;
      ogCoors.push_back(r);
    }
  }

  for (int i = 0; i < Q; i++){
    cin >> l >> r;
    queries.push_back({l, r});
    if (registered.find(l) == registered.end()){
      registered[l] = true;
      ogCoors.push_back(l);
    }
    if (registered.find(r) == registered.end()){
      registered[r] = true;
      ogCoors.push_back(r);
    }
  }

  // sort(updates.begin(), updates.end());
  sort(ogCoors.begin(), ogCoors.end());

  for (int i = 0; i < ogCoors.size(); i++){
    coorMap[ogCoors[i]] = i;
  }

  // for (int i = 1; i <= N; i++){
  //   lCoors[updates[i-1][0]] = i;
  //   updates[i-1][0] = i;
  // }
  
  // sort(updates.begin(), updates.end(), [](const vec1ll&v1, const vec1ll&v2){return v1[1] < v2[1];});

  // for (int i = 1; i <= N; i++){
  //   rCoors[updates[i-1][1]] = i ;
  //   updates[i-1][1] = i;
  // }

  cout << "\n";
  for (auto q: updates){
    arr[coorMap[q[0]]]+=q[2];
    arr[coorMap[q[1]+1]]-=q[2];
    cout << "adding: " << q[2] << " to the range l: " << coorMap[q[0]] << " and r: " << coorMap[q[1]] << "\n";  
  }
  cout << "\narr: ";
  for (int i = 0; i <= ogCoors.size(); i++){
    cout << arr[i] << " ";
  } cout << "\n";

  for (int i = 1; i <= ogCoors.size(); i++) arr[i] += arr[i-1];

  cout << "\narr: ";
  for (int i = 0; i <= ogCoors.size(); i++){
    cout << arr[i] << " ";
  } cout << "\n";

  for (int i = 1; i <= ogCoors.size(); i++) arr[i] += arr[i-1];


  cout << "ogCoors: ";
  for (auto coor: ogCoors){
    cout << coor << " -> " << coorMap[coor] << ", ";
  }

  for (int i = 0; i < Q; i++){
    cout << "\nquery l: " << coorMap[queries[i][0]] << " r: " << coorMap[queries[i][1]] << " | " << arr[coorMap[queries[i][1]]] << " - " << arr[coorMap[queries[i][0]]] << "\n";
    cout << arr[coorMap[queries[i][1]]]-arr[coorMap[queries[i][0]]-1] << "\n";
  }

  return 0;
}