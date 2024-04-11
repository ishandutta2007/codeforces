#include<bits/stdc++.h>
#define ll long long
#define N 10000005
using namespace std;
int n,sbad,phi[N];
int pri[N],di[N],pref[N];
bool bad[N];
void prepare(){
	for (int i=1;i<=n;i++) phi[i]=i;
	for (int i=2;i<=n;i++){
		if (pri[i]) continue;
		for (int j=i;j<=n;j+=i){
			if (!pri[j]) pri[j]=i;
			phi[j]-=phi[j]/i;
		}
	}
	for (int i=1;i<=n;i++)
		if (i==1||(pri[i]==i&&2*i>n))
			bad[i]=1,sbad++;
	for (int i=2;i<=n;i++)
		if (pri[i]==i) di[i]=1;
		else if (pri[i/pri[i]]==pri[i])
			di[i]=di[i/pri[i]];
		else di[i]=di[i/pri[i]]+1;
}
ll ask1(){
	ll ans=0;
	for (int i=2;i<=n;i++)
		if (!bad[i]) ans+=i-1-phi[i];
	return ans;
}
ll ask2(){
	ll ans=0;
	int pre=1;
	for (int i=2;i<=n;i++)
		if (pri[i]!=i){
			ans+=phi[i];
			ans-=pre;
			ans+=di[i];
		}
		else pre++;
	for (int i=1;i<=n;i++)
		if (!bad[i]) pref[pri[i]]++;
	for (int i=1;i<=n;i++)
		pref[i]+=pref[i-1];
	for (int i=2;i<=n;i++){
		if (pri[i]!=i||bad[i]) continue;
		ans+=pref[n/i];
		for (int j=i;j<=n;j+=i)
			if (pri[j]<=n/i) --ans;
	}
	for (int i=2;i<=n;i++){
		int a=pri[i],b=i/a;
		if (b!=1&&pri[b]==b&&a!=b) ans--;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	prepare();
	ll ans1=ask1();
	ll ans2=ask2();
	ll ans3=1ll*(n-sbad)*(n-sbad-1)/2-ans1-ans2;
	printf("%I64d",ans1+ans2*2+ans3*3);
}