#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
const long long N=300005;
long long n,m,a[N];
struct data{
	long long ans,lzf,rzf,lz,lf,rz,rf;
}tree[4*N];
inline data p(data a,data b,long long l,long long mid,long long r){
	data zs;
	if(a.lz==mid-l+1)zs.lz=a.lz+b.lz; else zs.lz=a.lz;
	if(a.lf==mid-l+1)zs.lf=a.lf+b.lf; else zs.lf=a.lf;
	if(b.rz==r-mid)zs.rz=a.rz+b.rz; else zs.rz=b.rz;
	if(b.rf==r-mid)zs.rf=a.rf+b.rf; else zs.rf=b.rf;
	if(a.lz==mid-l+1)zs.lzf=a.lz+b.lzf; else if(a.lzf==mid-l+1)zs.lzf=a.lzf+b.lf; else zs.lzf=a.lzf;
	if(b.rf==r-mid)zs.rzf=a.rzf+b.rf; else if(b.rzf==r-mid)zs.rzf=a.rz+b.rzf; else zs.rzf=b.rzf;
	zs.ans=max(max(a.ans,b.ans),max(a.rz+b.lzf,a.rzf+b.lf));
	return zs;
}
inline data chu(long long x){
	return (data){x!=0,x!=0,x!=0,x>0,x<0,x>0,x<0};
}
inline void insert(long long l,long long r,long long i,long long nod){//cout<<l<<" "<<r<<" "<<i<<" "<<nod<<endl;
	long long mid=(l+r)>>1;
	if (l==r) {tree[nod]=chu(a[l]); return;}
	if (i<=mid)insert(l,mid,i,nod<<1);
	else insert(mid+1,r,i,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1],l,mid,r);
}
inline void build(long long l,long long r,long long nod){long long mid=(l+r)>>1;
	if (l==r) {tree[nod]=chu(a[l]); return;}
	build(l,mid,nod<<1); build(mid+1,r,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1],l,mid,r);
	//cout<<tree[nod].ans<<" "<<tree[nod].lf<<" "<<tree[nod].lz<<" "<<tree[nod].lzf<<" "<<tree[nod].rf<<" "<<tree[nod].rz<<" "<<tree[nod].rzf<<" "<<l<<" "<<r<<endl;
}
int main(){
    n=read(); 
    if(n==1){
    	m=read();
    	while(m--){
    		writeln(1);
		}
		return 0;
	}
    for(long long i=1;i<=n;i++){a[i]=read(); a[i-1]=a[i]-a[i-1];} 
	build(1,n-1,1);
    m=read();
    while(m--){
    	long long l=read(),r=read(),w=read();
    	if(l>1){a[l-1]+=w; insert(1,n-1,l-1,1);} a[r]-=w; insert(1,n-1,r,1);
    	writeln(tree[1].ans+1);
	}
}