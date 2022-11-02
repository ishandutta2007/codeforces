#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int d,mod;cin>>d>>mod;
		ll ans=1;
		for(int i=1;i<=d;i<<=1){
			if((i<<1)>d){
				ans=ans*(d-i+1+1)%mod;
			}
			else ans=ans*(i+1)%mod;
		}
		cout<<(ans+mod-1)%mod<<endl;
	}
	
}