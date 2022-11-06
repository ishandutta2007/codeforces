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
ll mod;
const int N=10;

int aget(int y,int x){
	if(y%2==0){
		return 99-10*y-x;
	}else{
		return 90-10*y+x;
	}
}
int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int L,R;cin>>L>>R;
		ll dp[32][2][2][2][2];
		for(int i=0;i<32;++i){
			for(int j=0;j<2;++j){
				for(int k=0;k<2;++k){
					for(int l=0;l<2;++l){
						for(int r=0;r<2;++r){
							dp[i][j][k][l][r]=0;
						}
					}
				}
			}
		}
		dp[31][1][1][1][1]=1;
		for(int i=30;i>=0;--i){
			for(int l_same=0;l_same<2;++l_same){
				for(int r_same=0;r_same<2;++r_same){
					for(int l_same2=0;l_same2<2;++l_same2){
						for(int r_same2=0;r_same2<2;++r_same2){
							for(int x=0;x<2;++x){
								for(int y=0;y<2;++y){
									if(x&&y)continue;
									else{
										bool nl_same=false,nr_same=false;
										bool nl_same2=false,nr_same2=false;
										bool ok=true;
										{
											if(l_same){
												if((L&(1<<i))!=0){
													if(x){
														nl_same=true;

													}else{
														ok=false;
													}
												}else{
													if(x){
														nl_same=false;
													}else{
														nl_same=true;
													}
												}
											}else{
												nl_same=false;
											}
											if(r_same){
												if((R&(1<<i))!=0){
													if(x){
														nr_same=true;
													}else{
														nr_same=false;
													}
												}else{
													if(x){
														ok=false;
													}else{
														nr_same=true;
													}
												}
											}else{
												nr_same=false;
											}
										}
										{
											if(l_same2){
												if((L&(1<<i))!=0){
													if(y){
														nl_same2=true;

													}else{
														ok=false;
													}
												}else{
													if(y){
														nl_same2=false;
													}else{
														nl_same2=true;
													}
												}
											}else{
												nl_same2=false;
											}
											if(r_same2){
												if((R&(1<<i))!=0){
													if(y){
														nr_same2=true;
													}else{
														nr_same2=false;
													}
												}else{
													if(y){
														ok=false;
													}else{
														nr_same2=true;
													}
												}
											}else{
												nr_same2=false;
											}
										}

										
										if(!ok)continue;
										dp[i][nl_same][nr_same][nl_same2][nr_same2]+=dp[i+1][l_same][r_same][l_same2][r_same2];
									}
								}
							}
						}
					}
					
				}
			}
			
		}
		ll answer=0;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				for(int k=0;k<2;++k){
					for(int l=0;l<2;++l){
				answer+=dp[0][i][j][k][l];

					}	
				}
			}
		}
		cout<<answer<<endl;
	}
	
	return 0;	
}