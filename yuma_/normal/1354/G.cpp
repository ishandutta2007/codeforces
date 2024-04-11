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
using Graph=vector<vector<int>>;
    
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
vector<int>ap;
void dfs(const Graph&g,vector<int>&colors,int now,int color,vector<int>&uses){
    uses.push_back(now);
    colors[now]=color;
    ap[color]++;
    
    for(auto e:g[now]){
        if(colors[e]==-1){
            dfs(g,colors,e,!color,uses);
        }else{
            if(colors[e]!=colors[now]){

            }else{
                throw(false);
            }
        }
    }
}
int memo[5001][5001];

void dfs2(const Graph&g,vector<int>&answer,int now,int color){

}
struct minion{
    int id;
    ll buff;
    ll pow;
};
string say(vector<int>ls, vector<int>rs){
    cout<<"? "<<ls.size()<<' '<<rs.size()<<endl;
    for(auto l:ls){
        cout<<l+1<<' ';
    }
    cout<<endl;
    for(auto r:rs){
        cout<<r+1<<' ';
    }
    cout<<endl;
    string answer;cin>>answer;
    assert(answer!="WASTED");
    return answer;
}
#include<random>
int main() {
    ap=vector<int>{0,0};
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    //ios::sync_with_stdio(false);
    //cin.tie();
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        std::random_device rnd;
        std::mt19937 mt(rnd());

        bool ans_0=false;
        for(int i=0;i<25;++i){
            int x=mt()%(N-1)+1;
            string st=say(vector<int>{0},vector<int>{x});
            if(st=="SECOND"){
                ans_0=true;
            }
        }

        if(ans_0){
            cout<<"! "<<1<<endl;
        }else{
            int ok_cnt=1;
            bool flag=false;
            int l=1;
            int r=N;
            while(true){
                int al=l;
                int ar=min(r,al+ok_cnt);
                int len=ar-al;
                vector<int>ls(len),rs(len);
                iota(ls.begin(),ls.end(),0);
                iota(rs.begin(),rs.end(),al);
                string st=say(ls,rs);
                if(st=="FIRST"){
                    l=al;
                    r=ar;
                    break;
                }else if(st=="SECOND"){
                
                    assert(false);
                }else if(st=="EQUAL"){
                    l=ar;
                    ok_cnt*=2;
                }
            }

            while(l+1!=r){
                int m((l+r)/2);
                vector<int>ls(m-l);
                vector<int>rs(m-l);
                iota(ls.begin(),ls.end(),0);
                iota(rs.begin(),rs.end(),l);

                string st=say(ls,rs);
                if(st=="FIRST"){
                    r=m;
                }else if(st=="SECOND"){
                    assert(false);
                }else if(st=="EQUAL"){
                    l=m;
                }
            }
            cout<<"! "<<l+1<<endl;
        }
        
    }
    
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14