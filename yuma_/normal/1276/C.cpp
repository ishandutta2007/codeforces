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
	int N;cin>>N;
	map<int,int>mp;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		mp[a]++;
	}
	vector<pair<int,int>>vs;
	for(auto m:mp){
		vs.emplace_back(make_pair(m.second,m.first));
	}
	sort(vs.begin(),vs.end());
	reverse(vs.begin(),vs.end());
	int sum=0;

	pair<int,int>answer(0,0);
	vector<int>nums;
	for(int i=1;i<=N;++i){
		for(int j=0;j<vs.size();++j){
			if(vs[j].first>=i){
				sum++;
			}else{
				break;
			}
		}
		for(int h=i;ll(h)*h<=ll(sum);h+=10000){
			int aw=sum/h;
			//WHATS(h)
			//WHATS(aw)
			if(answer.first*answer.second<=h*aw){
				answer=make_pair(h,aw);
			}
		}
	}
	
	int H=answer.first;
	int W=answer.second;
	for(int j=0;j<vs.size();++j){
		for(int k=0;k<min(vs[j].first,H);++k)nums.push_back(vs[j].second);
	}
	cout<<H*W<<endl;
	cout<<H<<' '<<W<<endl;
	assert(H<=W);
	vector<vector<int>>field(H,vector<int>(W));
	
	for(int l=0;l<W;++l){
		for(int y=0;y<H;++y){
			int x=(y+l)%W;
			field[y][x]=nums[l*H+y];
		}
	}
	for(int y=0;y<H;++y){
		for(int x=0;x<W;++x){
			cout<<field[y][x]<<' ';
		}
		cout<<endl;
	}
	return 0;
}