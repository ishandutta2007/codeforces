#include"bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}
int main() {
	int N;cin>>N;
	auto mp(soinnsuu(N));
	int num=prev(mp.end())->first;

	long long int ans=N;
	for(int x=N-num+1;x<=N;++x){
		auto so(soinnsuu(x));
		int num=x-prev(so.end())->first+1;
		if(num==1)continue;
		ans=min(ans,x-(prev(so.end())->first)+1);
	}
	cout<<ans<<endl;
	return 0;
}