#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
int n,q,i;
struct data{
	int val,pos;
}a[N];
inline bool cmp(data a,data b){
	return a.val<b.val;
}
int tree[4*N],tong[N];
inline int ask(int l,int r,int i,int j,int nod){if(j<i)return n+1;
    int mid=(l+r)>>1;
	if (l==i&&j==r) return tree[nod];
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,(nod<<1)+1);
	int left=ask(l,mid,i,mid,nod<<1);
	int right=ask(mid+1,r,mid+1,j,(nod<<1)+1);
	return min(left,right);
}
inline void insert(int l,int r,int i,int nod){
	if (l==r){tree[nod]=n+1; return;}
	int mid=(l+r)>>1;
	if (i<=mid)insert(l,mid,i,nod<<1);
	else insert(mid+1,r,i,(nod<<1)+1);
	tree[nod]=min(tree[nod<<1],tree[(nod<<1)+1]);
}
inline void build(int l,int r,int nod){int mid=(l+r)>>1;
	if (l==r) {tree[nod]=a[l].pos; return;}
	build(l,mid,nod<<1); build(mid+1,r,(nod<<1)+1);
	tree[nod]=min(tree[nod<<1],tree[(nod<<1)+1]);
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].val=read(); a[i].pos=i;
	}
	sort(&a[1],&a[n+1],cmp); build(1,n,1);
	for(int i=1;i<=n;i++)tong[a[i].pos]=i; int sum=0;
	//cout<<ask(1,n,1,n,1)<<endl;
	while(sum<n){
		for(int i=ask(1,n,1,n,1);i<=n;i=ask(1,n,tong[i]+1,n,1)){
			write(a[tong[i]].val); sum++; putchar(' '); insert(1,n,tong[i],1);
		}puts(""); 
	}
}