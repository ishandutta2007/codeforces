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


using ll=long long ;

class HashVI {  // nbVIuWFNg
public:
	size_t operator()(const vector<int> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			t = t * C + x[i];
		}
		return t;
	}
	size_t operator()(const vector<vector<int>> &x) const {
		const int C = 997;      // f
		size_t t = 0;
		for (int i = 0; i != x.size(); ++i) {
			for (int j = 0; j < x[i].size(); ++j) {
				t = t * C + x[i][j];
			}
		}
		return t;
	}
};
#include<unordered_map>
int main() {
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	
	while(Q--){
		int N;cin>>N;
		vector<int>v(N);
		for(int i=0;i<N;++i)cin>>v[i];
		int M;cin>>M;

		vector<int>max_ps(N+1);
		for(int i=0;i<M;++i){
			int a,b;cin>>a>>b;
			max_ps[b]=max(max_ps[b],a);
		}
		for(int i=N-1;i>=0;--i){
			max_ps[i]=max(max_ps[i],max_ps[i+1]);
		}
		reverse(max_ps.begin(),max_ps.end());
		max_ps.pop_back();
	//	WHATS(max_ps)

		int answer=1;
		int from=0;
		int amin_cnt=1e9;
		for(int i=0;i<N;++i){
			auto it=lower_bound(max_ps.begin(),max_ps.end(),v[i]);
			int cnt=max_ps.end()-it;
			amin_cnt=min(amin_cnt,cnt);
			if(cnt==0){
				answer=-2;
				break;
			}
			if(i-from+1<=amin_cnt){

			}else{
				answer++;
				from=i;
				amin_cnt=cnt;
			}
		}
		
		if(answer<0)answer=-1;
		cout<<answer<<endl;

	}
	return 0;
}