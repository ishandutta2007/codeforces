#include "bits/stdc++.h"
using namespace std;
using ld= long double;

int main() {  
	int N,X,K;cin>>N>>X>>K;
	vector<int>as(N);
	long long int ans = 0;
	if (K) {
		map<int,long long int>amp,bmp;
		for (int i = 0; i < N; ++i) {
			cin >> as[i];
			if (as[i] % X) {
				amp[as[i]/X]++;
			}
			else {
				bmp[as[i]/X]++;
			}
		}
		for (auto am : amp) {
			auto it = amp.find(am.first + K);
			if (it != amp.end())ans += it->second*am.second;

			auto jt = bmp.find(am.first + K);
			if (jt != bmp.end())ans += jt->second*am.second;
		}

		for (auto bm : bmp) {
			auto it = amp.find(bm.first + K - 1);
			if (it != amp.end())ans += it->second*bm.second;

			auto jt = bmp.find(bm.first + K - 1);
			if (jt != bmp.end())ans += jt->second*bm.second;
		}
	}
	else {
		map<int,long long int>mp;
		for (int i = 0; i < N; ++i) {
			cin >> as[i];
			mp[as[i]]++;
		}
		sort(as.begin(),as.end());

		long long int num=0;
		long long int from=-1;
		for(auto m:mp){
			int aa=m.first;
			
			if (aa % X) {
				if (from == aa / X) {
					ans+=num*m.second+m.second*(m.second);
					num+=m.second;

				}
				else {
					ans+=m.second*(m.second);
					num=m.second;
					from= aa /X;
				}
			}
			else {
				num=0;
				from=-1;
			}
			
		}
	}
	
	cout<<ans<<endl;

	//int N; cin >> N;
	//vector<int>as(N);
	//for (int i = 0; i < N; ++i) {
	//	cin >> as[i];
	//}
	//int ans=360;
	//for (int l = 0; l < N; ++l) {
	//	for (int r = 0; r < N; ++r) {
	//		if (l <= r) {
	//			int t=accumulate(as.begin(),as.end(),0);
	//			ans=min(ans,180-min(t,360-t));
	//		}
	//	}
	//}
	//vector<vector<int>>oks(N + 1, vector<int>(361));
	//oks[0][0] = true;
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j <= 360; ++j) {
	//		if (oks[i][j]) {
	//			oks[i + 1][j] = true;
	//			oks[i + 1][j + as[i]] = true;
	//		}
	//	}
	//}
	//int ans = 360;
	//for (int i = 0; i <= 360; ++i) {
	//	if (oks[N][i])ans = min(ans, abs(180 - i) * 2);
	//}
	//cout << ans << endl;

	return 0;
}