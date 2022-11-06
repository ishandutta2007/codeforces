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
ll mod=1e9+7;
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	string st;cin>>st;
	vector<int>v(N+1);
	v[0]=0;
	for(int i=0;i<N;++i){
		v[i+1]=st[i]=='('?1:-1;
		v[i+1]+=v[i];
	}
	if(v[N]){
		cout<<0<<endl<<1<<' '<<1<<endl;
	}else{
		int minx=*min_element(v.begin(),v.end());
		vector<int>places;
		for(int i=0;i<N;++i){
			if(v[i]==minx)places.push_back(i);
		}
		//WHATS(v)
		pair<int,pair<int,int>>answer;
		for(int i=0;i<places.size();++i){
			int l=places[i];
			int r=places[(i+1)%places.size()];
			int sum=0;
			int one_cnt=0;
			if(l>=r){
				int al=l;
				for(int ax=l+1;ax<N;++ax){
					if(v[ax]==minx+1){
						answer=max(answer,make_pair(sum,make_pair(al,ax-1)));
						al=ax;
						sum=0;
						one_cnt++;
					}
					else if(v[ax]==minx+2){	
						sum++;
					}
				}
				for(int ax=0;ax<r;++ax){
					if(v[ax]==minx+1){					
							answer=max(answer,make_pair(sum,make_pair(al,ax==0?N-1:ax-1)));

						al=ax;
						sum=0;
						one_cnt++;
					}
					else if(v[ax]==minx+2){	
						sum++;
					}
				}
			}else{
				int al=l;
				for(int ax=l+1;ax<r;++ax){
					if(v[ax]==minx+1){
						answer=max(answer,make_pair(sum,make_pair(al,ax-1)));
						al=ax;
						sum=0;
						one_cnt++;
					}
					else if(v[ax]==minx+2){	
						sum++;
					}
				}
			}
			answer=max(answer,make_pair(one_cnt-int(places.size()),make_pair(l,r-1)));
		}
		answer.first+=places.size();
		if(answer.second.second==-1)answer.second.second+=N;
		cout<<answer.first<<endl;
		cout<<answer.second.first+1<<' '<<answer.second.second+1<<endl;
	}
	return 0;	
}