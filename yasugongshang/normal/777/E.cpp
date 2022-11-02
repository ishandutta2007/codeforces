#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define int long long
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
const int N=100005,M=4000005;
int sum,top,nodecnt,n,dp[N],tree[M],ans,lson[M],rson[M],rt;
inline void insert(int l,int r,int i,int j,int s,int &nod){
	if(!nod)nod=++nodecnt;
	if(l==i&&r==j){
		//cout<<l<<" "<<r<<" "<<s<<endl;
		tree[nod]=max(tree[nod],s); return;
	}
	int mid=l+r>>1;
	if(j<=mid)insert(l,mid,i,j,s,lson[nod]);
	else if(i>mid)insert(mid+1,r,i,j,s,rson[nod]);
	else insert(l,mid,i,mid,s,lson[nod]),insert(mid+1,r,mid+1,j,s,rson[nod]);
}
inline int ask(int l,int r,int pos,int nod){
	//cout<<nod<<" "<<l<<" "<<r<<" "<<tree[nod]<<endl;
	if(!nod)return 0;
	if(l==r)return tree[nod];
	int mid=l+r>>1;
	if(pos<=mid)return max(ask(l,mid,pos,lson[nod]),tree[nod]);
	else return max(ask(mid+1,r,pos,rson[nod]),tree[nod]);
}
struct data{
	int a,b,c;
}a[N],q[N];
inline bool cmp(data a,data b){
	return a.b==b.b?a.a>b.a:a.b>b.b;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].a=read(); a[i].b=read(); a[i].c=read();
	}
	sort(&a[1],&a[n+1],cmp);
	for(int i=1;i<=n;i++){
		while(top&&a[i].b<=q[top].a)sum-=q[top--].c;
		q[++top]=a[i]; sum+=a[i].c;
		ans=max(ans,sum);
	}
	writeln(ans);
}