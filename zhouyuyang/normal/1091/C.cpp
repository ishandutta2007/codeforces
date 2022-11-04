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
int n;
ll ans[244444];
void insert(int x){
	int cnt=n/x;
	ll tmp=1ll*cnt*(cnt-1)/2*x;
	ans[++*ans]=tmp+cnt;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i*i<=n;i++)
		if (n%i==0){
			insert(i);
			if (i*i!=n) insert(n/i);
		}
	sort(ans+1,ans+*ans+1);
	For(i,1,*ans) printf("%lld ",ans[i]);
}