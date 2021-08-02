    #include <bits/stdc++.h>
    typedef long long ll;
     
    using namespace std;
     
    ll N, T, l = 0, r = 0, arr[100010], csum = 0, books = 0, final = 0;
     
    int main(){
      cin >> N >> T;
     
      for (int i = 0; i < N; i++){
        cin >> arr[i];
      }
     
      while (l <= r) {
        if (arr[r] > T && r < N-1){
          r++; l = r;
          csum = 0; books = 0;
        } else {
          if (csum + arr[r] <= T) {
            csum += arr[r];
            books++;
            r++;
            final = max(final, books);
            if (r == N){
              break;
            }
          } else {
            csum -= arr[l];
            books--;
            l++;
          }
        }
      }
     
      cout << final << "\n";
      return 0;
    }