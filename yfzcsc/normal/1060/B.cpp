#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll x){
	ll ans=0;
	while(x)ans+=x%10,x/=10;
	return ans;
}
int main(){
	ll n;
	cin>>n;
	ll sum=0,ans=0;
	if(n<10){
		cout<<n;
	} else {
		sum=9;
		while(sum*10+9<=n)sum=sum*10+9;
		cout<<cal(sum)+cal(n-sum);
	}
}