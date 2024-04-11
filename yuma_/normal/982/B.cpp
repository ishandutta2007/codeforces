#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld =long double;
const ld eps = 1e-9;



int main()
{
	//string st;cin>>st;
	//int a=st.find("11");
	//int b=st.find("000");
	//if (a != -1 || b != -1) {
	//	cout<<"Yes"<<endl;
	//}
	//else {
	//	cout<<"No"<<endl;
	//}

	int N;cin>>N;
	vector<pair<int,int>>ws;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		ws.push_back(make_pair(a,i));
	}
	sort(ws.begin(),ws.end());

	int a=0;
	int b=-1;

	vector<int>anss(2*N);

	string st;cin>>st;
	deque<int>dq;
	for (int i = 0; i < 2 * N; ++i) {
		if (st[i] == '0') {
			anss[i]=ws[a].second;
			dq.push_back(a);
			a++;
		}
		else {
			int k=dq.back();
			dq.pop_back();
			anss[i]=ws[k].second;
			
		}
	}
	for(auto ans:anss)cout<<ans+1<<" ";
	cout<<endl;
	return 0;
}