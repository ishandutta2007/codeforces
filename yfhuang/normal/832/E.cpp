#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

int md5[30];
const int maxn = 505;
const int mod = 1e9 + 7;
char s[maxn];
int b[maxn],a[maxn][maxn];
int n,m,q;
int inv[5] = {0,1,3,2,4};
int main(){
    {
        cin >> n >> m;
        int cnt = 0;
        for(int i = 0;i < 30;i++) md5[i] = i % 5;
        for(int i = 0;i < n;i++){
            scanf("%s",s);
            for(int j = 0;j < m;j++) b[j] = s[j] - 'a';
            for(int j = 0;j < cnt;j++){
                for(int k = 0;k < m;k++) if(a[j][k]){
                        int t = md5[b[k] * inv[a[j][k]]];
                        for(int l = 0;l < m;l++)
                            b[l] = md5[b[l] - md5[t * a[j][l]] + 5];
                        break;
                    }
            }
            bool flag = 0;
            for(int j = 0;j < m;j++) flag |= (b[j] > 0);
            if(flag){
                for(int j = 0;j < m;j++) a[cnt][j] = b[j];
                cnt++;

            }
        }
        cin >> q;
        int ans = 1;
        for(int i = 0;i < n - cnt;i++){
            ans = 5LL * ans % mod;
        }
        for(int i = 1;i <= q;i++){
            scanf("%s",s);
            for(int j = 0;j < m;j++) b[j] = s[j] - 'a';
            for(int j = 0;j < cnt;j++){
                    for(int k = 0;k < m;k++) if(a[j][k]){
                            int t = md5[b[k] * inv[a[j][k]]];
                            for(int l = 0;l < m;l++)
                                b[l] = md5[b[l] - md5[t * a[j][l]] + 5];

                            break;
                        }
            }
            bool flag = 0;
            for(int j = 0;j < m;j++) flag |= (b[j] > 0);
            if(flag) printf("0\n");
            else printf("%d\n",ans);
        }
    }

    return 0;
}