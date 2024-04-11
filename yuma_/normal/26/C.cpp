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
int main() {
	ios::sync_with_stdio(false);
	int H,W,A,B,C;cin>>H>>W>>A>>B>>C;
	bool ok=true;
	bool flag=false;
	vector<vector<int>>field;
	if(H%2&&W%2){
		ok=false;
	}else{
		if(H*W>A*2+B*2+C*4)ok=false;
		else{
			if(H%2){
				swap(H,W);
				swap(A,B);
				flag=true;
			}
			if(W%2){
				if(B<H/2)ok=false;
				else{
					field=vector<vector<int>>(H,vector<int>(W));
					for(int y=0;y<H;y+=2){
						field[y][0]=2;
					}
					int rest_a=A;
					int rest_b=B-H/2;
					int rest_c=C;
					for(int x=1;x<W;x+=2){
						for(int y=0;y<H;y+=2){
							if(rest_a>=2){
								field[y][x]=1;
								field[y+1][x]=1;
								rest_a-=2;
							}else if(rest_b>=2){
								field[y][x]=2;
								field[y][x+1]=2;
								rest_b-=2;
							}else if(rest_c){
								field[y][x]=3;
								rest_c-=1;
							}else{
								ok=false;
							}
						}
					}
				}
			}else{
				{
					field=vector<vector<int>>(H,vector<int>(W));
					
					int rest_a=A;
					int rest_b=B;
					int rest_c=C;
					for(int x=0;x<W;x+=2){
						for(int y=0;y<H;y+=2){
							if(rest_a>=2){
								field[y][x]=1;
								field[y+1][x]=1;
								rest_a-=2;
							}else if(rest_b>=2){
								field[y][x]=2;
								field[y][x+1]=2;
								rest_b-=2;
							}else if(rest_c){
								field[y][x]=3;
								rest_c-=1;
							}else{
								ok=false;
							}
						}
					}
				}
			}
		}
		
	}
	if(ok){
		vector<string>answer(field.size(),string(field[0].size(),'z'));
		for(int y=0;y<H;++y){
			for(int x=0;x<W;++x){
				int sx=0,sy=0;
				if(field[y][x]==1){
					sy=1;
					sx=2;
				}else if(field[y][x]==2){
					sy=2;
					sx=1;
				}else if(field[y][x]==3){
					sy=2;
					sx=2;
				}
				char ch='a';
				ch+=y%4;
				ch+=4*(x%4);
				for(int ny=y;ny<y+sy;++ny){
					for(int nx=x;nx<x+sx;++nx){
						answer[ny][nx]=ch;
					}
				}
			}
		}
		if(flag){
			vector<string>nanswer(answer[0].size(),string(answer.size(),'z'));
			for(int i=0;i<H;++i){
				for(int j=0;j<W;++j){
					nanswer[j][i]=answer[i][j];
				}
			}
			answer=nanswer;
		}
		for(int i=0;i<answer.size();++i){
			cout<<answer[i]<<endl;
		}
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}