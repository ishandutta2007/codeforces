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
	
using ll=long long ;


const ll mod=129402307;
vector<int>modv{1,2,9,4,0,2,3,0,6};
vector<int>modv2{1,2,9,4,0,2,3,0,7};

vector<int>solve(vector<int>l,vector<int>r){
	swap(l,r);
	for(int i=0;i<=int(r.size())-int(l.size());++i){
		while(true){
			bool ok=true;
			if(i&&r[i-1]){

			}else{
				for(int j=0;j<l.size();++j){
					if(l[j]<r[i+j])ok=true;
					else if(l[j]>r[i+j])ok=false;
				}
			}
			
			if(ok){
				for(int j=0;j<l.size();++j){
					r[i+j]-=l[j];
				}
				for(int j=l.size()-1;j>=0;--j){
					if(r[i+j]<0){
						r[i+j]+=10;
						assert(i+j>0);
						r[i+j-1]--;
					}
				}
			}else{
				break;
			}
		}
	}
	if(r.size()<l.size())return r;
	return vector<int>(r.end()-l.size(),r.end());
}

ll mod_pow(ll a, ll b){
	if(b==0)return a==0?0:1;
	else{
		ll xx=mod_pow(a,b/2);
		xx*=xx;
		xx%=mod;

		if(b%2){
			xx*=a;
			xx%=mod;
		}
		return xx;
	}
}
struct query{
	int type;
	int l;
	int r;
	ll cnt;
	int id;
};

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<query>qs;
	for(int i=0;i<N;++i){
		int l,r;cin>>l>>r;
		qs.push_back(query{1,l-1,r,1,i});
	}
	int M;cin>>M;
	for(int i=0;i<M;++i){
		int l,r,c;cin>>l>>r>>c;
		qs.push_back(query{0,l-1,r,c,i});
	}
	sort(qs.begin(),qs.end(),
	[](const query&l,const query&r){
		return l.l==r.l?l.type<r.type:l.l<r.l;
	});
	map<pair<int,int>,ll>mp;
	bool ok=true;
	vector<int>anss(N);
	for(auto q:qs){
		if(q.type==1){
			auto it=mp.upper_bound(make_pair(q.r,-1));
			if(it!=mp.end()){
				it->second--;
				anss[q.id]=it->first.second;

				if(it->second==0){
					mp.erase(it);
				}
			}else{
				ok=false;
				break;
			}
		}else{
			mp[make_pair(q.r,q.id)]+=q.cnt;
		}
	}
	if(ok){
		cout<<"YES"<<endl;
		for(int i=0;i<N;++i){
			cout<<anss[i]+1<<' ';
		}
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}