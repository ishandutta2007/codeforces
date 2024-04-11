#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
using namespace std; 
ll a[30],fac[30],S,ans;
map<ll,ll> ma[30];
int n,K,half;
void dfs1(int x,ll s,int k){
	if (x>half){
		ma[k][s]++;
		return;
	}
	dfs1(x+1,s,k);
	if (s+a[x]<=S) dfs1(x+1,s+a[x],k);
	if (k<K&&a[x]<=20&&s+fac[a[x]]<=S) dfs1(x+1,s+fac[a[x]],k+1);
}
void dfs2(int x,ll s,int k){
	if (x>n){
		for (int i=k;i<=K;i++)
			if (ma[i-k].count(S-s))
				ans+=ma[i-k][S-s];
		return;
	}
	dfs2(x+1,s,k);
	if (s+a[x]<=S) dfs2(x+1,s+a[x],k);
	if (k<K&&a[x]<=20&&s+fac[a[x]]<=S) dfs2(x+1,s+fac[a[x]],k+1);
} 
int main(){
	for (int i=fac[0]=1;i<=20;i++) fac[i]=fac[i-1]*i;
	scanf("%d%d%I64d",&n,&K,&S);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1){
		if (a[1]==S) ++ans;
		if (a[1]<=20&&fac[a[0]]==S) ++ans;
		printf("%I64d",ans);
		return 0;
	}
	half=n/2;
	dfs1(1,0,0);
	dfs2(half+1,0,0);
	printf("%I64d",ans);
}