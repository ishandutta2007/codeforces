#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,p,q;
	string s;
	cin>>n>>p>>q;
	cin>>s;
	for(int i=0;i<=n/p;i++){
		if((n-i*p)%q==0){
			cout<<i+(n-i*p)/q<<endl;
			for(int j=0;j<i;j++){
				cout<<s.substr(j*p,p)<<endl;
			}
			for(int j=0;j<(n-i*p)/q;j++){
				cout<<s.substr(i*p+j*q,q)<<endl;
			}
			return 0;
		}
	}
	puts("-1");
}