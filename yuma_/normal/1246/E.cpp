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
	
#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
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

int main() {
	ios::sync_with_stdio(false);
	int N,K;cin>>N>>K;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	dp=vector<vector<ll>>(1<<N,vector<ll>(101));;
	dp[0][0]|=1;
	
	int tt=0;
	while(tt+K<=2000)tt+=K;;
	for(int id=0;id<(1<<N);++id){
		int np=tt/K;
		for(int p=tt;p>=0;p-=K){
			if(dp[id][p>>6]&(1ull<<(p&63))){
				dp[id][np>>6]|=(1ull<<(np&63));
			}
			np--;
		}
		for(int use=0;use<N;++use){
			int x=v[use];
			if((id&(1<<use))==0){
				int nid=id|(1<<use);
				for(int l=0;l<50;++l){
					int mo=x&63;
					int sa=x>>6;
					
					dp[nid][l+sa]|=dp[id][l]<<mo;
					if(dp[id][l])WHATS(dp[nid][l+sa])
					dp[nid][l+sa+1]|=dp[id][l]>>(64-mo);
				}
			}
		}
		
	}
	WHATS(dp)
	if(dp[(1<<N)-1][0]&2){
		cout<<"YES"<<endl;

		int id=(1<<N)-1;
		int num=1;
		vector<int>answer;
		while(!(id==0&&num==0)){
				WHATS(answer)
			WHATS(id)
			WHATS(num)
			if(num*K<=32000){
				int np=num*K;
				if(dp[id][np>>6]&(1ull<<(np&63))){
					num=np;
					answer.push_back(-1);
					continue;
				}
			}
			bool ok=false;
			for(int use=0;use<N;++use){
				
				if((1<<use)&id){
					int nid=id^(1<<use);
					int pre=num-v[use];
					if(pre<0)continue;
					if(dp[nid][pre>>6]&(1ull<<(pre&63))){
						id=nid;
						num=pre;
						answer.push_back(use);

						ok=true;
						break;
					}
				}
			}
			
			if(!ok)assert(false);
		}
		WHATS(answer)
		vector<pair<int,int>>mp;
		int cnt=0;
		for(int i=0;i<answer.size();++i){
			if(answer[i]==-1){
				cnt++;
			}else{
				mp.push_back(make_pair(cnt,v[answer[i]]));
			}
		}
		vector<pair<ll,ll>>oks;
		while(mp.size()>=2){
			WHATS(mp)
			sort(mp.begin(),mp.end());
			auto ap=mp.back();mp.pop_back();
			auto bp=mp.back();mp.pop_back();
			assert(ap.first==bp.first);
			oks.emplace_back(ap.second,bp.second);
			{
				pair<int,int>cp=make_pair(ap.first,ap.second+bp.second);
				while(cp.second%K==0){
					cp.second/=K;
					cp.first--;
				}
				mp.push_back(cp);
			}
		}
		for(auto p:oks){
			cout<<p.first<<' '<<p.second<<endl;
		}
	}else{
		cout<<"NO"<<endl;
	}
	return 0;	
}