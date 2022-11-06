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

vector<int>gp(){
    const int MAX_N=300000;
    vector<int>is_primes(MAX_N+1,true);
    vector<int>v;
    for(int i=2;i*i<=MAX_N;++i){
        if(is_primes[i]){
            v.push_back(i);
            for(ll j=i;j*j<=MAX_N;j+=i){
                is_primes[j]=false;
            }
        }
    }
    return v;
}
int H,W,Q;
bool ch(int y,int x){
    return y>=0&&y<H&&x>=0&&x<W;
}
int main() {
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    ios::sync_with_stdio(false);
    cin.tie();
    cin>>H>>W>>Q;
    vector<vector<int>>field(H,vector<int>(W));
    for(int y=0;y<H;++y){
        string st;cin>>st;
        for(int x=0;x<W;++x){
            field[y][x]=st[x]=='1';
        }
    }
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    queue<pair<int,int>>que;
    vector<vector<ll>>times(H,vector<ll>(W,ll(2e18)));
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            for(int way=0;way<4;++way){
                int nx=x+dx[way];
                int ny=y+dy[way];
                if(ch(ny,nx)&&(field[ny][nx]==field[y][x])){
                    times[y][x]=0;
                    que.emplace(y,x);
                }
            }
        }
    }
    while(!que.empty()){
        auto p(que.front());
        que.pop();
        int x=p.second;
        int y=p.first;
        for(int way=0;way<4;++way){
            int nx=x+dx[way];
            int ny=y+dy[way];
            if(ch(ny,nx)&&times[ny][nx]>times[y][x]+1){
                times[ny][nx]=times[y][x]+1;
                que.emplace(ny,nx);
            }
        }
    }
    while(Q--){
        int y,x; ll p;cin>>y>>x>>p;
        y--;x--;
        ll c_time=max(0ll,p-(times[y][x]));
        c_time%=2;
        cout<<int(field[y][x]^c_time)<<endl;
    }
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14