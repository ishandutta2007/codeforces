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


const int MAX_N=1e5;

vector<int> min_divs(MAX_N+1,-1);
vector<vector<int>>divs(MAX_N+1);
vector<int>haves(MAX_N+1,false);
vector<int>cnts(MAX_N+1,false);
vector<int>u(MAX_N+1,false);
void init(){
    
    for(int i=2;i<MAX_N;++i){
        if(min_divs[i]==-1){
            for(ll j=(ll(i)*i);j<=MAX_N;j+=i){
                if(min_divs[j]==-1){
                    min_divs[j]=i;
                }
            }
        }
    }
    //cout<<3<<endl;
    for(int i=1;i<=MAX_N;++i){
        for(int j=i;j<=MAX_N;j+=i){
            divs[j].push_back(i);
        }
        if(i==1)u[i]=1;
        else if((i/divs[i][1])%divs[i][1]==0){
            u[i]=0;
        }else{
            u[i]=-u[i/divs[i][1]];
        }
    }
}
int coprime(int x){
    int ret=0;
    for(int k:divs[x]){
        ret+=cnts[k]*u[k];
    }
    return ret;
}
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
void update(int x,int a){
    for(int i:divs[x])cnts[i]+=a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    ll answer=0;
    int N;cin>>N;
    for(int i=0;i<N;++i){
        ll a;cin>>a;
        haves[a]=true;
        answer=max(answer,a);
    }
    //WHATS(divs)
    for(int gg=MAX_N;gg>=1;--gg){
        //WHATS(gg)
        stack<int>sta;
        for(int xx=MAX_N/gg*gg;xx>0;xx-=gg){
            if(!haves[xx])continue;
            int c=coprime(xx/gg);
            //WHATS(c)
            //WHATS(xx)
            while(c){
                //WHATS(c)
                //WHATS(xx)
                //WHATS(gg)
                //WHATS(sta.top())
                if(gcd(sta.top(),xx/gg)==1){
                    answer=max(answer,1ll*xx*sta.top());
                    c--;
                }
                update(sta.top(),-1);
                sta.pop();
            }
            update(xx/gg,1);
            sta.push(xx/gg);
        }
        while(!sta.empty()){
            //WHATS(sta.top())
            update(sta.top(),-1);
            sta.pop();
        }
    }
    cout<<answer<<endl;
    return 0;
}