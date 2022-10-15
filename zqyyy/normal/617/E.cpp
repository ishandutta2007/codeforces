#include <cstdio>
#include <cctype>
#include <iostream>
#include <cmath>
#include <algorithm>
#define re register
#define ll long long
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+1,A=1<<20;
int n,m,b,k,a[N],cnt[A];
ll sum,ans[N];
struct qry{
	int l,r,id;
	bool operator <(const qry &q) const {
		return l/b^q.l/b?l/b<q.l/b:r<q.r;
	}
}q[N];
inline void add(int x){
	sum+=cnt[a[x]^k],cnt[a[x]]++;
}
inline void del(int x){
	cnt[a[x]]--,sum-=cnt[a[x]^k];
}
int main(){
    n=read(),m=read(),k=read(),b=sqrt(n)+(n>3)+(n>6);
	for(re int i=1;i<=n;i++)a[i]=read()^a[i-1];
	for(re int i=1;i<=m;i++)q[i].l=read()-1,q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1);int l=1,r=0;
	for(re int i=1;i<=m;i++){
		while(l>q[i].l)add(--l);
		while(l<q[i].l)del(l++);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=sum;
	}
	for(re int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}