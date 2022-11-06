#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}

using ll = long long int;
int N,K;
vector<int>nums;
vector<vector<int>>g;
int sum=0;
vector<int>szs;
vector<int>ok_cnts;
vector<int>sums;
vector<int>lens;
vector<int>anss;
void dfs(int now,int from,vector<int>&oks){
	szs[now]=1;
	if(oks[now]){
		ok_cnts[now]=1;
	}
	vector<int>v{0,0};
	for(auto e:g[now]){
		if(e==from)continue;

		dfs(e,now,oks);
		szs[now]+=szs[e];
		ok_cnts[now]+=ok_cnts[e];

		if(szs[e]==ok_cnts[e]){
			sums[now]+=szs[e];
		}else{
			v.push_back(lens[e]);
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	if(oks[now]){
		int nans=0;
		if(N-szs[now]==sum-ok_cnts[now]){
			nans+=N-szs[now];
		}
		//WHATS(v)
		nans+=1+sums[now]+v[0]+v[1];
		lens[now]=sums[now]+v[0]+1;
		anss[now]=nans;
	}
	
}
bool check(int amid){
	sum=0;
	szs=vector<int>(N);
	ok_cnts=vector<int>(N);
	sums=vector<int>(N);
	lens=vector<int>(N);
	anss=vector<int>(N);
	vector<int>oks(N);
	for(int i=0;i<N;++i){
		if(amid<=nums[i]){
			oks[i]=true;
			sum++;
		}
	}
	//WHATS(oks)
	dfs(0,-1,oks);
	//WHATS(anss)
	if(*max_element(anss.begin(),anss.end())>=K)return true;
	else return false;
}
vector<int>l_lens(10),r_lens(10);

int main() {
	
	ios::sync_with_stdio(false);
	int N;cin>>N;
	while(N--){
		string a,b;cin>>a>>b;
		vector<int>oks(26);
		for(auto c:a){
			oks[c-'a']=1;
		}
		bool ans=false;
		for(auto c:b){
			if(oks[c-'a'])ans=true;
		}
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}