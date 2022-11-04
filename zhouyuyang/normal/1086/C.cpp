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
int vis[30],Ans[30],ans[30],Vis[30],k;
void output(){
	int at=1;
	for (int i=1;i<=k;i++)
		if (!ans[i]){
			for (;vis[at];at++);
			ans[i]=at;
			vis[at]=1;
		}
	puts("YES");
	for (int i=1;i<=k;i++)
		putchar(ans[i]+'a'-1);
	puts("");
}
const int N=1000005;
char a[N],b[N],s[N];
bool fill(int x,int y){
	if (!ans[x])
		if (!vis[y]){
			ans[x]=y,vis[y]=1;
			return 1;
		}
		else
			return 0;
	else if (ans[x]!=y)
		return 0;
	else return 1;
}
void solve(){
	scanf("%d%s%s%s",&k,s+1,a+1,b+1);
	int n=strlen(s+1);
	For(i,1,n) s[i]=s[i]-'a'+1;
	For(i,1,n) a[i]=a[i]-'a'+1;
	For(i,1,n) b[i]=b[i]-'a'+1;
	int lcp=1;
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	for (;lcp<=n&&a[lcp]==b[lcp];lcp++)
		if (!fill(s[lcp],a[lcp]))
			return puts("NO"),void(0);
	if (lcp>n)
		return output();
	for (int i=a[lcp]+1;i<=b[lcp]-1;i++)
		if (fill(s[lcp],i))
			return output();
	memcpy(Ans,ans,sizeof(ans));
	memcpy(Vis,vis,sizeof(vis));
	if (fill(s[lcp],a[lcp])){
		bool ok=1;
		for (int i=lcp+1;i<=n&&ok;i++){
			for (int j=a[i]+1;j<=k;j++)
				if (fill(s[i],j))
					return output();
			if (!fill(s[i],a[i])){
				ok=0; break;
			}
		}
		if (ok)
			return output();
	}
	memcpy(ans,Ans,sizeof(ans));
	memcpy(vis,Vis,sizeof(vis));
	if (fill(s[lcp],b[lcp])){
		bool ok=1;
		for (int i=lcp+1;i<=n&&ok;i++){
			for (int j=1;j<=b[i]-1;j++)
				if (fill(s[i],j))
					return output();
			if (!fill(s[i],b[i])){
				ok=0; break;
			}
		}
		if (ok)
			return output();
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
2
4
bbcb
aadb
aada
3
abc
bbb
bbb
*/