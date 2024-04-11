#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo1=998244353,mo2=998244853,N=5e5+5;
struct P{int x,y;operator ll(){return ll(x)<<30|y;}}h[N],mi[N];
P operator+(P a,P b){return (P){(a.x+b.x)%mo1,(a.y+b.y)%mo2};}
P operator-(P a,P b){return (P){(a.x+mo1-b.x)%mo1,(a.y+mo2-b.y)%mo2};}
P operator*(P a,P b){return (P){int(1ll*a.x*b.x%mo1),int(1ll*a.y*b.y%mo2)};}
int n,i,f[N],ans;
char c[N];
P geth(int l,int r){return h[r]-h[l-1]*mi[r-l+1];}
unordered_set<ll>S;
vector<int>ve[N];
int main(){
	scanf("%d%s",&n,c+1);
	mi[0]=(P){1,1};mi[1]=(P){71,97};for(i=2;i<=n;++i)mi[i]=mi[i-1]*mi[1];
	for(i=1;i<=n;++i)h[i]=h[i-1]*mi[1]+(P){c[i]-'a'+1,c[i]-'a'+1};
	f[n+1]=1;S.insert((P){0,0});
	for(i=n;i;--i){
		f[i]=f[i+1]-1;for(int x:ve[i])S.insert(geth(i+1,x));
		for(;f[i]<i && (S.count(geth(i-f[i]+1,i)) || S.count(geth(i-f[i],i-1)));++f[i]);
		ans=max(ans,f[i]);for(int j=f[i+1]-1;j<=f[i];++j)ve[i-j].push_back(i);
	}
	printf("%d\n",ans);
	return 0;
}