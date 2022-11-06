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
using ll=long long ;
const ll mod=1e9+7;
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

	
using ll = long long int;
int H,W;
bool ch(int x,int y){
    return x>=0&&x<W&&y>=0&&y<H;
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie();

    cin>>H>>W;
    vector<string>fi(H);
vector<vector<vector<ll>>>memo(H,vector<vector<ll>>(H,vector<ll>(2)));

    int need_time=(H+W-2)/2;
    for(int i=0;i<H;++i){
        char chs[504];
        scanf("%s",chs);
        string st=chs;
        fi[i]=st;
    }
    memo[0][H-1][0]=(fi[0][0]==fi[H-1][W-1])?1:0;

    for(int i=0;i<need_time;++i){
        int cur=i&1;
        int tar=cur^1;

        int au=max(0,i-(W-1));
        int ad=min(H-1,i);

        int bd=H-1-au;
        int bu=H-1-ad;

        for(int ay=au;ay<=ad;++ay){
            for(int by=bu;by<=bd;++by){
                //WHATS(i)
                //WHATS(ay)
                //WHATS(by)
                int ax=i-ay;
                int bx=(H+W-2)-i-by;

                int dx[]={1,0};
                int dy[]={0,1};
                for(int away=0;away<2;++away){
                    for(int bway=0;bway<2;++bway){
                        int any=ay+dy[away];
                        int anx=ax+dx[away];
                        int bny=by-dy[bway];
                        int bnx=bx-dx[bway];
                        if(ch(anx,any)&&ch(bnx,bny)){
                            if(fi[any][anx]==fi[bny][bnx]){
                                memo[any][bny][tar]+=memo[ay][by][cur];
                            }
                        }
                        
                    }
                }
                //WHATS(i)
            }
        }
        for(int i=0;i<H;++i){
            for(int j=0;j<H;++j){
                memo[i][j][cur]=0;
                memo[i][j][tar]%=mod;
            }
        }
    }
    ll answer=0;
    if((H+W)%2){
    //WHATS(memo)

        for(int y=0;y<H-1;++y){
            int ax=need_time-y;
            if(fi[y][ax]==fi[y+1][ax]){
                answer+=memo[y][y+1][need_time%2];
            }
        }
        for(int y=0;y<H;++y){
            int ax=need_time-y;
            if(ch(ax+1,y)){
                if(fi[y][ax]==fi[y][ax+1]){
                    answer+=memo[y][y][need_time%2];
                }
            }
            
        }
    }else{
        for(int y=0;y<H;++y){
            answer+=memo[y][y][need_time%2];
        }
    }
    cout<<answer%mod<<endl;
	return 0;
}