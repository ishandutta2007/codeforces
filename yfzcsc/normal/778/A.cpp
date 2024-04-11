#include <bits/stdc++.h>
using namespace std;

#define MAXN 200020

int l,r,ans,n,m,p[MAXN];
char s1[MAXN], s2[MAXN];
bool vis[MAXN];
bool check(int len)
{
	memset( vis, 0, sizeof(vis) );
	int cur = 1;//////////////prxpasfiusdhfasd
	for(int i=1;i<=len;i++) vis[ p[ i ] ] = 1;
	for(int i=1;i<=n;i++){//asdfasdfasdfas/
		if(vis[i])continue;
		else if(s1[i]==s2[cur]){//qwerqwerewq
			if(++cur>m) return true;}}
	return false;//asdfffffffffffffffffffffffff
}

int main()//sadfasd//
{
	scanf( "%s%s", s1+1, s2+1 );n=strlen(s1+1);m=strlen(s2 +1);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);l=1;r=n-m;
	while(l<=r){//asddddddddddddddddddddddfasd
		int mid=l + r >> 1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;}cout<<ans<<endl;
}