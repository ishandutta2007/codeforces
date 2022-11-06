#include "bits/stdc++.h"
using namespace std;
using ld=long double;
#pragma warning(disable:4996)

int main() { 
	int N,K;cin>>N>>K;
	vector<int>as(N);
	for (int i = 0; i < N; ++i) {
		cin>>as[i];
	}
	vector<int>maxs(N);
	bool ok=true;
	{
		int now=K;
		for (int i = N - 1; i >= 0; --i) {
			now-=as[i];
			now=min(K,now);
			maxs[i]=now;
			
		}
		if(maxs[0]<0)ok=false;
	}
	
	int ans=0;
	int now=0;
	for (int i = 0; i < N; ++i) {
		if (as[i] == 0) {
			if (now < 0) {
				ans++;
				if(maxs[i]<0)ok=false;
				now=maxs[i];
			}
		}
		else {
			now=now+as[i];
		}
	}
	if(ok)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}