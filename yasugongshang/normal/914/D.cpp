#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
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
#define N 500005
int a[N],G[N<<2];
int id[100],L[100],R[100],n,q,tot;
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void build(int k,int l,int r){
	if (l==r) return G[k]=a[l],void(0);
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	G[k]=gcd(G[k*2],G[k*2+1]);
}
void change(int k,int l,int r,int p,int v){
	if (l==r) return G[k]=v,void(0);
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	G[k]=gcd(G[k*2],G[k*2+1]);
}
void getblock(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		id[++tot]=k; L[tot]=l; R[tot]=r;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) getblock(k*2,l,mid,x,y);
	else if (x>mid) getblock(k*2+1,mid+1,r,x,y);
	else getblock(k*2,l,mid,x,mid),
		 getblock(k*2+1,mid+1,r,mid+1,y);
}
bool check(int k,int l,int r,int v){
	if (l==r) return 1;
	if ((G[k*2]%v!=0)&&(G[k*2+1]%v!=0))
		return 0;
	int mid=(l+r)/2;
	if (G[k*2]%v!=0) return check(k*2,l,mid,v);
	if (G[k*2+1]%v!=0) return check(k*2+1,mid+1,r,v);
	return 1;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	q=read();
	while (q--){
		int fl=read(),x=read(),y=read(),z;
		if (fl==2){
			change(1,1,n,x,y);
			continue;
		}
		z=read();
		tot=0;
		getblock(1,1,n,x,y);
		int sum=0;
		for (int i=1;i<=tot;i++)if (G[id[i]]%z) sum++;
		if (sum==0){
			puts("YES");
			continue;
		}
		if (sum>1){
			puts("NO");
			continue;
		}
		for (int i=1;i<=tot;i++)
			if (G[id[i]]%z){
				if (check(id[i],L[i],R[i],z))
					puts("YES");
				else puts("NO");
			}
	}
}