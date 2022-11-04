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
ll sum[35];
multiset<int> s[35];
int main(){
	int Q;
	scanf("%d",&Q);
	while (Q--){
		char c[10]; int x;
		scanf("%s%d",c,&x);
		int i=0;
		for (;(1<<(i+1))<=x;i++);
		if (c[0]=='+') sum[i]+=x,s[i].insert(x);
		else sum[i]-=x,s[i].erase(s[i].find(x));
		ll S=0; int ans=0;
		For(i,0,30){
			ans+=s[i].size();
			if (!s[i].empty()&&*s[i].begin()>2*S) ans--;
			S+=sum[i];
		}
		printf("%d\n",ans);
	}
}