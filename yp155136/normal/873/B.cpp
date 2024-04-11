#include <iostream>
#include <set>
#include <map>
using namespace std;

int pre[123456];

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s=" "+s;
	for (int i=1;n>=i;i++) {
		pre[i] = pre[i-1] + (s[i]-'0');
		if (s[i]=='0') pre[i]--;
	}
	map<int,int> mp;
	for (int i=2;n>=i;i+=2) {
		mp[pre[i]] = max(mp[pre[i]],i);
//		cout<<"i = "<<i<<" , perr = "<<pre[i]<<endl;
	}
	int ans=mp[0];
	for (int i=2;n>=i;i+=2) {
		ans = max(ans,mp[pre[i]]-i);
	}
	mp.clear();
	for (int i=1;n>=i;i+=2) {
		mp[pre[i]] = max(mp[pre[i]],i);
	}
	for (int i=1;n>=i;i+=2) {
		ans = max(ans,mp[pre[i]]-i);
	}
	cout<<ans<<endl;
}