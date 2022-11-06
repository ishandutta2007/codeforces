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
using ll =long long int;
ld dis(pair<int,int>a,pair<int,int>b){
	ld dx=a.first-b.first;
	ld dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}
vector<int>manacher(string st){
	string x;
	for(int i=0;i<st.size();++i){
		x.push_back(st[i]);
		if(i==st.size()-1){

		}else{
			x.push_back(' ');
		}
	}
	st=x;
	auto S=st;
	int c=0;
	vector<int>R(st.size());
	for (int i = 0; i < S.size(); ++i) {
		int l = c - (i-c);
		if (i+R[l] < c+R[c]) {
			R[i] = R[l];
		} else {
			int j = c+R[c] - i;
			while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
			R[i] = j;
			c = i;
		}
	}
	for(int i=0;i<st.size();++i){
		if(i%2==0){
			if(R[i]%2==0)R[i]--;
		}else{
			if(R[i]%2==1)R[i]--;
		}
	}
	return R;
}
using ll = long long int;
using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	static const ll add0 = 1000010007, add1 = 1003333331;
	static const ll mod0 = 1000000007, mod1 = 1000000009;

	size_t len=0;
	//vector<ll> hash_, hash2_;
	vector<ha>hash_;
	//static vector<ll> pmo_, pmo2_;
	static vector<ha>pmo_;
	void init(const vector<ll>& s) {
		hash_.resize(len+s.size()+ 1);
		hash_[0] = make_pair(0, 0);

		if (pmo_.empty()) {
			pmo_.push_back(make_pair(1, 1));
		}
		while (pmo_.size() <= len+s.size()) {
			pmo_.push_back(make_pair(pmo_.back().first*mul0%mod0, pmo_.back().second*mul1%mod1));
		}
		for (unsigned int i = 0; i < s.size(); ++i) {
			int id=i+len;
			hash_[id + 1] = make_pair((hash_[id].first * mul0 + s[i])%mod0, (hash_[id].second*mul1 + s[i])%mod1);
		}
		len += s.size();

		return;
	}
	void init(const string& s) {
		vector<ll>v;
		for (char c : s) {
			v.push_back(c);
		}
		init(v);
	}
	ha hash(const int l, const int r)const { // s[l..r]
		auto p=make_pair(hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first,
			hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second);
		
		p.first%=mod0;
		p.second%=mod1;
		if(p.first<0)p.first+=mod0;
		if(p.second<0)p.second+=mod1;

		return p;
	}
	ha  hash()const { // s[all]
		return hash(0, len - 1);
	}

	static ha concat(const ha L, const ha R, const int RLength) { // hash(L+R) 
		return make_pair((R.first + L.first*pmo_[RLength].first)%mod0, (R.second + L.second*pmo_[RLength].second)%mod1);
	}

	ha get_changed_hash(const int index, const ll from, const ll to)const {
		const ha p(hash());
		return make_pair(
			(p.first + (to - from) * pmo_[len - index - 1].first)%mod0,
			(p.second + (to - from) * pmo_[len - index - 1].second)%mod1);
	}
};
vector<ha> RollingHash::pmo_;
int main() {
	
	ios::sync_with_stdio(false);

	string st;cin>>st;
	const int N=st.size();
	RollingHash rh1,rh2;
	rh1.init(st);
	reverse(st.begin(),st.end());
	rh2.init(st);
	reverse(st.begin(),st.end());
	auto R=manacher(st);
	//WHATS(R)
	vector<int>ls(st.size()+1);
	int al=0;
	for(int len=1;len<=st.size();++len){
		auto ah=rh2.hash(0,len-1);
		while(al+len<=N-len){
			if(rh1.hash(al,al+len-1)==ah){
				break;
			}else{
				al++;
			}
		}
		if(al+len<=N-len){
			ls[len]=al;
		}else{
			ls[len]=N+1;
		}
	}
	//WHATS(ls)
	auto manas=manacher(st);
	int sum=0;
	vector<pair<int,int>>answer;
	for(int m=0;m<N;++m){
		int x=R[2*m]/2;
		int ok=0;
		int ng=N;
		//WHATS(m)
		//WHATS(x)
		while(ok+1!=ng){
			//WHATS(ok)
			//WHATS(ng)
			int amid=(ok+ng)/2;
			int ar=N-amid;
			int al=ls[amid]+amid;
			//WHATS(ar)
			//WHATS(al)
			if(al<=m-x&&m+x+1<=ar){
				ok=amid;
			}else{
				ng=amid;
			}
		}
		//cout<<ok<<endl;
		vector<pair<int,int>>nanswer;
		nanswer.push_back(make_pair(m-x,2*x+1));
		if(ok){
			nanswer.push_back(make_pair(ls[ok],ok));
			nanswer.push_back(make_pair(N-ok,ok));
		}
		//WHATS(nanswer)
		if(sum<ok*2+2*x+1){
			sum=ok*2+2*x+1;
			answer=nanswer;
		}
		int al=ls[ok];

	}
	//WHATS(answer)
	sort(answer.begin(),answer.end());
	cout<<answer.size()<<endl;
	for(int i=0;i<answer.size();++i){
		cout<<answer[i].first+1<<' '<<answer[i].second<<endl;
	}
	return 0;
}