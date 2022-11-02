#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
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
const int N=200005,K=55;
int n,k,a[N],LL,RR;
double zs,dp[K][N],sum[N],sss[N],tot[N];
void solve(int l,int r,int L,int R,int id){
	if(l>r)return;
	int mid=(l+r)>>1,pos=mid;
	double ans=4e18;
	for(int i=min(R,mid);i>=L;i--){
		double zs=tot[mid]-tot[i-1]-sss[i-1]*(sum[mid]-sum[i-1]);
		if(zs+dp[id-1][i-1]<ans)ans=zs+dp[id-1][i-1],pos=i;
		//cout<<zs<<" "<<id<<" "<<i<<" "<<mid<<endl;
	}
	dp[id][mid]=ans;
	solve(l,mid-1,L,pos,id); solve(mid+1,r,pos,R,id);
}
int main(){
	n=read(); k=read();LL=1; RR=0;
	for(int i=1;i<=n;i++){a[i]=read(); sum[i]=sum[i-1]+(double)1/a[i];}
	for(int i=1;i<=n;i++){sss[i]=sss[i-1]+a[i]; dp[1][i]=tot[i]=dp[1][i-1]+sss[i]/a[i];}
	for(int i=2;i<=k;i++)solve(1,n,1,n,i);
	printf("%.6lf\n",dp[k][n]);
}