#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int M=1<<18|3,N=100005;
int n,Q,q[10],tot,mn[M],mx[M],Add[M],jb[M],lazy[M],a[N];
int Alb(int x){
	return *lower_bound(&q[0],&q[tot],x)-x;
}
void cao(int nod,int x){
	mn[nod]+=x; mx[nod]+=x; Add[nod]+=x; jb[nod]-=x; 
}
void bao(int nod,int x){
	mn[nod]=mx[nod]=x; Add[nod]=0; lazy[nod]=x;
	jb[nod]=Alb(mx[nod]);
}
void pushdown(int nod){
	if(Add[nod]&&lazy[nod]){
		lazy[nod]+=Add[nod]; Add[nod]=0;
	}
	if(lazy[nod]){
		bao(nod<<1,lazy[nod]); bao(nod<<1|1,lazy[nod]); lazy[nod]=0; return;
	}
	if(Add[nod]){
		cao(nod<<1,Add[nod]); cao(nod<<1|1,Add[nod]); Add[nod]=0; return;
	}
}
void push_up(int nod){
	mn[nod]=min(mn[nod<<1],mn[nod<<1|1]); jb[nod]=min(jb[nod<<1],jb[nod<<1|1]); mx[nod]=max(mx[nod<<1],mx[nod<<1|1]);
}
void add(int l,int r,int i,int j,int x,int nod){
	if(l==i&&r==j){
		if(jb[nod]>x){
			cao(nod,x); return;
		}
		if(mx[nod]==mn[nod]){
			bao(nod,mx[nod]+x); return;
		}
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)add(l,mid,i,j,x,nod<<1); else if(i>mid)add(mid+1,r,i,j,x,nod<<1|1);
	else{
		add(l,mid,i,mid,x,nod<<1); add(mid+1,r,mid+1,j,x,nod<<1|1);
	}
	push_up(nod);
}
void insert(int l,int r,int i,int j,int x,int nod){
	if(l==i&&r==j){
		bao(nod,x); return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,x,nod<<1); else if(i>mid)insert(mid+1,r,i,j,x,nod<<1|1);
	else{
		insert(l,mid,i,mid,x,nod<<1); insert(mid+1,r,mid+1,j,x,nod<<1|1);
	}
	push_up(nod);
}
int ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return jb[nod];
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return min(ask(l,mid,i,mid,nod<<1),ask(mid+1,r,mid+1,j,nod<<1|1));
}
int ask(int l,int r,int pos,int nod){
	if(l==r)return mx[nod];
	pushdown(nod);
	int mid=(l+r)>>1;
	if(pos<=mid)return ask(l,mid,pos,nod<<1); else return ask(mid+1,r,pos,nod<<1|1);
}
void build(int l,int r,int nod){
	if(l==r){
		bao(nod,a[l]); return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
signed main(){
	n=read(); Q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=42;tot<9;i*=42)q[tot++]=i; 
	build(1,n,1); 
	while(Q--){
		int op=read();
		if(op==1){
			writeln(ask(1,n,read(),1));
		}else if(op==2){
			int l=read(),r=read(),x=read();
			insert(1,n,l,r,x,1);
		}else{
			int l=read(),r=read(),x=read();
			add(1,n,l,r,x,1);
			while(ask(1,n,l,r,1)==0){
				add(1,n,l,r,x,1);// cout<<l<<" "<<r<<" "<<ask(1,n,1,1)<<endl;
			}
		}
	}
}