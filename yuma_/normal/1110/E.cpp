#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

vector<int>get_sa(vector<int>v) {
	assert(!v.empty());
	vector<int>sas;
	for (int i = 0; i < v.size() - 1; ++i) {
		sas.push_back(v[i+1]-v[i]);
	}
	return sas;
}

bool check() {
	int N;cin>>N;
	vector<int>lv(N),rv(N);
	for(int i=0;i<N;++i)scanf("%d",&lv[i]);
	for(int i=0;i<N;++i)scanf("%d",&rv[i]);
	vector<int>l_sas=get_sa(lv),r_sas=get_sa(rv);

	sort(l_sas.begin(),l_sas.end());
	sort(r_sas.begin(),r_sas.end());

	bool ok=(l_sas==r_sas)&&(lv[0]==rv[0])&&(lv.back()==rv.back());

	return ok;
}
int main() {
	bool ok=check();
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}