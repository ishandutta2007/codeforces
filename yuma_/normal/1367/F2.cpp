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
#include<memory>

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}

struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(),vs.end()),vs.end());
		for (int i = 0; i < vs.size(); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
	Compress(const set<int>&vs) {
		int num = 0;
		for (auto v : vs) {
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};
using ll = long long int;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();

    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>as(N);
        for(int i=0;i<N;++i)cin>>as[i];
        Compress comp(as);
        for(int i=0;i<N;++i)as[i]=comp.mp[as[i]];
        vector<set<int>>places(N+1);
        for(int i=0;i<N;++i)places[as[i]].emplace(i);

        vector<vector<int>>anss(N,vector<int>(3));
        for(int i=0;i<N;++i){
            anss[i][0]=1;
        }
        //WHATS(as)
        for(int i=0;i<N;++i){
            auto it=places[as[i]+1].lower_bound(i);
            // for(auto k:places[as[i]+1]){
            //     cout<<k<<endl;
            // }
            auto jt=places[as[i]].upper_bound(i);

            if(it!=places[as[i]+1].end()){
                int nex=*it;

                bool nex_fst=(it==places[as[i]+1].begin());
                bool now_end=(jt==places[as[i]].end());
                if(nex_fst&&now_end){
                }
                if(now_end){
                    if(nex_fst){
                        anss[nex][1]=max(anss[nex][1],anss[i][1]+1);

                    }else{
                        anss[nex][2]=max(anss[nex][2],anss[i][1]+1);

                    }
                }
                if(nex_fst){
                    anss[nex][1]=max(anss[nex][1],anss[i][0]+1);
                }else{
                    anss[nex][2]=max(anss[nex][2],anss[i][0]+1);
                }
            }
            if(jt!=places[as[i]].end()){
                int nex=*jt;
                anss[nex][2]=max(anss[nex][2],anss[i][2]+1);

                anss[nex][1]=max(anss[nex][1],anss[i][1]+1);
                anss[nex][0]=max(anss[nex][0],anss[i][0]+1);

            }
            ////WHATS(anss)
        }
        //WHATS(anss)
        int cnt=0;
        for(int j=0;j<3;++j){
             for(int i=0;i<N;++i){
                cnt=max(cnt,anss[i][j]);
            }
        }
       
        cout<<N-cnt<<endl;
    }
	return 0;
}