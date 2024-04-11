#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<1<<endl;
		return 0;
	}
	else if(m==n){
		cout<<0<<endl;
		return 0;
	}
	else if(m<=n/2){
		cout<<m<<endl;
		return 0;
	}
	else{
		cout<<n-m<<endl;
		return 0;
	}
}