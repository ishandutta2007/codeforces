#include<bits/stdc++.h>
using namespace std;

long long int sum[300002],a[300001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sum[0]=a[n];
	for(int i=1;i<n-1;i++)
		sum[i]=sum[i-1]+a[n-i];
	long long int ans=sum[n-2]+a[1];
	sort(sum,sum+n-1,greater<long long int>());
	for(int i=0;i<k-1;i++)
		ans+=sum[i];
	cout<<ans<<endl;
}