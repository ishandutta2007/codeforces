#include<bits/stdc++.h>
using namespace std;
typedef int LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
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
const int N=10005;
int rr,n,q;
bitset<N> ans,dp,que[20];
vector<int> v[N<<2];
inline void build(int l,int r,int i,int j,int zs,int nod){
	if(i>j)return;
	if(l==i&&r==j){
		v[nod].push_back(zs);
		return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)build(l,mid,i,j,zs,nod<<1);
	else if(i>mid)build(mid+1,r,i,j,zs,nod<<1|1);
	else{
		build(l,mid,i,mid,zs,nod<<1); build(mid+1,r,mid+1,j,zs,nod<<1|1);
	}
}
inline void solve(int l,int r,int nod){
	rr++;
	que[rr]=dp;
	for(int i=0;i<v[nod].size();i++){
		int zs=v[nod][i];
		dp=dp|dp<<zs;
	}
	//cout<<l<<" "<<r<<" "<<dp[1]<<" "<<dp[2]<<endl;
	if(l==r){
		ans|=dp;
		dp=que[rr--];
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,nod<<1); solve(mid+1,r,nod<<1|1);
	dp=que[rr];
	rr--;
}
int main(){
	n=read(); q=read();
	for(int i=1;i<=q;i++){
		int l=read(),r=read(),x=read();
		build(1,n,l,r,x,1);
	}
	dp[0]=1;
	solve(1,n,1);
	int tot=0;
	for(int i=1;i<=n;i++)if(ans[i])tot++;
	writeln(tot);
	for(int i=1;i<=n;i++)if(ans[i]){
		write(i); putchar(' ');
	}
}