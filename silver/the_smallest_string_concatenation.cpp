#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int> > vec2i;
typedef vector<vector<vector<int> > > vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll> > vec2ll;
typedef vector<vector<vector<ll> > > vec3ll;

vector<string> arr;
int N;
string out;

int main(){
  cin >> N;
  while (N--){
    cin >> out;
    arr.push_back(out);
  }
  sort(arr.begin(), arr.end(), [](const string&a, const string&b){return a+b < b+a;});
  out = "";
  for (auto s: arr) out += s;
  cout << out << "\n";
  return 0;
}