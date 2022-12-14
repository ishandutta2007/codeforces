#include<bits/stdc++.h>
using namespace std;

int a[200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k1,k2,k3;
	cin>>k1>>k2>>k3;
	int n=k1+k2+k3;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+k1+1);
	sort(a+k1+1,a+k1+k2+1);
	sort(a+k1+k2+1,a+k1+k2+k3+1);
	vector<int> dp;
	for(int i=1;i<=n;i++){
		auto it=upper_bound(dp.begin(),dp.end(),a[i]);
		if(it==dp.end())
			dp.emplace_back(a[i]);
		else
			*it=a[i];
	}
	cout<<n-dp.size()<<endl;
}