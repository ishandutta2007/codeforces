#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int cnt[maxn];
int n, m;
int a[maxn];
typedef long long LL;
LL qpow(LL a, LL n){
    LL ret = 1;
    while(n > 0){
        if(n & 1){
            ret = ret * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return ret;
} 
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i] % m]++;
    }
    bool flag = false;
    for(int i = 0;i < m;i++){
        if(cnt[i] > 1)
            flag = true;
    }
    LL ans;
    if(!flag)
        ans = 1;
    else
        ans = 0;
    if(ans == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            ans = ans * (a[j] - a[i]) % m;
        }
    }
    cout << ans << endl;
    return 0;
}