#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long n, k;
        cin >> n >> k;
        long long ans = 0;
        while(n > 0){
            if(n % k == 0){
                n /= k;
                ans++;
            }else{
                ans += n % k;
                n = n - (n % k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}