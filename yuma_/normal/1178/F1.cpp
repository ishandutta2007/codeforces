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

const ll mod=998244353;
    
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


ll memo[501][501];
bool flag[501][501];
int N;
vector<int>colors,places;
vector<vector<int>>max_nums;
ll solve(int l,int r){
    int now=max_nums[l][r];
    if(flag[l][r]){
        return memo[l][r];
    }else{
        flag[l][r]=true;
        if(now==N){
            memo[l][r]=1;
        }else{
            if(places[now]<l||r<=places[now]){
               assert(false);
            }else{
                ll l_sum=0;
                for(int al=l;al<=places[now];++al){
                    l_sum+=solve(l,al)*solve(al,places[now]);
                    l_sum%=mod;
                }
                ll r_sum=0;
                for(int ar=places[now]+1;ar<=r;++ar){
                    r_sum+=solve(places[now]+1,ar)*solve(ar,r);
                    r_sum%=mod;
                }
                memo[l][r]=l_sum*r_sum%mod;
            }
        }
        return memo[l][r];
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    // int N;cin>>N;
    // vector<int>vs(N);
    // for(int i=0;i<N;++i)cin>>vs[i];
    // int need=accumulate(vs.begin(),vs.end(),0);
    // need=(need+2)/2;
    // vector<int>anss;
    // for(int i=0;i<N;++i){
    //     if(i==0||vs[i]*2<=vs[0]){
    //         anss.push_back(i);
    //         need-=vs[i];
    //     }
    // }
    // if(need<=0){
    //     cout<<anss.size()<<endl;
    //     for(int i=0;i<anss.size();++i){
    //         cout<<anss[i]+1<<' ';
    //     }
    //     cout<<endl;
    // }else{
    //     cout<<0<<endl;
    // }
    // string st;cin>>st;
    // int sum=0;
    // for(int i=0;i<st.size()-1;++i){
    //     if(st[i]=='v'&&st[i+1]=='v')sum++;
    // }
    // ll l_sum=0;
    // ll answer=0;
    // for(int i=0;i<st.size()-1;++i){
    //     if(st[i]=='v'&&st[i+1]=='v')l_sum++;
    //     if(st[i]=='o'){
    //         answer+=l_sum*(sum-l_sum);
    //     }
    // }
    // cout<<answer<<endl;
    // int H,W;cin>>H>>W;
    // ll answer=1;
    // const int mod=998244353;
    // for(int i=0;i<H+W;++i){
    //     answer*=2;
    //     answer%=mod;
    // }
    // cout<<answer<<endl;
    // int N;cin>>N;
    // vector<pair<int,int>>answers;
    // for(int i=0;i<N;++i){
    //     answers.push_back(make_pair(i,(i+1)%N));
    // }
    // int x=0;
    // while(!check(int(answers.size()))){
    //     answers.push_back(make_pair(x,x+N/2));
    //     x++;
    // }
    // cout<<answers.size()<<endl;
    // for(auto ans:answers){
    //     cout<<ans.first+1<<' '<<ans.second+1<<endl;
    // }
    // string st;cin>>st;
    // int l=0;
    // int r=st.size();
    // string answer;
    // char amid;
    // while(l<r){
    //     if(l+3>=r){
    //         amid=st[l];
    //         break;
    //     }else{
    //         bool flag=false;
    //         for(int al=l;al<l+2;++al){
    //             for(int ar=r-2;ar<r;++ar){
    //                 if(!flag&&st[al]==st[ar]){
    //                     flag=true;
    //                     answer.push_back(st[al]);
    //                 }
    //             }
    //         }
    //         assert(flag);
    //         l+=2;
    //         r-=2;
    //     }
    // }
    // string r_answer(answer);
    // reverse(r_answer.begin(),r_answer.end());
    // if(amid)cout<<answer<<amid<<r_answer<<endl;
    // else cout<<answer<<r_answer<<endl;

    int M;cin>>N>>M;
    colors=vector<int>(N);
    places=vector<int>(N);
    max_nums=vector<vector<int>>(N+1,vector<int>(N+1,N));
    for(int i=0;i<N;++i){
        cin>>colors[i];
        colors[i]--;
        places[colors[i]]=i;
    }
    for(int l=0;l<=N;++l){
        for(int r=0;r<=N;++r){
            
            for(int x=l;x<r;++x){
                max_nums[l][r]=min(max_nums[l][r],colors[x]);
            }
        }
    }
    ll answer=solve(0,N);
    cout<<answer<<endl;
    return 0;
}