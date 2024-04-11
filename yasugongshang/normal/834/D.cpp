#include<iostream>
#include<cstdio>
using namespace std;
const int K=55,N=35005;
int n,a[N],lazy[N<<2],last[N];
int k,dp[K][N],tong[N];
struct data{
    int val;
}tree[N<<2];
inline void cao(int nod,int x){
    tree[nod].val+=x;
    return;
}
inline void p(int nod){
    tree[nod].val=max(tree[nod<<1].val,tree[(nod<<1)+1].val);
    if(lazy[nod])cao(nod,lazy[nod]);
}
inline void pushdown(int p){
    lazy[p<<1]+=lazy[p]; lazy[(p<<1)+1]+=lazy[p]; cao(p<<1,lazy[p]); cao((p<<1)+1,lazy[p]); lazy[p]=0; 
}
inline int ask(int l,int r,int i,int j,int nod){int mid=(l+r)>>1;
    if (l==i&&j==r) return tree[nod].val; pushdown(nod);
    if (j<=mid) return ask(l,mid,i,j,nod<<1);
    else if(i>mid) return ask(mid+1,r,i,j,(nod<<1)+1);
    int left=ask(l,mid,i,mid,nod<<1);
    int right=ask(mid+1,r,mid+1,j,(nod<<1)+1);
    return max(left,right);
}
inline void insert(int l,int r,int i,int j,int s,int nod){int mid=(l+r)>>1;  
    if(l==i&&r==j){
        lazy[nod]+=s; cao(nod,s); return;
    }
    pushdown(nod);
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,(nod<<1)+1); else{
        insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,(nod<<1)+1);
    }
    p(nod);
}
inline void build(int l,int r,int nod,int id){int mid=(l+r)>>1;lazy[nod]=0; 
    if (l==r) {tree[nod].val=dp[id][l-1];  return;}
    build(l,mid,nod<<1,id); build(mid+1,r,(nod<<1)+1,id);
    p(nod);
}
inline void write(int a)
{
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a)
{
    write(a); puts("");
}
inline int  read()// 
{
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')  positive = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return positive ? x : -x;
}
int main(){
    n=read(); k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
    	if(tong[a[i]])last[i]=tong[a[i]];
    	tong[a[i]]=i;
	}
    for(int i=1;i<=k;i++){
    	build(1,n,1,i-1); 
    	for(int j=i;j<=n;j++){
    		insert(1,n,last[j]+1,j,1,1);
    		dp[i][j]=ask(1,n,i,j,1); 
    		//cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
		}
	}
	cout<<dp[k][n]<<endl;
}