#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans;
int main(){
	cin>>n>>k;
	if(n>=k)ans=(k-1)/2;
		else ans=max(min((k-1)/2,n-1)-(k-n)+1,0ll);
	cout<<ans<<endl;
	return 0;
}