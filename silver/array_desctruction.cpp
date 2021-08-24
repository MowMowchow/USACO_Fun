#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec1i;
typedef vector<vector<int>> vec2i;
typedef vector<vector<vector<int>>> vec3i;
typedef vector<ll> vec1ll;
typedef vector<vector<ll>> vec2ll;
typedef vector<vector<vector<ll>>> vec3ll;

int T, N, UN, SN, arr[2010], x; 
map<int, int> vis;
vec1i nums, sums;
vec2i moves;
bool bad;

int main(){
  cin >> T;

  while (T--){
    memset(arr, 0, sizeof(arr));
    nums.clear();
    sums.clear();
    vis.clear();
    bad = true;
    cin >> N; N *= 2;
    for (int i = 0; i < N; i++){
      cin >> arr[i];
      if (!vis[arr[i]]) nums.push_back(arr[i]);
      vis[arr[i]]++;
    }

    UN = nums.size();
    sort(nums.begin(), nums.end());
    sort(arr, arr+N);

    for (int i = 0; i < N-1; i++)
      sums.push_back(arr[i]+arr[N-1]);

    SN = sums.size();
    for (auto s: sums){
      bool attempt = true;
      moves.clear();
      map<int, int> visT = vis;
      x = s;
      for (int i = UN-1; i >= 0; i--){
        while (visT[nums[i]]){  
          if (visT[x-nums[i]]){ 
            if (x-nums[i] == nums[i]){ 
              if (visT[nums[i]] >= 2){ 
                visT[nums[i]] -= 2;
                moves.push_back({nums[i], nums[i]});
                x = nums[i];
              } else {
                attempt = false;
                break;
              }
            } else { 
                visT[x-nums[i]]--;
                visT[nums[i]]--;
                moves.push_back({x-nums[i], nums[i]});
                x = max(nums[i], x-nums[i]);
            }
          } else {
              attempt = false;
              break;
            }
        }
      }
      if (attempt){
        bad = false;
        break;
      }
    }
    if (!bad){
      cout << "YES\n" << moves[0][0]+moves[0][1] << "\n";
      for (auto move: moves) cout << move[0] << " " << move[1] << "\n";
    } else cout << "NO\n";
  }
  return 0;
}