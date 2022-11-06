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
using MyBitset = vector<ll>;
void add(const MyBitset& a,int offset,MyBitset&b){
	const int mo=offset&63;
	WHATS(a.size())
	WHATS(b.size())
	assert(a.size()==b.size());
	assert(offset>=0);
	const int len=offset>>6;
	for(int l=0;l<a.size()-len;++l){
		b[l+len]|=a[l]<<mo;
		if(mo&&l!=a.size()-len-1)b[l+len+1]|=a[l]>>(64-mo);
	}

}

	
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	N*=2;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	sort(v.begin(),v.end());
	ll answer=v[0]+v[1];
	int mm=v[0],mmm=v[1];
	v=vector<int>(v.begin()+2,v.end());
	vector<vector<vector<ll>>>memo(N-1,vector<vector<ll>>(N/2,vector<ll>(30000)));
	memo[0][0][0]=1;
	
	int sum=accumulate(v.begin(),v.end(),0);
	for(int i=0;i<N-2;++i){
		WHATS(i)
		vector<vector<ll>> nmemo=vector<vector<ll>>(N/2,vector<ll>(30000));
		for(int j=0;j<N/2;++j){
			int x=v[i];
			 if(j!=N/2-1){
			add(memo[i][j],x,nmemo[j+1]);
				 
			// 	int mo=x&63;
			// 	int pl=x>>6;
			// 	for(int k=0;k<30000;++k){
			// 		if(k+pl<30000)nmemo[j+1][k+pl]|=memo[i][j][k]<<mo;
			// 		if(k+pl+1<30000&&mo)nmemo[j+1][k+pl+1]|=memo[i][j][k]>>(64-mo);
			// 	}
			 }
			for(int k=0;k<30000;++k){
				nmemo[j][k]|=memo[i][j][k];
			}
			
		}
			memo[i+1]=nmemo;
	}
	int ad=1e9;
	for(int i=0;i<30000;++i){
		for(int j=0;j<64;++j){
			int x=(i<<6)+j;
			if(memo[N-2][N/2-1][i]&(1ull<<j)){
				ad=min(ad,max(x,sum-x));
			}
		}
	}
	answer+=ad;
	//cout<<answer<<endl;
	vector<int>up_ids,do_ids;
	int now_sum=ad;
	int now_rest=N/2-1;
	WHATS(memo[2][2][0]);
	
	for(int i=N-2;i>=0;--i){
		if(!i)break;
		int now_mo=now_sum&63;
		int now_pl=now_sum>>6;
		WHATS(i)
		WHATS(now_mo)
		WHATS(now_pl)
		WHATS(now_rest)
		WHATS(memo[i-1][now_rest][now_pl])
		assert(memo[i][now_rest][now_pl]&(1ull<<now_mo));
		
		if(memo[i-1][now_rest][now_pl]&(1ull<<now_mo)){
			do_ids.push_back(i-1);
		}else{
			up_ids.push_back(i-1);
			now_sum-=v[i-1];
			now_rest--;
		}
	}
	cout<<mm;
	sort(up_ids.begin(),up_ids.end());
	for(int i=0;i<N/2-1;++i){
		cout<<' '<<v[up_ids[i]];
	}
	cout<<endl;
	for(int i=0;i<N/2-1;++i){
		cout<<v[do_ids[i]]<<' ';
	}
	
	cout<<mmm;
	cout<<endl;
	
	return 0;	
}