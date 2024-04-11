#include<iostream>
#include<cstdio>
using namespace std;
#define mp make_pair
const int N=100005;
int n,q,a[N];
int tree[N<<2],lazy[N<<2];
inline void cao(int p,int x){
	tree[p]+=x;
}
inline void pushdown(int p){
	if(!lazy[p])return;
	lazy[p<<1]+=lazy[p]; lazy[p<<1|1]+=lazy[p]; cao(p<<1,lazy[p]); cao(p<<1|1,lazy[p]); lazy[p]=0;
}
inline int ask(int l,int r,int nod){
	if(l==r)return l; int mid=(l+r)>>1;
	pushdown(nod);
	if(tree[nod<<1|1]>0)return ask(mid+1,r,nod<<1|1);
	else return ask(l,mid,nod<<1);
}
inline void insert(int l,int r,int i,int j,int s,int nod){int mid=(l+r)>>1;
	if(l==i&&r==j){
		lazy[nod]+=s; cao(nod,s); return;
	}
    pushdown(nod);
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,nod<<1|1); else{
    	insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,nod<<1|1);
	}
	tree[nod]=max(tree[nod<<1],tree[nod<<1|1]);
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
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int pos=read(),op=read();
		if(op)a[pos]=read();
		if(op==1){
			insert(1,n,1,pos,1,1);
		}else{
			insert(1,n,1,pos,-1,1);
		}
		//cout<<ask(1,n,1)<<endl;
		writeln(tree[1]<=0?-1:a[ask(1,n,1)]);
	}
}