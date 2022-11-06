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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;
const ll mod=1e9+7;

ll powll(ll a,ll b){
	if(b==0)return 1;
	else{
		ll x=powll(a,b/2);
		x*=x;
		x%=mod;
		if(b%2)x*=a;
		x%=mod;
		return x;
	}
}
#include<random>
int gcd(int a,int b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
bool check(vector<int>ls,vector<int>rs){
	set<pair<int,int>>aset;
	for(int i=0;i<ls.size();++i){
		for(int j=i+1;j<ls.size();++j){
			int dl=ls[i]-ls[j];
			int dr=rs[j]-rs[i];
			pair<int,int>ap=make_pair(dl/gcd(dl,dr),dr/gcd(dl,dr));
			if(aset.find(ap)!=aset.end())return false;
			else aset.emplace(ap);
			//cout<<ap.first<<' '<<ap.second<<endl;
		}
	}
	return true;
}

vector<int>bfs(int from,const vector<vector<int>>&edges){
	queue<int>que;
	que.emplace(from);
	vector<int>memo(edges.size(),100000000);
	memo[from]=-1;
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto e:edges[now]){
			if(memo[e]>memo[now]+1){
				memo[e]=memo[now]+1;
				que.emplace(e);
			}
		}
	}
	return memo;
}
struct aa{
	int a;
	int b;
	int c;
	int cost;
};
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie();
	string A,B;cin>>A>>B;
	vector<vector<vector<int>>>dp(A.size()+1,vector<vector<int>>(B.size()+1,vector<int>(202,10000)));
	vector<vector<vector<aa>>>froms(A.size()+1,vector<vector<aa>>(B.size()+1,vector<aa>(202)));

	dp[0][0][0]=0;
	queue<aa>que;
	string chs=")(";
	que.emplace(aa{0,0,0,0});
	while(!que.empty()){
		auto q=que.front();
		que.pop();
		int a=q.a;
		int b=q.b;
		int c=q.c;
		int cost=q.cost;
		
		//WHATS(a)
		//WHATS(b)
		//WHATS(c)
		for(int use=0;use<2;++use){
			if(c==0&&use==0)continue;
			int na=a;
			int nb=b;
			int nc=c+(use?1:-1);
			if(nc>=201)continue;
			if(a!=A.size()&&A[a]==chs[use]){
				na++;
			}
			if(b!=B.size()&&B[b]==chs[use]){
				nb++;
			}
			if(dp[na][nb][nc]>cost+1){
				dp[na][nb][nc]=cost+1;
				froms[na][nb][nc]=q;
				que.emplace(aa{na,nb,nc,cost+1});
			}
		}
	}
	int  na=A.size(),nb=B.size(),nc=0;
	string answer;
	while(na!=0 || nb!=0 || nc!=0){
		auto from=froms[na][nb][nc];
		answer.push_back(chs[from.c<nc]);
		
		na=from.a;
		nb=from.b;
		nc=from.c;
	}
	reverse(answer.begin(),answer.end());
	cout<<answer<<endl;
	return 0;
}