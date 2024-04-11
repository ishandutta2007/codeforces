#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

using poly=vector<int>;

poly kake(poly p) {
	p.insert(p.begin(),0);
	return p;
}

poly tasu(poly p, poly p2) {
	poly ans(max(p.size(),p2.size()));
	for (int i = 0; i < ans.size(); ++i) {
		if(i<p.size())ans[i]+=p[i];
		if(i<p2.size())ans[i]+=p2[i];
	}
	return ans;
}

bool check(poly p) {
	return all_of(p.begin(), p.end(), [](const int a) {return abs(a) <= 1; });
}

void out(poly p) {
	cout<<p.size()-1<<endl;
	for (int i = 0; i < p.size(); ++i) {
		cout<<p[i];
		if(i==p.size()-1)cout<<endl;
		else cout<<" ";
	}
	return ;
}

int main() {
	int N;N=200;
	vector<poly>polys;
	polys.push_back(poly{ 1 });
	polys.push_back(poly{ 0,1 });

	for (int i = 0; i < N; ++i) {
		poly p1(polys[polys.size()-2]);
		poly p2(polys[polys.size()-1]);

		poly p3(kake(p2));
		bool flag=false;
		{

			poly ansp3(tasu(p1, p3));
			if (check(ansp3)) {
				polys.push_back(ansp3);
				flag=true;
			}
		}
		if(!flag){
			for (auto& a : p3) {
				a=-a;
			}

			poly ansp3(tasu(p1, p3));
			if (check(ansp3)) {
				polys.push_back(ansp3);
			}
		}
		
	}
	int num;cin>>num;

	if (polys[num][polys[num].size() - 1] == -1) {
		for (auto& a : polys[num]) {
			a=-a;
		}
	}
	if (polys[num-1][polys[num-1].size() - 1] == -1) {
		for (auto& a : polys[num-1]) {
			a = -a;
		}
	}
	out(polys[num]);
	out(polys[num-1]);
	return 0;
}