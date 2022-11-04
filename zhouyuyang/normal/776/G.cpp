#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[17][66666][17];
ll a[17];
ll trans(char *s){
	int len=strlen(s);
	ll ans=0;
	for (int i=0;i<len;i++)
		if (s[i]<='9')
			ans=ans*16+s[i]-'0';
		else ans=ans*16+s[i]-'a'+10;
	return ans;
}
ll dfs(int dep,int v,int mx,bool tp){
	if (!dep){
		if ((1<<mx)&v) return 1;
		return 0;
	}
	if (!tp&&f[dep][v][mx]!=-1)
		return f[dep][v][mx];
	ll ans=0;
	for (int i=0;i<=(tp?a[dep]:15);i++)
		ans+=dfs(dep-1,(v*16+i)&65535,max(mx,i),tp&(i==a[dep]));
	if (!tp) f[dep][v][mx]=ans;
	return ans;
}
ll work(ll x){
	int top=0;
	for (;x;a[++top]=x%16,x/=16);
	return dfs(top,0,0,1);
}
int main(){
	int T;
	scanf("%d",&T);
	memset(f,-1,sizeof(f));
	while (T--){
		char s[20];
		ll ans=0,x;
		scanf("%s",s);
		x=trans(s)-1;
		ans=-work(x);
		scanf("%s",s);
		x=trans(s);
		printf("%lld\n",ans+work(x));
	}
}