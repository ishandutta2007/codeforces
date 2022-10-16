#include <bits/stdc++.h>
using namespace std;
int f[100001];
int trace[100001];
long long cal(long long n){
	if(n==0) return 0;
	if(n%2) return n-cal(n-1);
	if(n==4) return 3;
	if(n%4==0) return n-cal(n-1);
	return n-cal(n/2);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	long long n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<cal(n)<<'\n';
	}
}