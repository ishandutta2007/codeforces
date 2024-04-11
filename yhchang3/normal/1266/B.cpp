#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long int n;
		cin>>n;
		if(n/14>=1&&n%14>=1&&n%14<=6)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
}