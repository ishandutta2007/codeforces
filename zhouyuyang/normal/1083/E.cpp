#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
using namespace std;

int n,tp; ll f[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
struct node{ ll x,y,z; }a[N],h[N];
bool cmpx(node u,node v){ return u.x<v.x; }
bool check(node a,node b,node c){
	ll A=c.y-b.y,B=c.x-b.x,C=b.y-a.y,D=b.x-a.x;
	if (A/B!=C/D) return A/B>C/D;
	A%=B; C%=D;
	return A*D>=B*C;
}
int main(){
	n=read();
	int i;
	for (i=1; i<=n; i++){
		a[i].x=read(); a[i].y=read(); scanf("%lld",&a[i].z);
	}
	sort(a+1,a+n+1,cmpx);
	int tp=1;
	h[1]=(node){0,0,0};
	ll ans=0;
	for (i=1; i<=n; i++){
		int l=1,r=tp;
		while (l<r){
			int mid=l+r>>1;
			if (h[mid+1].y-h[mid].y>(h[mid+1].x-h[mid].x)*a[i].y) l=mid+1; else r=mid;	
		}
		f[i]=h[l].y+(a[i].x-h[l].x)*a[i].y-a[i].z;
		while (h[tp].x==a[i].x && f[i]>h[tp].y) tp--;
		if (f[i]<=h[tp].y) continue;
		while (tp>1 && check(h[tp-1],h[tp],(node){a[i].x,f[i],0})) tp--;
		h[++tp]=(node){a[i].x,f[i],0};
		ans=max(ans,f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}