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

const int MAX_N=400000;
vector<vector<ll>>hs(MAX_N+1,vector<ll>(20,-1));
vector<vector<ll>>sums(MAX_N+1,vector<ll>(20,-1));

vector<vector<int>>ups(MAX_N+1,vector<int>(20,-1));
int main() {
	
	//ios::sync_with_stdio(false);
	cin.tie();
	int Q;cin>>Q;
	int cnt=0;
	
	vector<ll>ws(MAX_N);
	ws[0]=0;

	ll LAST=0;
	while(Q--){
		int type;
		ll p,q;
		scanf("%d %lld %lld",&type,&p,&q);
		p^=LAST;
		q^=LAST;
		if(type==1){
			cnt++;
			p--;
			int kk=p;
			ws[cnt]=q;
			
			if(ws[kk]<q){
				//WHATS(kk)
				for(int i=19;i>=0;--i){
					if(ups[kk][i]==-1 || ws[ups[kk][i]]>=q){
					}else{
						kk=ups[kk][i];
					}
				}
				//WHATS(ws)
				//WHATS(kk)
				ups[cnt][0]=ups[kk][0];
			}else{
				ups[cnt][0]=kk;
			}
			if(ups[cnt][0]!=-1){
				sums[cnt][0]=ws[ups[cnt][0]];
			}
			for(int i=1;i<20;++i){
				if(ups[cnt][i-1]==-1){
					ups[cnt][i]=-1;
				}else{	
					ups[cnt][i]=ups[ups[cnt][i-1]][i-1];
					if(ups[cnt][i]!=-1){
						sums[cnt][i]=sums[cnt][i-1]+sums[ups[cnt][i-1]][i-1];

					}
				}
			}
			//WHATS(ups)
			//WHATS(sums)

		}else{
			p--;
			ll asum=ws[p];
			int answer=0;
			int now=int(p);
			if(asum>q){
			}else{
				answer=1;
				for(int i=19;i>=0;--i){
					if(ups[now][i]!=-1){
						if(asum+sums[now][i]<=q){
							asum+=sums[now][i];
							now=ups[now][i];
							answer+=(1<<i);
						}
					}
				}
			}
			//cout<<answer<<"\n";
			printf("%d\n",answer);
			LAST=answer;
		}
	}
	return 0;
}