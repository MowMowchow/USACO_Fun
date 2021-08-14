#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

ll N, a, b, ans[200010], last = 0;
priority_queue<vec1ll, vec2ll, greater<vec1ll>> q;
vec2ll customers;
int final = -1;

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> b;
    customers.push_back({a, b, i+1});
  }
  sort(customers.begin(), customers.end());

  for (int i = 0; i < N; i++){
    if (q.empty()){
      last++;
      q.push({customers[i][1], last});
      ans[customers[i][2]] = last;
    } else {
      ll temp;
      if (q.top()[0] < customers[i][0]){
        temp = q.top()[1];
        q.pop();
        q.push({customers[i][1], temp});
        ans[customers[i][2]] = temp;
      } else {
        last++;
        q.push({customers[i][1], last});
        ans[customers[i][2]] = last;
      }
    }
    final = max(final, (int) q.size());
  }

  cout << final << "\n";
  for (int i = 1; i <= N; i++) cout << ans[i] << " "; cout << "\n";

  return 0;
}