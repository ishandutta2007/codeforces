#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<0<<endl;
		return 0;
	}
	if(a>b)	swap(a,b);
	long long int tmp=b-a;
	long long int ans=2e9;
	long long int lcm=2e18;
	for(int i=1;i*i<=tmp;i++){
		if(tmp%i)	continue;
		if(((b-1)/i+1)*i*((a-1)/i+1)<lcm){
			lcm=((b-1)/i+1)*i*((a-1)/i+1);
			ans=((a-1)/i+1)*i-a;
		}
		else if(((b-1)/i+1)*i*((a-1)/i+1)==lcm){
			ans=min(ans,((a-1)/i+1)*i-a);
		}
		i=tmp/i;
		if(((b-1)/i+1)*i*((a-1)/i+1)<lcm){
			lcm=((b-1)/i+1)*i*((a-1)/i+1);
			ans=((a-1)/i+1)*i-a;
		}
		else if(((b-1)/i+1)*i*((a-1)/i+1)==lcm){
			ans=min(ans,((a-1)/i+1)*i-a);
		}
		i=tmp/i;
	}
	cout<<ans<<endl;
}