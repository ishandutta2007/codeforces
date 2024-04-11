#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C[66][66];
char s[66];
int cntA[66],cntB[66];
ll best;
int r,c;
map<ll,ll> mp;
void dfs(ll x,ll y,int v1,int v2){
	ll diff=abs(x-y);
	if (best<=1||diff-C[v1][r]*C[v2][r]>=best)
		return;
	if (v1==r-1&&v2==r-1){
		best=min(best,diff);
		return;
	}
	if (v1>=r){
		ll s1=C[v1][r]-C[v1-1][r];
		ll s2=C[v2][r];
		dfs(x,y+s1*s2,v1-1,v2);
	}
	if (v2>=r){
		ll s1=C[v1][r];
		ll s2=C[v2][r]-C[v2-1][r];
		dfs(x+s1*s2,y,v1,v2-1);
	}
}
ll solve(ll x,ll y,int v1,int v2){
	ll diff=abs(x-y);
	ll sta=(x-y)*10000+v1*100+v2; 
	if (mp.find(sta)!=mp.end())
		return mp[sta];
	ll &ans=mp[sta];
	if (diff-C[v1][r]*C[v2][r]>best)
		return ans=0;
	if (v1<r||v2<r){
		if (v1>=cntA[v1+v2]&&v2>=cntB[v1+v2]){
			int sum=v1+v2;
			v1-=cntA[sum];
			v2-=cntB[sum];
			return ans=C[v1+v2][v1];
		}
		return ans=0;
	}
	ans=0;
	char c=s[v1+v2-1];
	if (c!='B'){
		ll s1=C[v1][r]-C[v1-1][r];
		ll s2=C[v2][r];
		ans+=solve(x,y+s1*s2,v1-1,v2);
	}
	if (c!='A'){
		ll s1=C[v1][r];
		ll s2=C[v2][r]-C[v2-1][r];
		ans+=solve(x+s1*s2,y,v1,v2-1);
	}
	return ans;
	
	
}
int main(){
	scanf("%d%d",&r,&c);
	for (int i=0;i<=2*(r+c);i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	ll x=0,y=0;
	int v1=r+c,v2=r+c;
	for (;v1>=r&&v2>=r;)
		if (x>y){
			ll s1=C[v1][r]-C[v1-1][r];
			ll s2=C[v2][r];
			y+=s1*s2;
			v1--;
		}
		else{
			ll s1=C[v1][r];
			ll s2=C[v2][r]-C[v2-1][r];
			x+=s1*s2;
			v2--;
		}
	best=abs(x-y);
	dfs(0,0,r+c,r+c);
	//printf("%lld",best);
	scanf("%s",s);
	for (int i=0;i<2*(r+c);i++){
		cntA[i+1]=cntA[i]+(s[i]=='A');
		cntB[i+1]=cntB[i]+(s[i]=='B');
	}
	printf("%lld",solve(0,0,r+c,r+c));
}