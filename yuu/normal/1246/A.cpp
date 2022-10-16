#include <bits/stdc++.h>
using namespace std;
long long n;
long long p;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>p;
	long long ans=-1;
	for(long long cnt=1; cnt<=1000000; cnt++){
		long long k=n-p*cnt;
		if(k<0) break;
		if(__builtin_popcountll(k)>cnt) continue;
		if(k<cnt) continue;
		ans=cnt;
		break;
	}
	cout<<ans<<'\n';
}