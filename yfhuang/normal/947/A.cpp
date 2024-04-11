#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

const int maxn = 1e6 + 5;
int ans[maxn];
bool prime[maxn];
int suf[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(ans, 0x3f, sizeof(ans));
    for(int i = 2;i < maxn;i++){
        if(!prime[i]){
            for(int j = i * 2;j < maxn;j += i){
                prime[j] = 1;
                ans[j] = min(ans[j], (j / i - 1) * i + 1);
            }
        }
    }
    cin >> n;
    suf[n] = ans[n];
    for(int i = n - 1;i >= 1;i--){
        suf[i] = min(suf[i + 1], ans[i]);
    }
    int tmp = n;
    int res = 1e9;
    for(int i = 2;i * i <= tmp;i++){
        if(tmp % i == 0){
            while(tmp % i == 0){
                tmp /= i;
            }
            res = min(res, suf[n - i + 1]);
        }
    }
    if(tmp > 1){
        res = min(res, suf[n - tmp + 1]);
    }
    cout << res << endl;
    return 0;
}