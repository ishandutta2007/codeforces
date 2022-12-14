#include<bits/stdc++.h>
using namespace std;

long long int a[200000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	long long int l=1,r=2e9;
	while(l<r){
		long long int mid = (l+r+1)/2;
		long long int cnt=0;
		for(int i=n/2;i<n;i++)
			cnt+=max(mid-a[i],0LL);
		if(cnt<=k)
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}