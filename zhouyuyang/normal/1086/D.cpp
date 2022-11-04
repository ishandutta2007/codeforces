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
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
int tp(char x){
	return (x=='P'?0:(x=='R'?1:2));
}
const int N=200005;
int n,Q;
char s[N];
int a[N];
struct Tarr{
	int t[N];
	void change(int x,int v){
		for (;x<=n;x+=x&(-x)) t[x]+=v; 
	}
	int ask(int x){
		int ans=0;
		for (;x;x-=x&(-x))
			ans+=t[x];
		return ans;
	}
}t[3];
set<int> S[3];
vector<pii> range;
int calc(){
	int ans=n;
	for (int i=0;i<=2;i++){
		int beat=(i+2)%3,save=(i+1)%3;
		range.resize(0);
		if (!S[beat].empty()){
			int GG=*S[beat].begin();
			int ed=S[save].empty()?n:*S[save].begin(); 
			if (GG<=ed)	range.PB(pii(GG,ed));
			GG=*(--S[beat].end());
			ed=S[save].empty()?1:*(--S[save].end()); 
			if (GG>=ed) range.PB(pii(ed,GG));
		}
		sort(range.begin(),range.end());
		if (range.size()==2)
			if (range[0].se>=range[1].fi){
				range[0].se=range[1].se;
				range.pop_back();
			}
		for (auto p:range)
			ans-=t[i].ask(p.se)-t[i].ask(p.fi-1);
	}
	return ans;
}
int main(){
	scanf("%d%d%s",&n,&Q,s+1);
	for (int i=1;i<=n;i++)
		a[i]=tp(s[i]),S[a[i]].insert(i),t[a[i]].change(i,1);
	printf("%d\n",calc());
	while (Q--){
		int x; 
		scanf("%d%s",&x,s+1);
		t[a[x]].change(x,-1);
		S[a[x]].erase(x);
		a[x]=tp(s[1]);
		t[a[x]].change(x,1);
		S[a[x]].insert(x);
		printf("%d\n",calc());
	}
}
//1-(i-1):notbeat
//(i+1)-n:notbeat
//always beat A:
//no (A+1)%3  and   have(A+2)%3