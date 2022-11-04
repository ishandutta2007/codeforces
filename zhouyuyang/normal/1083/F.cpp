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
const int N=400005,B=500;
int a[N],b[N],c[N];
int n,k,Q,ans,GG;
struct data{
	int a[(1<<14)+2];
};
vector<data> to[N];
vector<int> v[N],V[N];
void build(int id){
	int x=(n/k)+(id<n%k)-1;
	for (int j=id;j<=n;j+=k) v[id][j/k]=c[j];
	for (int i=x;i>=0;i--){
		v[id][i]^=v[id][i+1];
		if (!v[id][i]) ans--;
		if (i/B<to[id].size())
			to[id][i/B].a[v[id][i]]++;
	}
	if (v[id][0]&&id!=k-1)
		GG++;
}
void change(int pos,int vv){
	int id=pos%k; pos/=k;
	if ((v[id][0]^V[id][0])&&id!=k-1) GG--;
	int bel=pos/B,x=V[id][bel];
	Rep(i,pos,pos/B*B){
		if (v[id][i]==x) ans++;
		if (bel<to[id].size()) to[id][bel].a[v[id][i]]--;
		v[id][i]^=vv;
		if (bel<to[id].size()) to[id][bel].a[v[id][i]]++;
		if (v[id][i]==x) ans--;
	}
	Rep(i,bel-1,0){
		ans+=to[id][i].a[V[id][i]];
		V[id][i]^=vv;
		ans-=to[id][i].a[V[id][i]];
	}
	if ((v[id][0]^V[id][0])&&id!=k-1) GG++;
}
int main(){
	scanf("%d%d%d",&n,&k,&Q); ans=n;
	For(i,0,n-1) scanf("%d",&a[i]);
	For(i,0,n-1) scanf("%d",&b[i]);
	Rep(i,n-1,0) c[i]=a[i]^b[i]^a[i+1]^b[i+1];
	For(i,0,k-1){
		v[i].resize(n/k+3);
		V[i].resize(n/k/B+3);
		to[i].resize((n/k+3)/B);
		build(i);
	}
	printf("%d\n",GG?-1:ans);
	while (Q--){
		int p,v; char s[10];
		scanf("%s%d%d",s,&p,&v); p--;
		if (s[0]=='a'){
			change(p,v^a[p]);
			if (p) change(p-1,v^a[p]);
			a[p]=v;
		}
		else{
			change(p,v^b[p]);
			if (p) change(p-1,v^b[p]);
			b[p]=v;
		}
		printf("%d\n",GG?-1:ans);
	}
}