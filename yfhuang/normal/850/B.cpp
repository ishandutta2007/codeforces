#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include <vector>
using namespace std;

const int maxn = 5e5 + 5;

typedef long long LL;

int n;
LL x,y;
int a[maxn];
int num[maxn * 4];
int pre[maxn * 4];
bool vis[maxn * 4];
LL pos[maxn * 4];
LL ppos[maxn * 4];

int main(){
    cin >> n >> x >> y;
    int num1 = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        num[a[i]] ++;
        pos[a[i]] += a[i];
        if(a[i] == 1) num1++;
    }
    if(num1 == n){
        cout << 1LL * n * min(x,y) << endl;
        return 0;
    }
    for(int i = 1;i <= 2000000;i++){
        pre[i] = num[i] + pre[i - 1];
        ppos[i] = pos[i] + ppos[i - 1];
    }
    //cout << ppos[17] << endl;
    LL t = x / y;
    LL ans = x * (n - 1);
    for(int i = 2;i <= 2000000;i++){
        if(vis[i]) continue;
        long long ret = 0;
        for(int j = 2 * i;j <= 2000000;j += i) vis[j] = 1;
        for(int j = i;j <= 2000000;j += i){
            int len = i;
            int l = max(j - len,(int)(j - t - 1));
            LL xx = 1LL * (pre[j] - pre[l]) * j - (ppos[j] - ppos[l]);
            if(xx > ans / y){
                ret = ans + 1;
                break;
            }
            ret += (1LL * (pre[j] - pre[l]) * j - (ppos[j] - ppos[l])) * y;
            ret += (1LL * (pre[l] - pre[j - len]) * x);
            if(ret > ans) break;
        }
        //  if(i == 17) cout << ret << endl;
        ans = min(ans,ret);
    }
    cout << ans << endl;
    return 0;
}