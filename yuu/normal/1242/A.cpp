#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	vector <long long> fact;
	for(long long i=2; i*i<=n; i++){
		if(n%i==0){
			fact.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) fact.push_back(n);
	if(fact.empty()) fact.push_back(1);
	if(fact.size()>1) fact[0]=1;
	cout<<fact[0]<<'\n';
}