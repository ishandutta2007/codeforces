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
using ll = long long int;

//using Graph=vector<vector<pair<int,ll>>>;
	
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
   
    int T;cin>>T;
    while(T--){
        int H,W;cin>>H>>W;
        vector<string>field(H+2,string(W+2,'#'));
        for(int y=0;y<H;++y){
            string st;cin>>st;
            for(int x=0;x<W;++x){
                field[y+1][x+1]=st[x];
            }
        }
        vector<int>dx{-1,0,1,0};
        vector<int>dy{0,1,0,-1};
        bool ok=true;
        bool ok2=true;
        for(int y=1;y<=H;++y){
            for(int x=1;x<=W;++x){
                if(field[y][x]=='B'){
                    for(int way=0;way<4;++way){
                        int nx(x+dx[way]);
                        int ny(y+dy[way]);
                        {
                            if(field[ny][nx]=='G')ok=false;
                            else if(field[ny][nx]!='B') field[ny][nx]='#';

                            if(nx==W&&ny==H)ok2=false;
                        }
                    }
                }
            }
        }
        queue<pair<int,int>>que;
        if(ok2)que.emplace(W,H);
        vector<vector<int>>cango(H+2,vector<int>(W+2));
        while(!que.empty()){
            auto p(que.front());
            que.pop();
            int nowx(p.first);
            int nowy(p.second);
            for(int way=0;way<4;++way){
                int nexx(nowx+dx[way]);
                int nexy(nowy+dy[way]);

                if(field[nexy][nexx]!='#'&&field[nexy][nexx]!='B'){
                    if(!cango[nexy][nexx]){
                        cango[nexy][nexx]=true;
                        que.emplace(nexx,nexy);
                    }
                }
            }
        }
        for(int y=1;y<=H;++y){
            for(int x=1;x<=W;++x){
                if(field[y][x]=='G'){
                    if(!cango[y][x])ok=false;
                }
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    // {
    //     int N;cin>>N;
    //     vector<ll>v(N);
    //     for(int i=0;i<N;++i)cin>>v[i];
    //     int len=min(N,3);
    //     ll answer=0;
    //     for(int l=0;l<=N-len;++l){
    //         ll nans=0;
    //         for(int x=l;x<l+len;++x){
    //             nans|=v[x];
    //         }
    //         answer=max(answer,nans);
    //     }
    //     cout<<answer<<endl;
    // }
	return 0;
}