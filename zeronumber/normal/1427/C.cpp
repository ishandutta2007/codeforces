#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int dp[maxn],mx[maxn],x[maxn],y[maxn],t[maxn],n,r;
bool check(int p,int q){
    return abs(x[p]-x[q])+abs(y[p]-y[q])<=t[q]-t[p];
}
int main(){
    cin >> r >> n; x[0]=y[0]=1;
    for (int i=1;i<=n;i++) scanf("%d%d%d",&t[i],&x[i],&y[i]);
    for (int i=1;i<=n;i++){
        dp[i]=-n;
        if (i<r*2){
            for (int j=1;j<=i;j++)
                if (check(i-j,i)) dp[i]=max(dp[i],dp[i-j]+1);
        } else {
            dp[i]=mx[i-r*2]+1;
            for (int j=1;j<r*2;j++)
                if (check(i-j,i)) dp[i]=max(dp[i],dp[i-j]+1);
        }
        mx[i]=max(mx[i-1],dp[i]);
    }
    printf("%d\n",mx[n]);
}