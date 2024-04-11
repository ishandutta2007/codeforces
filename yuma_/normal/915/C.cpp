#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

vector<vector<long long int>>memo(1<<20,vector<long long int>(2,-3));

long long int solve(bitset<20>&used,int now,string &ast, string &bst,bool flag) {
	if (memo[used.to_ulong()][flag]!=-3) {
		return memo[used.to_ulong()][flag];
	}
	long long int ans=-2;
	if (now == -1) {
		if(flag)ans=-1;
		else ans=-2;
		return memo[used.to_ulong()][flag]=ans;
	}
	for (int i = 0; i < ast.size(); ++i) {
		if(used[i])continue;
		else {
			used[i]=true;
			int nflag ;
			if (ast[i] == bst[now]) {
				nflag=flag;
			}
			else if (ast[i] < bst[now]) {
				nflag=true;
			}
			else {
				nflag=false;
			}

			long long int num=solve(used,now-1,ast,bst,nflag);
			if (num == -2) {
				ans=max(ans,-2ll);
			}
			else if (num == -1) {
				ans=max(ans,static_cast<long long int>(ast[i]-'0'));
			}
			else {
				ans=max(ans,10*num+static_cast<long long int>(ast[i]-'0'));
			}
			used[i]=false;
		}
	}

	return memo[used.to_ulong()][flag]=ans;
}

int main() {

	string ast,bst;cin>>ast>>bst;
	if (ast.size() == bst.size()) {
		long long int ans;
		bitset<20>used;
		ans = solve(used, ast.size() - 1, ast, bst, true);
		cout << ans << endl;

	}
	else {
		sort(ast.begin(),ast.end(),greater<char>());
		cout<<ast<<endl;
	}
	
	return 0;
}