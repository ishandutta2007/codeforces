#include<bits/stdc++.h>
#define maxn 2001000
using namespace std;
typedef long long ll;
int n,s[maxn],t[maxn*4],id;
long long lef,rig,lefs,rigs,ans,nw;
ll cal(int pos){
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=abs(s[i]-pos);
		pos=(pos==n?1:pos+1);
	}
	return ans;
}
int main(){
	//freopen("a3.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&s[i]);
	//	s[i]=rand()%n+1;
		int x=s[i]-i;
		t[x+n]++,ans+=abs(x);
		if(x<=0)lef+=x,lefs++;
		else rig+=x,rigs++;
	}
	nw=ans;
	id=0;
	for(int i=1;i<n;++i){
		lef+=1ll*t[i+n]*i,rig-=1ll*t[i+n]*i;
		lefs+=t[i+n],rigs-=t[i+n];
		int x=s[n-i+1]-(n-i+1);
		if(x-i<=0)lef-=x,lefs--;
		else rig-=x,rigs--;
		t[x+n]--;
		x=s[n-i+1]-1;
		if(x<=0)lef+=x+i,lefs++;
		else rig+=x+i,rigs++;
		t[x+n+i]++;
		if(-lef+rig+1ll*lefs*i-1ll*rigs*i<nw)id=i;
		nw=min(nw,-lef+rig+1ll*lefs*i-1ll*rigs*i);
	}
	cout<<nw<<" "<<id;
}