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
using ll =unsigned long long ;	
vector<vector<int>>chs;
vector<int>ds;
vector<int>answers;
vector<int>ops;
void dfs(int now){
	ds[now]=0;
	for(auto e:chs[now]){
		dfs(e);
		ds[now]=max(ds[now],1+ds[e]);
	}

}
void solve(int now,int next){
	answers.push_back(now);
	vector<pair<int,int>>ps;
	for(auto e:chs[now]){
		ps.push_back(make_pair(ds[e],e));
	}
	sort(ps.begin(),ps.end());
	for(int i=0;i<ps.size();++i){	
		int an=-1;
		if(i!=ps.size()-1)an=ps[i+1].second;
		else{
			an=next;
		}
		solve(ps[i].second,an);
	}
	if(next!=-1)ops.push_back(next);

}
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
#include<unordered_map>
class HashVI {  // nbVIuWFNg
public:
	size_t operator()(const vector<int> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			t = t * C + x[i];
		}
		return t;
	}
	size_t operator()(const map<ll,int>&mp) const {
		const int C = 997;      // f
		size_t t = 0;
		for(auto m:mp){
			
			t=t*C+m.first;
			t=t*(C+100)+m.second;
		}
		return t;
	}
};
vector<vector<ll>>dp;

pair<int,int> ad(pair<int,int>a,int b){
	if(b){
		return make_pair(max(1+a.second,a.first),1+a.second);
	}else{
		return make_pair(a.first+1,a.second);
	}
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<string>sts(N);
	for(int i=0;i<N;++i)cin>>sts[i];

	vector<vector<int>>dist(N,vector<int>(N));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			dist[i][j]=sts[i][j]=='1'?1:10000;
		}
		dist[i][i]=0;
	}
	for(int i=0;i<N;++i){

		for(int j=0;j<N;++j){
			for(int k=0;k<N;++k){
				dist[j][k]=min(dist[j][i]+dist[i][k],dist[j][k]);
			}
		}
	}
	int Q;cin>>Q;
	int pre=-1;
	int need=0;
	vector<int>answers;
	int afrom;
	for(int i=0;i<Q;++i){
		int k;cin>>k;k--;
		if(!i){
			answers.push_back(k);

			pre=k;
			need=0;
		}else{
			need+=dist[afrom][k];
			if(dist[pre][k]!=need){
				answers.push_back(afrom);
				pre=afrom;
				need=dist[afrom][k];
			}else{

			}
		}
		afrom=k;
		
	}
	answers.push_back(afrom);
	cout<<answers.size()<<endl;
	for(int i=0;i<answers.size();++i){
		cout<<answers[i]+1<<' ';
	}
	cout<<endl;
	return 0;	
}