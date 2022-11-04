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
const int N=100000;
const ll LL_MAX=(1ll<<63)-1;
struct num{
	ll v[5];
	num(){
		memset(v,0,sizeof(v));
	}
	num operator +(const num &a)const{
		num c;
		For(i,0,4)
			c.v[i]=v[i]+a.v[i];
		return c;
	}
	num operator -(const num &a)const{
		num c;
		For(i,0,4)
			c.v[i]=v[i]-a.v[i];
		return c;
	}
	num operator *(const num &a)const{
		num c;
		For(i,0,4) For(j,0,4)
			c.v[(i+j)%5]+=v[i]*a.v[j];
		return c;
	}
	num shift(int w)const{
		num c;
		For(i,0,4)
			c.v[(i+w)%5]=v[i];
		return c;
	}
}a[N],tmp[20];
ll power(ll x,ll y){
	ll s=1;
	for (;y;y/=2,x*=x)
		if (y&1) s*=x;
	return s;
}
num power(num x,int y){
	num s; s.v[0]=1;
	for (;y;y/=2,x=x*x)
		if (y&1) s=s*x;
	return s;
}
void DFT(int S,int n,int fl){
	if (n==1) return;
	For(i,0,9) DFT(S+n/10*i,n/10,fl);
	For(i,0,n/10-1){
		For(j,0,9) For(k,0,4) tmp[j].v[k]=0;
		For(j,0,9) For(k,0,9){
			int w=(fl==1?j*k%10:(10-j*k%10)%10);
			if (w&1) tmp[j]=tmp[j]-a[S+n/10*k+i].shift((w+5)/2);
			else tmp[j]=tmp[j]+a[S+n/10*k+i].shift(w/2);
		}
		For(j,0,9) a[S+n/10*j+i]=tmp[j];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		++a[x].v[0];
	}
	DFT(0,N,1);
	For(i,0,N-1)
		a[i]=power(a[i],n);
	DFT(0,N,-1);
	ll inv=power(3125,LL_MAX);
	For(i,0,n-1)
		printf("%lld\n",(((a[i].v[0]-a[i].v[1])>>5)*inv)&((1ll<<58)-1));
}