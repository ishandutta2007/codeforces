#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5001];
int f[5001];
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		double x;
		cin>>x;
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		f[i]=1;
		for(int j=1; j<i; j++) if(a[i]>=a[j]) f[i]=max(f[i], f[j]+1);
		ans=max(ans, f[i]);
	}
	cout<<n-ans<<'\n';
}