#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;


int main() { 
	string st;cin>>st;
	int one_num=count(st.begin(),st.end(),'1');
	int zero_num=st.size()-one_num;

	vector<vector<int>>anss;
	if(one_num>=zero_num){


	}else{
		anss.resize(zero_num-one_num);

		queue<int>zero_q,one_q;
		for(int i=0;i<anss.size();++i){
			zero_q.push(i);
		}

		for(int i=0;i<st.size();++i){
			if(st[i]=='0'){
				if(zero_q.empty()){
					anss.clear();
					break;
				}else{
					int n(zero_q.front());
					zero_q.pop();
					anss[n].push_back(i+1);
					one_q.push(n);
				}
			}else{
				if(one_q.empty()){
					anss.clear();
					break;
				}else{
					int n(one_q.front());
					one_q.pop();
					anss[n].push_back(i+1);
					zero_q.push(n);
				}
			}
		}
	}
	if(anss.empty()){
		cout<<-1<<endl;
	}else{
		cout<<anss.size()<<endl;
		for(int i=0;i<anss.size();++i){
			cout<<anss[i].size();
			for(int j=0;j<anss[i].size();++j){
				cout<<" "<<anss[i][j];
			}
			cout<<endl;
			 
		}
	}
	return 0;
}