#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a[500001];
ll pre[500001];
ll suf[500001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll ans=0;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	map<long long int,int> M;
	ll cnt=0;
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]+a[i];
		if(suf[i]*3==sum)	cnt++;
	}
	ll cur=0;
	if(suf[1]*3==sum)	cnt--;
	for(int i=1;i<=n-2;i++){
		cur+=a[i];
		if(suf[i+1]*3==sum)	cnt--;
		if(cur*3==sum)	ans+=cnt;
	}
	cout<<ans<<endl;
	

	
}