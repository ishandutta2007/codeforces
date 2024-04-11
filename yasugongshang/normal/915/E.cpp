#include<iostream>
#include<cstdio>
using namespace std;
#define mp make_pair
const int M=15000000;
int rt,n,q,nodecnt;
int lazy[M],tree[M],lson[M],rson[M];
inline void cao(int nod,int id,int len){
	tree[nod]=id==1?len:0;
}
inline void pushdown(int nod,int len){
	if(!lazy[nod])return; if(!lson[nod])lson[nod]=++nodecnt; if(!rson[nod])rson[nod]=++nodecnt;
	lazy[lson[nod]]=lazy[rson[nod]]=lazy[nod]; cao(lson[nod],lazy[nod],len-(len>>1)); cao(rson[nod],lazy[nod],len>>1); lazy[nod]=0;
}
inline void insert(int l,int r,int i,int j,int &nod,int id){
	if(!nod)nod=++nodecnt;
	if(l==i&&r==j){
		lazy[nod]=id; cao(nod,id,r-l+1); return;
	}
    pushdown(nod,r-l+1);
    int mid=(l+r)>>1;
    if(j<=mid)insert(l,mid,i,j,lson[nod],id); else
    if(i>mid)insert(mid+1,r,i,j,rson[nod],id); else{
    	insert(l,mid,i,mid,lson[nod],id); insert(mid+1,r,mid+1,j,rson[nod],id);
	}
	tree[nod]=tree[lson[nod]]+tree[rson[nod]];
	//cout<<l<<' '<<r<<" "<<tree[nod]<<endl;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int main(){
	n=read(); int m=read();
	while(m--){
		int l=read(),r=read(),id=read();
		insert(1,n,l,r,rt,id);
		writeln(n-tree[rt]);
	}
}
//a tFrg 4a