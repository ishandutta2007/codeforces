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
    
#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
    
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


const ll MAX_S=2e5;

vector<ll>check(vector<ll>&x){
    vector<ll>anss(x.size());
    for(int i=0;i<int(x.size())-1;++i){
        anss[i+1]=x[i+1]-x[i];
    }
    anss[0]=x[0];
    return anss;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    vector<ll>as,bs;
    for(int i=0;i<N;++i){
        ll a;cin>>a;
        as.push_back(a);
    }
    for(int i=0;i<N;++i){
        ll a;cin>>a;
        bs.push_back(a);
    }
    if(N==1){
        if(as==bs){
            cout<<"SMALL"<<endl;
            cout<<0<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }else if(N==2){
        string answer;
        ll sum=0;
        bool ok=true;
        bool flag=false;
        if(as[0]>as.back()){
            reverse(as.begin(),as.end());
            flag=true;
        }
        while(as!=bs){
            WHATS(as)
            WHATS(bs)
    
            if(bs[0]>bs[1]){
                answer.push_back('R');
                swap(bs[0],bs[1]);
            }else{
                if(as[0]+as[1]>bs[0]+bs[1]){
                    ok=false;
                    break;
                }
                
                ll n_cnt=0;
                if(as[0]==bs[0]){
                    n_cnt=(bs[1]-as[1])/bs[0];
                }else if(as[0]>bs[0]){
                    ok=false;
                    break;
                }else{
                    n_cnt=bs[1]/bs[0];
                }
                if(!n_cnt)break;
                sum+=n_cnt;
                if(sum>MAX_S){
                    
                }else{
                    answer+=string(n_cnt,'P');
                }
                bs[1]-=bs[0]*n_cnt;
            }
        }
        if(flag){
            answer.push_back('R');
  
        }
        if(as!=bs){
            reverse(bs.begin(),bs.end());
            if(as==bs){
                answer.push_back('R');
            }else{
                ok=false;
            }
        }
        reverse(answer.begin(),answer.end());

        if(ok){
            if(sum>MAX_S){
                cout<<"BIG"<<endl;
                cout<<sum<<endl;
            }else{
                cout<<"SMALL"<<endl;
                cout<<answer.size()<<endl;
                cout<<answer<<endl;
            }
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }else{
        string answer;
        bool ok=true;
        bool flag=false;
        if(as[0]>as.back()){
            reverse(as.begin(),as.end());
            flag=true;
        }
        while(as!=bs){
            WHATS(as)
            WHATS(bs)
            if(bs[0]>bs.back()){
                reverse(bs.begin(),bs.end());
                answer.push_back('R');
                continue;
            }
            if(accumulate(as.begin(),as.end(),0ll)>=accumulate(bs.begin(),bs.end(),0ll)){
                break;
            }
            auto nex_bs=check(bs);
            if(find_if(nex_bs.begin(),nex_bs.end(),[](const ll b){return b<=0;})!=nex_bs.end()){
                ok=false;
                break;
            }else{
                answer.push_back('P');
                bs=nex_bs;
            }
        }
        if(flag)answer.push_back('R');
        if(as==bs){

        }else{
            reverse(bs.begin(),bs.end());
            if(as==bs){
                answer.push_back('R');
            }else{
                ok=false;
            }
        }
        if(ok){
            
            reverse(answer.begin(),answer.end());
            if(count(answer.begin(),answer.end(),'P')>MAX_S){
                cout<<"BIG"<<endl;
                cout<<count(answer.begin(),answer.end(),'P')<<endl;
            }else{
                
                cout<<"SMALL"<<endl;
                cout<<answer.size()<<endl;
                cout<<answer<<endl;
            }
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}