#include <iostream>
#include <unordered_map>
#define re register
#define ll long long
using namespace std;
const int MAXN=2e5+1;
unordered_map<ll,bool>mp;
ll n,a,sm,ans;
int main(){
	cin>>n;mp[0]=1;
	for(re int i=1;i<=n;i++){
		cin>>a;sm+=a;
		if(mp[sm])mp.clear(),++ans,mp[0]=1,sm=a;
		mp[sm]=1;
	}
	return cout<<ans,0;
}