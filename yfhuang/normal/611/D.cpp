#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MOD=1e9+7;

void  add(int &a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

const int N=5000+16;

char s[N];
int f[N][N];
int dp[N][N];

bool smaller(int i,int j,int len){
    if(f[i][j]>=len) return false;
    return s[i+f[i][j]]<s[j+f[i][j]];
}

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=n;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(i==n&&j==n) f[i][j]=0;
            else if(s[i]==s[j]) f[i][j]=f[i+1][j+1]+1;
            else f[i][j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            if(i==0) dp[i][j]=1;
            else{
                if(s[i]=='0'){
                    dp[i][j]=0;
                }
                else{
                    int len = j - i + 1;
                    bool added = false;
                    if (i - len >= 0 && smaller(i - len, i, len)) {
                        add(sum, dp[i - len][i - 1]);
                        added = true;
                    }
                    dp[i][j] = sum;
                    if (i - len >= 0 && !added) {
                        add(sum, dp[i - len][i - 1]);
                    }
                }
            }
        if(j==n-1) add(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}