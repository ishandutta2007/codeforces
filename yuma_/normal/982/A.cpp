#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld =long double;
const ld eps = 1e-9;



int main()
{
	int N;cin>>N;
	string st;cin>>st;
	int a=st.find("11");
	int b=st.find("000");
	if (a != -1 || b!=-1||(N==1&&st=="0")||(N!=1&&(st.substr(0,2)=="00"||st.substr(st.size()-2,2)=="00"))) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
	}

	return 0;

	/*int N;cin>>N;
	vector<vector<int>>edges(N);
	for (int i = 0; i < N; ++i) {
		int u,v;cin>>u>>v;
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	bool ok=N%2==0;
	if (find(edges.begin(), edges.end(), [](const vector<int>&v) {return v.empty(); }) != edges.end()) {
		ok=false;
	}
	if (ok) {
		cout<<edges.size()/2-
	}*/

}