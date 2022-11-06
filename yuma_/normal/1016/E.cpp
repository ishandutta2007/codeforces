#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = double;
const ld eps = 1e-9;

#include<unordered_map>

pair<int,ld>solve(const vector<pair<ld, ld>>&lines, ld ly, ld lx, ld py, ld px) {

	int amin = 0;
	int amax = lines.size();

	ld kx = lx + (px - lx) / (py - ly)*(-ly);

	int line_id = lower_bound(lines.begin(), lines.end(), make_pair(kx, 0.0)) - lines.begin();
	ld sec=0;
	if (line_id) {
		sec=min(lines[line_id-1].second,kx)-lines[line_id-1].first;
	}
	return make_pair(line_id,sec);
}

int main() {
	ld Y, L, R; cin >> Y >> L >> R;

	int a; cin >> a;
	vector<pair<ld,ld>>ps;
	ps.emplace_back(-2,-2);
	vector<ld>sums(a+2);
	sums[0]=0;
	sums[1]=0;
	for (int i = 0; i < a; ++i) {
		int l,r;
		scanf("%d %d",&l,&r);
		ps.emplace_back(l,r);
		sums[i+2]=sums[i+1]+(r-l);
	}
	int Q;cin>>Q;
	while (Q--) {
		int ay,ax;
		scanf("%d %d",&ax,&ay);
		ld y(ay),x(ax);

		auto rp=solve(ps,Y,R,y,x);
		auto lp=solve(ps,Y,L,y,x);

		ld wall_len=sums[rp.first-1]-sums[lp.first-1]+rp.second-lp.second;

		ld total_len=(R-L)/(y-Y)*y;

		ld ans=(R-L)*wall_len/total_len;
		//cout<<setprecision(10)<<fixed<<ans<<endl;
		printf("%.9f\n",ans);
		
	}
	return 0;
}