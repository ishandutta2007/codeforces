#include<bits/stdc++.h>
inline void read(int&x){
	char c=getchar();
	for(x=0;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-48;
}
const int N=500005;
int n,a[N],q,o,i,l,r,x,z,y,pos[N];
struct node{
	int l,r,m,d;
}t[N<<2];
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline void maintain(int i){t[i].d=gcd(t[i<<1].d,t[i<<1|1].d);}
inline void build(int i,int l,int r){
	t[i].l=l,t[i].r=r,t[i].m=(l+r)>>1;
	if(l==r){pos[l]=i;t[i].d=a[l];return;}
	build(i<<1,l,t[i].m),build(i<<1|1,t[i].m+1,r);
	maintain(i);
}
int st[200],w;
void getseg(int i,int l,int r){
	if(t[i].l==l && t[i].r==r){
		st[++w]=i;return;
	}
	if(l>t[i].m)getseg(i<<1|1,l,r);
		else if(r<=t[i].m)getseg(i<<1,l,r);
				else getseg(i<<1,l,t[i].m),getseg(i<<1|1,t[i].m+1,r);
}
inline bool check(int i){
	if(t[i].l==t[i].r)return t[i].d%x;
	if(t[i<<1].d%x && t[i<<1|1].d%x)return 0;
	return check(i<<1|bool(t[i<<1|1].d%x));
}
void mdy(int x,int v){
	int i=pos[x];t[i].d=v;
	for(i>>=1;i;i>>=1)maintain(i);
}
int main(){
	read(n);for(i=1;i<=n;++i)read(a[i]);
	build(1,1,n);read(q);
	while(q--){
		read(o),read(l),read(r);
		if(o==1){
			read(x);
			w=0;getseg(1,l,r);z=0;
			for(i=1;i<=w;++i)if(t[st[i]].d%x)++z,y=st[i];
			if(z>1){
				puts("NO");continue;
			}
			if(z && !check(y))puts("NO");
				else puts("YES");
		}else mdy(l,r);
	}
	return 0;
}