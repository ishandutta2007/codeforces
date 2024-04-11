#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[2][100002];
ll num[100002];
ll a[100002];
void init() {
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
    memset(a,0,sizeof(a));
}
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        init();
        for (int x=0;n>x;x++) {
            int i;
            scanf("%d",&i);
            num[i]++; 
        }
        for (int x=0;100002>x;x++) {
            a[x] = x * num[x];
        }
        //cout << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
        dp[0][1] = a[1];
        dp[1][1] = 0;
        for (int i=2;100002>i;i++) {
            for (int j=0;2>j;j++) {
                if (i==2 && j==0) {
                    dp[0][2] = max(a[2],dp[1][1]);
                }
                else if (j==0) {
                    dp[j][i] = max(dp[1][i-2]+a[i],dp[1][i-1]+a[i]);
                }
                else if (j==1){
                    dp[j][i] = max(dp[0][i-1],dp[1][i-1]);
                }
            }
        }
        /*for (int x=0;2>x;x++) {
            for (int y=0;n>=y;y++) {
                cout << dp[x][y] << ' ';
            }
            cout << endl;
        }*/
        printf("%I64d\n",max(dp[0][100001],dp[1][100001]));
    }
}