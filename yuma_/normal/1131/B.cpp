#include "bits/stdc++.h"

#pragma warning(disable:4996)

//

using namespace std;

int main() {
	pair<int,int>p(0,0);
	int ans=0;
	int N;cin>>N;
	set<int>anss{ 0 };
	for (int i = 0; i < N; ++i) {
		int a,b;cin>>a>>b;
		pair<int,int>np(a,b);

		int l,r;
		if (p.first >= p.second) {
			if (np.first >= np.second) {
				 l=p.first;
				 r=np.second;

			}
			else {
				 l=p.first;
				 r=np.first;
			}
		}
		else {
			if (np.first >= np.second) {
				l=p.second;
				r=np.second;
			}
			else {
				l=p.second;
				r=np.first;
			}
		}

		if (r >= l) {
			ans += max(0, r - l - 1);
			anss.emplace(r);
			anss.emplace(l);
		}
		p=np;

	}
	int answer=ans+anss.size();
	cout<<answer<<endl;
	return 0;
}