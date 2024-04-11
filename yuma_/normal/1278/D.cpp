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

pair<int,int>solve(int y,int x){
	int k=100;
	while(true){
		if(abs(y)>abs(x)){
			while(y>=5){
				y-=5;
				x+=2;
			}
			while(y<0){
				y+=5;
				x-=2;
			}
		}else{
			while(x>=5){
				x-=5;
				y-=2;
			}
			while(x<0){
				x+=5;
				y+=2;
			}
		}
		
		k--;
	}
	return make_pair(x,y);
}
vector<int>pluss{
	2,3,2,3,3,2,3,3,2,3,2,3,3,2,3,3,2,3,2,
};
int solve2(vector<string>field,int H,int W){
	assert(H==19);
	vector<vector<int>>dp(4201,vector<int>(19,1e9));
	dp[0][0]=0;
	for(int i=0;i<19;++i){
		dp[0][i]=0;
	}

	for(int x=0;x<3900;++x){
		//cout<<x<<endl;
		for(int flag=0;flag<19;++flag){
			//WHATS(dp[x][flag])
			vector<pair<int,int>>xs(H);
			xs[0]=make_pair(x,x+pluss[flag]);
			for(int y=1;y<19;++y){
				xs[y].first=xs[y-1].second-1;
				if(y+flag==19){
					xs[y].first++;
				}
				xs[y].second=xs[y].first+pluss[(flag+y)%19];
			}
			//WHATS(xs);

			bool no_flag=true;
			for(int y=0;y<19;++y){
				if(field[y][xs[y].second]=='.'){
					no_flag=false;
				}
			}
			if(no_flag){
				dp[x+1][flag]=min(dp[x][flag],dp[x+1][flag]);
			}
			else {
				//cout<<'t'<<endl;
				for(int l_plus=1;l_plus<=5;++l_plus){
					for(int n_flag=0;n_flag<19;++n_flag){
						vector<pair<int,int>>nxs(H);

						nxs[0].first=x+l_plus;
						nxs[0].second=nxs[0].first+pluss[n_flag];

						for(int y=1;y<19;++y){
							nxs[y].first=nxs[y-1].second-1;
							if(y+n_flag==19){
								nxs[y].first++;
							}
							nxs[y].second=nxs[y].first+pluss[(n_flag+y)%19];
						}
						bool ok_flag=true;
						bool aok_flag=true;
						for(int y=0;y<19;++y){
							for(int ax=xs[y].second;ax<nxs[y].first;++ax){
								//cout<<ax<<endl;
								if(field[y][ax]=='.'){
									ok_flag=false;
								}
							}
							for(int ax=nxs[y].first;ax<nxs[y].second;++ax){
								if(field[y][ax]=='.'){
									aok_flag=false;
								}
							}
						}
						//cout<<ok_flag<<endl;
						if(ok_flag){
							//WHATS(x)
							//WHATS(flag)
							//WHATS(l_plus)

							dp[x+l_plus][n_flag]=min(dp[x+l_plus][n_flag],dp[x][flag]+1);
							if(aok_flag){
								dp[x+l_plus][n_flag]=min(dp[x+l_plus][n_flag],dp[x][flag]);
							}
						}
					}
				}
			}
		}
	}
	int answer=1e9;
	for(int i=0;i<19;++i){
		answer=min(answer,dp[3800][i]);
	}
	return answer;
}

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;cin>>N;
	vector<pair<int,int>>ps(N);
	for(int i=0;i<N;++i){
		int l,r;cin>>l>>r;
		ps[i]=make_pair(l,r);
	}
	sort(ps.begin(),ps.end());
	//WHATS(ps)
	set<pair<int,int>>aset;
	int sum=0;
	UnionFind uf(N);
	for(int i=0;i<N;++i){
		if(sum>=N)break;
		int l=ps[i].first;
		int r=ps[i].second;
		
		for(auto it=aset.lower_bound(make_pair(r,i));it!=aset.begin();--it){
			//WHATS(*prev(it))
			if(prev(it)->first<l)break;
			sum++;
			uf.unionSet(i,prev(it)->second);
		}
		aset.emplace(make_pair(r,i));
		//WHATS(sum)

	}
	//cout<<sum<<endl;
	bool ok=true;
	if(sum!=N-1){
		ok=false;
	}else{
		if(uf.size(0)!=N)ok=false;
	}
	if(ok){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}


	return 0;
}