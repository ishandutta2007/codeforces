#include<bits/stdc++.h>
using namespace std;

int a[200010];
int dpp[200010],dps[200010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dpp[1]=dps[n]=1;
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1])
			dpp[i]=dpp[i-1]+1;
		else
			dpp[i]=1;
	for(int i=n-1;i>=1;i--)
		if(a[i]<a[i+1])
			dps[i]=dps[i+1]+1;
		else
			dps[i]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dps[i]);
	for(int i=2;i<n;i++)
		if(a[i-1]<a[i+1])
			ans=max(ans,dpp[i-1]+dps[i+1]);
	cout<<ans<<endl;
}