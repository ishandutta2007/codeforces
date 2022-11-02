#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005,oo=10000000;
int dq,n,q,i,a[N],b[N],c[N];
long long ans;
struct data{
	int mmin,pos,sum;
}tree[4*N];
inline data p(data a,data b){
	data zs;
	if(b.mmin<a.mmin){
		zs.mmin=b.mmin; zs.pos=b.pos;
	}else{
		zs.mmin=a.mmin; zs.pos=a.pos;
	}
	zs.sum=a.sum+b.sum;
	return zs;
}
inline data chu(int po){
	data zs;
	zs.mmin=a[po]; zs.pos=po; zs.sum=c[po]; return zs;
}
inline data ask(int l,int r,int i,int j,int nod){
	if(i>j)return (data){oo,1,0};
    int mid=(l+r)>>1;
	if (l==i&&j==r) return tree[nod];
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,(nod<<1)+1);
	data left=ask(l,mid,i,mid,nod<<1);
	data right=ask(mid+1,r,mid+1,j,(nod<<1)+1);
	return p(left,right);
}
inline void insert(int l,int r,int i,int nod){//cout<<l<<" "<<r<<" "<<i<<" "<<nod<<endl;
	int mid=(l+r)>>1;
	if (l==r) {tree[nod]=chu(l); return;}
	if (i<=mid)insert(l,mid,i,nod<<1);
	else insert(mid+1,r,i,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1]);
}
inline void build(int l,int r,int nod){int mid=(l+r)>>1;
	if (l==r) {tree[nod]=chu(l); return;}
	build(l,mid,nod<<1); build(mid+1,r,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1]); //cout<<tree[nod].sum<<endl;
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){a[i]=b[i]=read(); c[i]=1;}sort(&b[1],&b[n+1]); build(1,n,1);
	for(int i=1;i<=n;i++){
		int z=b[i];
		data zs=ask(1,n,dq+1,n,1);
		if(zs.mmin==z){
			ans+=ask(1,n,dq+1,zs.pos,1).sum;
			a[zs.pos]=oo; c[zs.pos]=0;
			insert(1,n,zs.pos,1);
		}else{
			ans+=zs.sum; 
			zs=ask(1,n,1,dq-1,1); 
			ans+=ask(1,n,1,zs.pos,1).sum;
			a[zs.pos]=oo; c[zs.pos]=0;
			insert(1,n,zs.pos,1);
		}
		dq=zs.pos;
		//cout<<i<<" "<<dq<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}