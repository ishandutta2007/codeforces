#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


string test(string st, vector<int>v) {
	for (auto c : v) {
		string aa=st.substr(st.size()-c);
		reverse(aa.begin(),aa.end());
		st=aa+st.substr(0,st.size()-c);
	}
	return st;
}

int main() {
	int K;cin>>K;
	string A,B;cin>>A>>B;
	string pre_A=A;
	string pre_B=B;
	bool ok=true;
	map<char,int>mp;
	for (auto c : A) {
		mp[c]++;
	}
	for (auto c : B) {
		mp[c]--;
	}
	for (auto m : mp) {
		if (m.second != 0) {
			ok=false;
		}
	}
	if (ok) {
		vector<int>all_anss;
		for (int i = 0; i < A.size(); ++i) {
			vector<int> anss;
			int num=(A.size()+1)/2-1;

			if(i%2)num-=(i+1)/2;
			else num+=(i+1)/2;

			if(num==-1)break;
			//cout<<num<<endl;
			if (A[i] == B[num]) {
				anss.push_back(A.size()-i);
				anss.push_back(A.size());
			}
			else {
				int t=A.find(B[num],i);
				anss.push_back(A.size()-t);
				anss.push_back(t-i);
				anss.push_back(A.size());
			}
			string next=test(A,anss);
			A=next;
			all_anss.insert(all_anss.end(),anss.begin(),anss.end());
		}
		//cout<<A<<endl;
		cout<<all_anss.size()<<endl;
		for (int i = 0; i < all_anss.size(); ++i) {
			cout<<all_anss[i];
			if(i==all_anss.size()-1)cout<<endl;
			else cout<<" ";
		}
	}
	else {
		cout<<-1<<endl;
	}
	return 0;
}