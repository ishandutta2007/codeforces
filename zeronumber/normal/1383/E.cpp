#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
typedef long long ll;
const int maxn=1e6+10;
bool f1,f2;
int a[maxn],n,m,b[maxn],sum[maxn],pos[maxn],dp[maxn];
char s[maxn];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
int qry(int x){
    int ret=0;
    while (x<maxn){
        ret=max(ret,b[x]);
        x+=x&(-x);
    }
    return ret;
}
void modify(int x,int y){
    while (x){
        b[x]=max(b[x],y);
        x-=x&(-x);
    }
}
int main(){
    scanf("%s",s+1);
    m=strlen(s+1);
    for (int i=1;i<=m;i++) if (s[i]=='1') pos[++n]=i;
    for (int i=1;i<=n;i++) a[i]=pos[i]-pos[i-1]-1;
    if (n==0){cout<<m<<endl;return 0;}
    a[n+1]=m-pos[n]; ++n;
    int res=1ll*(a[1]+1)*(a[n]+1)%M;
    n--;
    for (int i=1;i<n;i++) a[i]=a[i+1];
    n--;
    dp[0]=1; sum[0]=1;
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for (int j=1;j<=a[i];j++){
            int x=qry(j);
            //cout<<i<<' '<<j<<' '<<x<<endl;
            add(dp[i],sum[i-1]);
            if (x>0) sub(dp[i],sum[x-1]);
        }
        sum[i]=sum[i-1];
        add(sum[i],dp[i]);
        modify(a[i],i);
        //cout<<i<<' '<<dp[i]<<endl;
    }
    printf("%lld\n",1ll*sum[n]*res%M);
    return 0;
}