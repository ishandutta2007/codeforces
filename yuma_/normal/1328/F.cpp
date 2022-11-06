#define _CRT_SECURE_NO_WARNINGS
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
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
    
using namespace std;
    
using ll=long long;
using ld =long double;
    
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
using Graph=vector<vector<int>>;
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
const int MAX_A=int(1e6)+1;
int answer=1e8;
void dfs(int now,int from,int dep,const vector<vector<int>>&edges,vector<int>&depths){
    WHATS(now)
    assert(depths[now]==-1);
    depths[now]=dep;
    int ret=1e9;
    

    for(auto e:edges[now]){
        if(e==from)continue;
        if(depths[e]!=-1){
            if(depths[e]<depths[now]){
                answer=min(answer,depths[now]-depths[e]+1);
            }
        }else{
            dfs(e,now,dep+1,edges,depths);
        }
    }


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N,M;cin>>N>>M;
    map<ll,int>mp;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        mp[a]++;
    }
    map<ll,pair<ll,int>>sums;

    ll asum=0;
    int acnt=0;
    for(auto m:mp){
        asum+=m.first*m.second;
        acnt+=m.second;
        sums[m.first].first=asum;
        sums[m.first].second=acnt;

        //WHATS(asum)
    }
    ll total=prev(sums.end())->second.first;

    auto jt=sums.find(mp.begin()->first);

    ll l_sum=0;
    int l_cnt=0;

    ll answer=1e18;
    for(auto it=mp.begin();it!=mp.end();++it){
        //WHATS(l_sum)
        //WHATS(l_cnt)
        ll m_num=it->first;
        int m_cnt=it->second;
        
        ll r_sum=total-l_sum-it->second*it->first;
        int r_cnt=N-l_cnt-it->second;
        ll nanswer=1e18;
        if(m_cnt>=M){
            nanswer=0;
        }else{
            int aneed=M-m_cnt;
            ll l_need=(l_cnt*(m_num-1))-l_sum;
            ll r_need=r_sum-(r_cnt*(m_num+1));

            {
                ll aanswer=0;
                if(l_cnt>=aneed){
                    aanswer=l_need+aneed;
                }else{
                    aanswer=l_need+r_need+aneed;
                }
                nanswer=min(nanswer,aanswer);
            }
            {
                ll aanswer=0;
                if(r_cnt>=aneed){
                    aanswer=r_need+aneed;
                }else{
                    aanswer=l_need+r_need+aneed;
                }
                nanswer=min(nanswer,aanswer);
            }
        }
        //WHATS(nanswer)
        answer=min(answer,nanswer);

        l_sum=jt->second.first;
        l_cnt=jt->second.second;
        jt++;
    }
    cout<<answer<<endl;
    return 0;
}