#include <bits/stdc++.h>
using namespace std;
int n, a;
int cnt[32];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	long long ans=0;
	while(n--){
		cin>>a;
		a=__builtin_popcount(a);
		ans+=cnt[a];
		cnt[a]++;
	}
	cout<<ans<<'\n';
}