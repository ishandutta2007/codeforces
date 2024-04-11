#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

struct aa {
	long  long int s;
	long long int h;
	
};

int main() {
	int N;cin>>N;
	long long int ans=0;
	vector<aa>aas;
	for (int i = 0; i < N; ++i) {
		string st;cin>>st;
		long long int s_num=0;
		for (auto c : st) {
			if (c == 's') {
				s_num++;
			}
			else {
				ans+=s_num;
			}
		}
		aas.push_back(aa{ s_num,int(st.size()) - s_num });
	}
	sort(aas.begin(), aas.end(), [](const aa&l, const aa&r) {
		if(l.h==0&&r.h==0)return false;
		if(l.h==0)return true;
		else if(r.h==0)return false;
		else {
			return ld(l.s)/l.h>ld(r.s)/r.h;
		}
	});
	long long int now_snum=0;
	for (auto a : aas) {
		ans+=now_snum*a.h;
		now_snum+=a.s;
	}
	cout<<ans<<endl;
	return 0;
}