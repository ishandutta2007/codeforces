#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int n;
	cin>>n;
	long long int ans=0;
	if(n&1){
		for(long long int i=2;i*i<=n;i++){
			if(n%i==0){
				n-=i;
				break;
			}
		}
		if(n&1){
			cout<<1<<endl;
		}
		else{
			cout<<n/2+1<<endl;
		}
	}
	else{
		cout<<n/2<<endl;
	}
}