#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

using ld=long double;

int main() {
	int N,K,M;cin>>N>>K>>M;
	vector<ld>as;
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		as.push_back(a);
	}
	sort(as.begin(),as.end(),greater<ld>());
	ld ans=0;
	ld sum=0;
	for (int i = 0; i < as.size(); ++i) {
		long long int cnt=i+1;
		long long int power_up=M-(as.size()-cnt);
		sum += as[i];
		if(power_up<0)continue;

		long long int atime=min(power_up,K*cnt);

		ans=max(ans,(sum+atime)/cnt);
	}
	cout<<setprecision(10)<<fixed<<ans<<endl;
	
	return 0;
}