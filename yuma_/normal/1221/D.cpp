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
ll get_sum(ll x){
	vector<int>v(19);

	ll amin=1;
	ll min_cnt=1;
	ll amax=min(9ll,x);
	ll max_cnt=min(9ll,x);

	ll sum=0;
	ll xx=9;
	for(int keta=1;keta<19;++keta){
		
		
		ll asum=(min_cnt+max_cnt)*(amax-amin+1)/2;
		sum+=asum;

		amin*=10;
		amax=amax*10+9;
		if(amax>x)amax=x;
		if(amin>x)break;
		min_cnt=max_cnt+keta+1;
		max_cnt=max_cnt+(keta+1)*(amax-amin+1);
	}
	return sum;
}
int get_place(vector<int>v){
	if(count(v.begin(),v.end(),0)==0||count(v.begin(),v.end(),0)==v.size())return -2;
	else{
		if(v[0]==1){
			for(auto &k:v)k=!k;
		}
		int flag=0;
		for(int i=0;i<v.size();++i){
			if(v[i]==0){
				if(flag==0){

				}else if(flag>=1){
					flag=-1;
				}

			}else{
				if(flag==0)flag=i;
				
			}
		}
		assert(flag);
		return flag;
	}
}
pair<vector<int>,vector<int>> solve(vector<int>ls,vector<vector<int>>field){
	int H=field.size();
	int W=field[0].size();
	vector<int>h_flips(field.size());
	for(int i=0;i<field.size();++i){
		h_flips[i]=field[i][0]!=ls[i];
	}
	for(int y=0;y<field.size();++y){
		for(int x=0;x<field[y].size();++x){
			if(h_flips[y])field[y][x]=!field[y][x];
		}
	}
	for(int xx=0;xx<2;++xx){
		vector<int>w_flips(field[0].size());

		vector<int>flags;
		int amin,amax;
		bool ok=true;
		for(int x=W-1;x>=0;--x){
			vector<int>v;
			for(int y=0;y<H;++y)v.push_back(field[y][x]);
			int flag=get_place(v);
			if(flag==-2){
				if(xx)flag=H;
				else flag=0;
			}
			if(flag==-1)ok=false;
			w_flips[x]=field[0][x];
			if(flag==0){
				w_flips[x]=!w_flips[x];
			}
			if(x==W-1){
				amin=flag;
				amax=flag;
			}else{
				if(amin==amax){
					if(amin==flag){

					}else if(amin+1==flag){
						amax=flag;
					}else{
						ok=false;
					}
				}else {
					if(amax==flag){

					}else{
						ok=false;
					}
				}
			}
			
		}
		if(ok){
			return make_pair(h_flips,w_flips);
		}
	}	
	return make_pair(vector<int>(),vector<int>());
	
}
int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int N;cin>>N;
		vector<ll>hs,costs;
		for(int i=0;i<N;++i){
			ll h,c;cin>>h>>c;
			hs.push_back(h);
			costs.push_back(c);
		}
		vector<vector<ll>>dp(N+1,vector<ll>(4,1e18));
		dp[0][0]=0;
		dp[0][1]=costs[0];
		dp[0][2]=costs[0]*2;
		dp[0][3]=costs[0]*3;
		for(int i=1;i<N;++i){
			for(int from=0;from<4;++from){
				for(int to=0;to<4;++to){
					if(hs[i-1]+from==hs[i]+to)continue;
					else{
						ll n_cost=dp[i-1][from]+costs[i]*to;

						dp[i][to]=min(dp[i][to],n_cost);
					}
				}
			}
		}
		ll answer=1e18;
		for(int i=0;i<4;++i)answer=min(answer,dp[N-1][i]);
		cout<<answer<<endl;
	}
	return 0;
}