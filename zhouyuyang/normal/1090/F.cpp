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
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
struct node{
	int x,y,z,v;
	bool operator <(const node &a)const{
		return v<a.v;
	}
}q[15];
int n,a[1005];
int ask(int v1,int v2,int v3){
	printf("? %d %d %d\n",v1,v2,v3);
	fflush(stdout);
	scanf("%d",&v1);
	return v1;
}
void calc(int l,int r){
	int top=0;
	For(v1,l,r) For(v2,v1+1,r) For(v3,v2+1,r)
		q[++top]=(node){v1,v2,v3,ask(v1,v2,v3)};
	sort(q+1,q+top+1);
	int v13=q[1].v,v14=q[2].v;
	int v25=q[9].v,v35=q[10].v;
	int v15=(1ll*q[4].v+q[5].v+q[6].v+q[7].v-v14-v25)/2;
	int d15=v35-v13,v1=(v15-d15)/2,v5=(v15+d15)/2;
	int v3=v13-v1,v4=v14-v1,v2=v25-v5;
	a[l]=v1; a[l+1]=v2; a[l+2]=v3; a[l+3]=v4; a[l+4]=v5;
	for (;;){
		bool flag=0;
		For(i,1,10){
			int v=min(a[q[i].x],min(a[q[i].y],a[q[i].z]))+
				  max(a[q[i].x],max(a[q[i].y],a[q[i].z]));
			if (v!=q[i].v) flag=1;
		}
		if (!flag) break;
		next_permutation(a+l,a+r+1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i+4<n;i+=5) calc(i,i+4);
	calc(n-4,n);
	printf("!");
	For(i,1,n) printf(" %d",a[i]);
}