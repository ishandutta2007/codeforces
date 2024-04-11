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

int solve(ll place){
	if(place<=9)return place;

	place--;
	ll aten=1;
	for(int keta=1;keta<20;++keta){
		if(aten*9*keta<=place){
			place-=aten*keta*9;
			aten*=10;
		}else{
			ll num=place/keta+aten;
			ll xx=place%keta;
			string st=to_string(num);
			return st[xx]-'0';
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	vector<int>vs(2e5+1);
	int N;cin>>N;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		vs[a]++;
	}

	int sum=0;
	int al=-1;
	
	pair<int,pair<int,int>> answer=make_pair(0,make_pair(0,0));
	for(int i=0;i<vs.size();++i){
		if(vs[i]==0){
			answer=max(answer,make_pair(sum,make_pair(al,i)));
			sum=0;
			al=i+1;
		}else if(vs[i]==1){
			sum+=1;
			answer=max(answer,make_pair(sum,make_pair(al,i+1)));
			sum=1;
			al=i;
		}else{
			sum+=vs[i];
			answer=max(answer,make_pair(sum,make_pair(al,i+1)));

		}
	}
	cout<<answer.first<<endl;
	vector<int>v;

	for(int k=answer.second.first;k<answer.second.second;++k){
		v.push_back(k);
	}
	for(int k=answer.second.second-1;k>=answer.second.first;--k){
		for(int t=1;t<vs[k];++t){
			v.push_back(k);
		}
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<' ';
	}
	cout<<endl;
	return 0;
}