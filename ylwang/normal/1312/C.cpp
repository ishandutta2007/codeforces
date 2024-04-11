#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;
const long long inf = 1e16 + 10;

long long T , n , k , cnt , a[N] , vis[N] , fac[N];

int main(){
    scanf("%lld" , &T); while(T--){
        memset(vis , 0 , sizeof(vis));
        scanf("%lld %lld" , &n , &k);
        fac[0] = 1; for(int i = 1; fac[i - 1] < inf; i++)
            fac[i] = fac[i - 1] * k , cnt = i;
        for(int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
        for(int i = 1; i <= n; i++){
            int j = 0; while(a[i]){
                vis[j] += a[i] % k;
                a[i] /= k , j++;
            }
        }
        bool flag = false;
        for(int i = 0; i <= cnt; i++)
            if(vis[i] > 1) flag = true;
        flag ? puts("NO") : puts("YES");
    }
    return 0;
}