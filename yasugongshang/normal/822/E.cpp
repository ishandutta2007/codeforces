#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')  positive = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
        a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=200005;
int dp[N][105],n,m,x,ff[N][25];
int tong[N],SA[N],height[N],rk[N],logn[N];
char ch[N],a[N],b[N];
#define cmp(a,b,k) y[a]==y[b]&&y[a+k]==y[b+k]
inline int lcp(int l,int r){
	int tt=n-l+1;
	r+=n;
	if(l==r)return n-l+1;
	l=rk[l]; r=rk[r];
	if(l>r)swap(l,r); r--;
	int t=logn[r-l+1];
	//cout<<tt<<endl;
	//for(int i=l;i<=r;i++)cout<<height[i]<<" "; puts("");
	//cout<<r<<" "<<t<<" "<<l+(1<<t)-1<<" "<<l<<" "<<ff[r][t]<<" "<<ff[l+(1<<t)-1][t]<<endl;
	return min(tt,min(ff[r][t],ff[l+(1<<t)-1][t]));
}
void solve(){
	for(int i=1;i<=n;i++)ch[i]=a[i];
	for(int i=1;i<=m;i++)ch[n+i]=b[i];
	//cout<<(a+1)<<(b+1)<<" "<<(ch+1)<<" "<<n<<endl;
	n+=m;
    int m=150; 
    static int x[N],y[N];
    memset(tong,0,sizeof(tong)); memset(height,0,sizeof(height));
    for(int i=1;i<=n;i++)tong[x[i]=ch[i]]++;
    for(int i=1;i<=m;i++)tong[i]+=tong[i-1];
    for(int i=n;i;i--)SA[tong[x[i]]--]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k+1;i<=n;i++)y[++p]=i;
        for(int i=1;i<=n;i++)if(SA[i]>k)y[++p]=SA[i]-k;
        memset(tong,0,sizeof(tong));
        for(int i=1;i<=n;i++)tong[x[y[i]]]++;
        for(int i=1;i<=m;i++)tong[i]+=tong[i-1];
        for(int i=n;i;i--)SA[tong[x[y[i]]]--]=y[i];
        swap(x,y);
        x[SA[1]]=p=1;
        for(int i=2;i<=n;i++)x[SA[i]]=cmp(SA[i],SA[i-1],k)?p:++p;
        if(p>=n)break;
        m=p;
    }
    for(int i=1;i<=n;i++)rk[SA[i]]=i;
    logn[0]=-1;
    for(int i=1;i<=n;i++){
    	logn[i]=logn[i>>1]+1;
    	for(height[rk[i]]=max(height[rk[i-1]]-1,0);ch[i+height[rk[i]]]==ch[SA[rk[i]+1]+height[rk[i]]];height[rk[i]]++);
    	//cout<<i<<" "<<SA[rk[i]+1]<<" "<<height[rk[i]]<<endl;
	}
	for(int i=1;i<=n;i++)ff[i][0]=height[i];
	//for(int i=1;i<=n;i++)cout<<height[i]<<" "; puts("");
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j<=n;j++)if(j>=(1<<(i-1))){ff[j][i]=min(ff[j][i-1],ff[j-(1<<(i-1))][i-1]); }
	}
}
int main(){
    int T=1;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>n>>(a+1)>>m>>(b+1)>>x;
       	solve(); n-=m; 
		for(int i=0;i<=n;i++){
            for(int j=0;j<=x;j++){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                int t=lcp(i+1,dp[i][j]+1);
                //cout<<i+1<<" "<<dp[i][j]+1<<" "<<lcp(i+1,dp[i][j]+1)<<endl;
                dp[i+t][j+1]=max(dp[i+t][j+1],dp[i][j]+t);
            }
        }
        int flag=0;
        for(int i=0;i<=x;i++)if(dp[n][i]>=m){
            puts("YES"); flag=1; break;
        }
        if(!flag)puts("NO");
    }
}