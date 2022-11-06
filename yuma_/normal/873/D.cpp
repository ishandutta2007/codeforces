#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

vector<int>anss;

void solve(int l, int r, const vector<int>&ls,const vector<int>&rs ,const vector<int>alls,int&rest) {
	if (rest == 0||(r-l==1)) {
		if (alls.empty()) {
			for (int i = l; i < r; ++i) {
				anss[i] = i;
			}
			for (int i = 0; i < ls.size(); ++i) {
				anss[i + l] = ls[i];
			}
			for (int i = 0; i < rs.size(); ++i) {
				anss[r - 1 - i] = rs[i];
			}
		}else{
			for (int i = l; i < r; ++i) {
				anss[i]=alls[i-l];
			}
		}
		
	}else{
		rest--;
		int m((l+r)/2);
		int l_size=m-l;
		int r_size=r-m;
		if (alls.empty()&&l_size >= ls.size()+1 && r_size >= 1+ rs.size()) {
			vector<int>l_ls(ls);
			vector<int>l_rs{ m };
			vector<int>r_ls{ m - 1 };
			vector<int>r_rs{ rs };
			solve(l,m,l_ls,l_rs,alls,rest);
			solve(m,r,r_ls,r_rs,alls,rest);
		}else{
			vector<int>d_ls,d_rs;
			vector<int>nums(r-l);
			iota(nums.begin(),nums.end(),l);
			if (!alls.empty()) {
				nums=alls;
			}else{
				for (int i = 0; i < ls.size(); ++i) {
					nums[i] = ls[i];
				}
				for (int i = 0; i < rs.size(); ++i) {
					nums[(r - l) - 1 - i] = rs[i];
				}
			}
			
			swap(nums[m-l-1],nums[m-l]);
			solve(l,m,d_ls,d_rs,vector<int>(nums.begin(),nums.begin()+(m-l)),rest);
			solve(m,r,d_ls,d_rs,vector<int>(nums.begin()+(m-l),nums.end()),rest);
		}
	}
}

int main() {
	int N,K;cin>>N>>K;
	anss.resize(N);
	if (K % 2 == 0) {
		cout<<-1<<endl;
	}else{
		int rest=(K-1)/2;
		vector<int>ls,rs,alls;
		solve(0,N,ls,rs,alls,rest);
		if (rest == 0) {
			for (int i = 0; i < N; ++i) {
				cout<<anss[i]+1;
				if(i==N-1)cout<<endl;
				else cout<<" ";
			}
		}else{
			cout<<-1<<endl;	
		}
	}
	return 0;
}