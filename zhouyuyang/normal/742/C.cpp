#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
int nxt[140],fa[140],vis[140],flag=1,n;
ll ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&nxt[i]);
	for (int i=1;i<=n;i++)
		if (!fa[i]){
			int now=i,cot=0;
			for (;!fa[nxt[now]];cot++,now=nxt[now])
				fa[nxt[now]]=now;
			if (now!=i||!fa[now]){
				flag=0;
				continue;
			}
			if (cot&1){
				if (!ans) ans=cot;
				else ans=lcm(ans,(ll)cot);
			}
			else{
				if (!ans) ans=cot/2;
				else ans=lcm(ans,(ll)cot/2);
			}
		}
	if (flag) printf("%I64d",ans);
	else printf("-1");
}