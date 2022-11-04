#include<bits/stdc++.h>
using namespace std;
#define QC 1000000007
int dp[30][5005];
char s[5005];
long long ans;
int main(){
    int n,temp;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        temp=s[i]-'a'+1;
        ans=1;
        for(int j=1;j<=n;j++){
            dp[0][j]=(dp[0][j]-dp[temp][j]+QC)%QC;
            dp[temp][j]=ans;
            ans=(ans+dp[0][j])%QC;
            dp[0][j]=(dp[0][j]+dp[temp][j])%QC;
        }
    }
    printf("%d\n",dp[0][n]);
}