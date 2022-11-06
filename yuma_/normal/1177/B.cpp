#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main() {
	ll K;cin>>K;K--;
	ll keta=1;
	ll num=9;
	ll start=1;

	int ans=-1;
	while(true){
		ll use=keta*num;
		if(K>=use){
			K-=use;
			keta+=1;
			num*=10;
			start*=10;
		}else{
			ll place=K/keta;
			ll po=K%keta;
			string st=to_string(start+place);
			ans=st[po]-'0';
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}