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
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int n;
ll l[N],t;
ll rest[N];
char tp[N];
ll calc2(){
	ll preG=0,preE=0;
	ll val,ti=t*2;
	Rep(i,n,1){
		ll val=rest[i-1]*4;
		if (tp[i]=='G') preG+=l[i]*4;
		if (tp[i]=='W') preE+=l[i]*2;
		ll v=min(preG,val/2);
		preG-=v; val-=2*v; ti-=2*v;
		v=min(preE,val/2);
		preE-=v; val-=2*v; ti-=v;
		//printf("%lld %lld %lld\n",val,preE,preG);
	}
	return ti/2;
}
//2->1 0.5
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&l[i]);
	scanf("%s",tp+1);
	ll E=0,pmn=10;
	For(i,1,n){
		if (tp[i]=='G'){
			pmn=min(pmn,5ll); 
			E+=l[i],t+=l[i]*5;
		}
		else if (tp[i]=='W'){
			pmn=min(pmn,3ll);
			E+=l[i],t+=l[i]*3;
		}
		else{
			if (E<l[i]){
				t+=(l[i]-E)*pmn;
				E=l[i];
			}
			E-=l[i];
			t+=l[i];
		}
		rest[i]=E;
	}
	//printf("%lld\n",t);
	Rep(i,n-1,1) rest[i]=min(rest[i],rest[i+1]);
	For(i,0,n-1) rest[i]=rest[i+1]-rest[i];
	//For(i,0,n-1) printf("%lld\n",rest[i]);
	printf("%lld\n",calc2());
}
// 
// 
/*
3
100 100 10
WGL
*/