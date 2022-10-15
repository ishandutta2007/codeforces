#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int B;
struct query{
	int l,r,id;
	bool operator <(const query &q) const {
		return (l/B==q.l/B)?r<q.r:l<q.l;
	}
}q[N];
int n,m,sum,a[N],cnt[N],ans[N];
inline void add(int x){
	x=a[x];if(x>n)return;
	if(cnt[x]==x)sum--;
	if((++cnt[x])==x)sum++;
}

inline void del(int x){
	x=a[x];if(x>n)return;
	if(cnt[x]==x)sum--;
	if((--cnt[x])==x)sum++;
}
int main(){
	n=read(),m=read();B=sqrt(n)+(n>3)+(n>6);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1);int L=1,R=0;
	for(int i=1;i<=m;i++){
		int l=q[i].l,r=q[i].r;
		while(L<l)del(L++);
		while(L>l)add(--L);
		while(R<r)add(++R);
		while(R>r)del(R--);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}