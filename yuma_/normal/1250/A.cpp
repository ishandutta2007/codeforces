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
using ll =long long ;	
const ll mod=1e9+7;
int main() {
	ios::sync_with_stdio(false);
	int H,W;cin>>H>>W;
	
	vector<string>field(H);
	for(int y=0;y<H;++y)cin>>field[y];
if(H==1&&W==1){
		cout<<int(field[0][0]=='.')<<endl;
		return 0;
	}
	vector<vector<int>>rs(H,vector<int>(W));
	auto ds=rs;
	auto ls=rs;
	auto us=ds;

	for(int y=0;y<H;++y){
		for(int x=W-2;x>=0;--x){
			if(field[y][x+1]=='.'){
				rs[y][x]=rs[y][x+1]+1;
			}else{
				rs[y][x]=rs[y][x+1];
			}
		}
	}
	for(int y=0;y<H;++y){
		ls[y][0]=0;
		for(int x=0;x<=rs[y][0];++x){
			ls[y][x]=0;
		}
		for(int k=1;k<W;++k){
			for(int x=k-1+rs[y][k-1]+1;x<=k+rs[y][k];++x){
				ls[y][x]=k;
			}
		}
	}
	for(int x=0;x<W;++x){
		for(int y=H-2;y>=0;--y){
			if(field[y+1][x]=='.'){
				ds[y][x]=ds[y+1][x]+1;
			}else{
				ds[y][x]=ds[y+1][x];
			}
		}
	}

	for(int x=0;x<W;++x){
		us[0][x]=0;
		for(int y=0;y<=ds[0][x];++y){
			us[y][x]=0;
		}
		for(int k=1;k<H;++k){
			for(int y=k-1+ds[k-1][x]+1;y<=k+ds[k][x];++y){
				us[y][x]=k;
			}
		}
	}

	// 	WHATS(ls)
	// WHATS(rs)
	// WHATS(us)
	// WHATS(ds)
	vector<vector<vector<ll>>>answers(H+1,vector<vector<ll>>(W+1,vector<ll>(2)));
	auto sums=answers;
	answers[1][1][0]=1;
	answers[1][1][1]=1;
	for(int y=0;y<H;++y){
		for(int x=0;x<W;++x){
			for(int k=0;k<2;++k){
				if(k==0){
					answers[y+1][x+1][k]+=sums[y+1][x][!k]-sums[y+1][ls[y][x]][!k]-sums[y][x][!k]+sums[y][ls[y][x]][!k];

				}else{
					answers[y+1][x+1][k]+=sums[y][x+1][!k]-sums[us[y][x]][x+1][!k]-sums[y][x][!k]+sums[us[y][x]][x][!k];

				}
				answers[y+1][x+1][k]%=mod;
				
				sums[y+1][x+1][k]=sums[y][x+1][k]+sums[y+1][x][k]-sums[y][x][k]+answers[y+1][x+1][k];
				sums[y+1][x+1][k]%=mod;
				
			}
			
		}
	}
	//WHATS(answers)
	//WHATS(sums)
	ll kk=(answers[H][W][0]+answers[H][W][1])%mod;
	if(kk<0)kk+=mod;
	cout<<kk<<endl;
	return 0;
}