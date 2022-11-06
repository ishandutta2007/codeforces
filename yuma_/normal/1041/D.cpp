#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld =long double;


int main() {
	int N,H;cin>>N>>H;
	vector<pair<long long int ,long long int>>ps;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;int b;cin>>b;
		ps.push_back(make_pair(a,b));
	}
	long long int answer=0;
	int r=0;
	long long int down=0;
	long long int now_palarel=0;
	for (int l = 0; l < ps.size(); ++l) {
		while (r!=N) {
			if (r == 0) {
				now_palarel+=ps[r].second-ps[r].first;
				r++;
			}
			else {
				long long int ndown = ps[r].first-ps[r-1].second;
				if (down + ndown < H) {
					down+=ndown;
					now_palarel+=ps[r].second-ps[r].first;
					r++;
				}
				else {
					break;
				}
			}
		}
		answer=max(answer,H+now_palarel);
		if (l != N - 1) {

			now_palarel -= ps[l].second - ps[l].first;
			down -= ps[l + 1].first - ps[l].second;
		}
	}
	cout<<answer<<endl;
 	return 0;
}