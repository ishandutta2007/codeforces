#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005,M=7005;
int mu[M],Q;
bitset<M> a[N],b1[M],b2[M];
int main(){
	For(i,1,M-1) mu[i]=1;
	For(i,2,M-1) For(j,1,(M-1)/i/i) mu[i*i*j]=0;
	For(i,1,M-1) For(j,1,(M-1)/i) b1[i*j][i]=1;
	For(i,1,M-1) For(j,1,(M-1)/i) b2[i][i*j]=mu[j];
	scanf("%*d%d",&Q);
	while (Q--){
		int tp,x,y,z;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) a[x]=b1[y];
		if (tp==2) scanf("%d",&z),a[x]=a[y]^a[z];
		if (tp==3) scanf("%d",&z),a[x]=a[y]&a[z];
		if (tp==4) putchar('0'+(a[x]&b2[y]).count()%2);
	}
}