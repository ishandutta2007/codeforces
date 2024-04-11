#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
typedef unsigned long long ll;
const ll B=1e18;
struct I128{
	ll h,l;
	void operator+=(ll x){l+=x;l>=B?l-=B,++h:0;}
	int operator%(int x){return (h%x*B%x+l)%x;}
	void print(){if(h)printf("%lld%018lld\n",h,l);else printf("%lld\n",l);}
}ans;
int n,w[N],i,j,nxt[N],x,m26,ff[20][N],lo[N],pre[N];
char c[N];
inline int ask(int x,int y){int l=lo[y-x+1];return min(ff[l][y],ff[l][x+(1<<l)-1]);}
map<int,int>mp;
ll nw;
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;++i)lo[i]=lo[i>>1]+1;
	for(i=1;i<=n;++i){
		scanf("%s%d",c+i,w+i);
		c[i]=(c[i]-'a'+m26)%26+'a';w[i]^=ans%(1<<30);
		ff[0][i]=w[i];for(j=1;1<<j<=i;++j)ff[j][i]=min(ff[j-1][i],ff[j-1][i-(1<<j-1)]);
		for(j=nxt[i-1];j && c[j+1]!=c[i];j=nxt[j]);j+=i>1 && c[j+1]==c[i];nxt[i]=j;
		pre[i-1]=c[i]==c[nxt[i-1]+1]?pre[nxt[i-1]]:i-1;
		for(j=i-1;j;)if(c[j+1]==c[i])j=nxt[pre[j]];else nw-=x=ask(i-j,i-1),--mp[x],j=nxt[j];
		if(c[1]==c[i])++mp[w[i]],nw+=w[i];
		for(;mp.rbegin()->first>w[i];mp.erase(--mp.end()))
			x=mp.rbegin()->second,nw-=1ll*(mp.rbegin()->first-w[i])*x,mp[w[i]]+=x;
		m26=(m26+nw)%26;ans+=nw;
		ans.print();
	}
	return 0;
}