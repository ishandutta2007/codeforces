#include <bits/stdc++.h>
using namespace std;
int n, m;
int bit_n[32];
int bit_m[32];
int bit_ans[32];
void solve(){
	cin>>n>>m;
	if(m<n){
		cout<<"0\n";
		return; 
	}
	//n xor x > m
	for(int i=31; i>=0; i--){
		bit_n[i]=n%2;
		n/=2;
	}
	m++;
	for(int i=31; i>=0; i--){
		bit_m[i]=m%2;
		m/=2;
	}
    //n xor ans >=m
    bool good=0;	
	for(int i=0; i<=31; i++){
		if(good) bit_ans[i]=0;
		else{
			if(bit_m[i]==0){
				bit_ans[i]=0;
				if(bit_n[i]) good=1;
			}
			else{
				bit_ans[i]=bit_n[i]^bit_m[i];
			}
		}
	}
	int ans=0;
	for(int i=0; i<=31; i++) (ans*=2)+=bit_ans[i];
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}