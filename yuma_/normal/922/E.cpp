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

struct aa{
    ll len;
    ll com_cnt;

    vector<int>ids;

    int check()const{
        return ids.size();
    }
    void up(){
        len+=ids.size();
        if(ids.size()==2)com_cnt++;
    }
};

bool operator <(const aa&l,const aa&r){
    if(l.check()!=r.check())return l.check()<r.check();
    if(l.com_cnt!=r.com_cnt)return l.com_cnt<r.com_cnt;
    return l.len<r.len;
}
aa answer{-1,-1,vector<int>{}};
aa dfs(const Graph&g,int now,int from){
    WHATS(now)
    vector<aa>aas;
    for(auto e:g[now]){
        if(e==from)continue;
        auto val=dfs(g,e,now);
        aas.push_back(val);

    }
    if(aas.size()==0){
        aa ret{1,0,vector<int>{now}};
        return ret;
    }
    else if(aas.size()==1){
        aa ret=aas[0];
        ret.up();
        return ret;
    }else{
        WHATS(now)
        sort(aas.begin(),aas.end());
        aa al=aas[aas.size()-2];
        aa ar=aas[aas.size()-1];
        
        if(al.check()==2&&ar.check()==2){
            WHATS(now)
            answer=max(answer,aa{al.len+ar.len,al.com_cnt+ar.com_cnt+1,vector<int>{al.ids[0],al.ids[1],ar.ids[0],ar.ids[1]}});
        }else if(ar.check()==2&&aas.size()>=3){
            aa am=aas[aas.size()-3];

            assert(am.check()==1);
            answer=max(answer,aa{al.len+ar.len+am.len,al.com_cnt+1,vector<int>{ar.ids[0],ar.ids[1],al.ids[0],am.ids[0]}});
        }   
        if(ar.check()==2){
            aa ret=ar;
            ret.up();
            return ret;
        }else{
            assert(al.check()==1);
            aa ret{al.len+ar.len,0,vector<int>{ar.ids[0],al.ids[0]}};
            ret.up();
            return ret;
        }
    }
}
// 0 100/100
// 8 112/116
// 19 35/138
// 19 135/138
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int N;
    ll W,B,X;cin>>N>>W>>B>>X;
    vector<vector<ll>>memo(2,vector<ll>(10001,-1));
    memo[0][0]=W;
    vector<pair<int,pair<int,ll>>>ps;
    {
        vector<int>lims(N);
        vector<ll>costs(N);
        for(int i=0;i<N;++i)cin>>lims[i];
        for(int i=0;i<N;++i)cin>>costs[i];
        for(int i=0;i<N;++i){
            int lim=lims[i];
            int rest=lim;
            int now=1;
            if(rest==0){
                ps.push_back(make_pair(true,make_pair(0,0)));
            }else{
                
                while(rest>=now){
                    rest-=now;
                    ps.push_back(make_pair(false,make_pair(now,costs[i]*now)));
                    //now*=2;
                }
                if(now>=2&&rest>=now/2){
                    ps.push_back(make_pair(false,make_pair(now/2,costs[i]*now/2)));
                    rest-=now/2;
                }
                if(rest){
                    ps.push_back(make_pair(false,make_pair(rest,costs[i]*rest)));
                }
                ps.back().first=true;
            }
        }
    }
    //WHATS(ps);
    int sum=0;
    for(int i=0;i<ps.size();++i){
        sum+=ps[i].first;
        int cur=i%2;
        int tar=1-cur;

        for(int nowuse=0;nowuse<=10000;++nowuse){
            ll nowpower=memo[cur][nowuse];
            if(nowpower==-1)continue;
            else{
                ll acost=ps[i].second.second;
                bool restore=ps[i].first;
                ll aplus=ps[i].second.first;
                if(nowpower>=acost){
                    ll nextpower=nowpower-acost;
                    if(restore)nextpower+=X;
                    int nextuse=nowuse+aplus;
                    assert(nextuse<=10000);
                    nextpower=min(nextpower,W+nextuse*B);

                    memo[tar][nextuse]=max(memo[tar][nextuse],nextpower);
                }
                {
                    ll nextpower=nowpower;
                    if(restore)nextpower+=X;
                    int nextuse=nowuse;
                    assert(nextuse<=10000);
                    nextpower=min(nextpower,W+nextuse*B);

                    memo[tar][nextuse]=max(memo[tar][nextuse],nextpower);
                }
            }
        }
        for(int j=0;j<=10000;++j){
            memo[cur][j]=-1;
        }
    }
    int answer=0;
    for(int i=0;i<=10000;++i){
        if(memo[ps.size()%2][i]!=-1){
            answer=max(answer,i);
        }
    }
    //WHATS(memo)
    cout<<answer<<endl;
    assert(sum==N);
	return 0;

}