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
	
	
using ll = long long int;
using Graph=vector<vector<int>>;
Graph graph;
vector<int>depths;
vector<int>cycles;
vector<int>froms;
int N;
void dfs(int now,int from,int d){
	depths[now]=d;
	froms[now]=from;
	for(auto e:graph[now]){
		if(e==from)continue;
		else{
			if(depths[e]){
				if(depths[e]<depths[now]){
					int xx=now;
					cycles[xx]=true;
					while(xx!=e){
						xx=froms[xx];
						cycles[xx]=true;
					}
				}else if(depths[e]>=depths[now]){

				}
			}else{
				dfs(e,now,d+1);
			}
			
		}
	}
}
vector<int>szs;
vector<pair<ll,ll>>dps;
void dfs2(int now,int from,int d=0){
	szs[now]=1;
	bool flag=false;
	ll max_plus=0;
	ll normal_sum=0;
	for(auto e:graph[now]){
		if(e==from||cycles[e])continue;
		else{
			dfs2(e,now,d+1);
			szs[now]+=szs[e];
			flag=true;
			normal_sum+=dps[e].first;
			max_plus=max(max_plus,dps[e].second+N-szs[e]);
		}
	}
	if(!flag){
		max_plus=N-1;
	}else{
		max_plus-=szs[now];
	}
	normal_sum+=szs[now];
	{
		dps[now].first=normal_sum;
		dps[now].second=max_plus;
	}
	
}
int main() 
{
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<vector<int>>field(N,vector<int>(N));
	for(int k=0;k<2;++k){
		for(int i=0;i<N;++i){
			string st;cin>>st;
			for(int j=0;j<N;++j){
				field[i][j]^=st[j]=='1';
			}
		}
	}
	vector<int>nums(N);
	string st;cin>>st;
	for(int i=0;i<N;++i)nums[i]=(st[i]=='1');
	int k=-1;
	for(int i=0;i<N;++i){
		if(nums[i]){
			k=i;
			break;
		}
	}
	if(k==-1){
		
		bool aok=true;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(field[i][j])aok=false;
			}
		}
		if(aok){
			cout<<0<<endl;
		}else{
			cout<<-1<<endl;
		}
	}else{
		bool aok=false;
		vector<pair<int,int>>answers;
		for(int y0=0;y0<N;++y0){
			bool ok=true;
			vector<int>xs(N),ys(N);
			for(int x=0;x<N;++x){
				xs[x]=field[k][x]^(y0&nums[x]);

			}
			for(int y=0;y<N;++y){
				ys[y]=field[y][k]^(xs[k]&nums[y]);
			}
			for(int y=0;y<N;++y){
				for(int x=0;x<N;++x){
					if(field[y][x]!=(xs[x]&nums[y])^(ys[y]&nums[x])){
						ok=false;
					}
				}
			}
			if(ok){
				for(int y=0;y<N;++y){
					if(ys[y]){
						answers.push_back(make_pair(0,y));
					}
				}
				for(int x=0;x<N;++x){
					if(xs[x]){
						answers.push_back(make_pair(1,x));
					}
				}
				aok=true;
				break;
			}
		}
		if(aok){
			cout<<answers.size()<<endl;
			for(auto an:answers){
				if(!an.first)cout<<"row ";
				else cout<<"col ";
				cout<<an.second<<endl;
			}
		}else{
			cout<<-1<<endl;
		}
	}
	
	
	
	return 0;
}