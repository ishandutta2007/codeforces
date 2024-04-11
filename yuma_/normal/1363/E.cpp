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

void solveB(){
    int N;cin>>N;
    while(N--){
        string st;cin>>st;
        vector<int>l_sums(st.size()+1);
        vector<int>r_sums(st.size()+1);

        for(int i=0;i<st.size();++i){
            l_sums[i+1]=l_sums[i]+int(st[i]=='1');
        }
        for(int i=st.size()-1;i>=0;--i){
            r_sums[i]=r_sums[i+1]+int(st[i]=='1');
        }
        int answer=10000000;
        for(int x=0;x<=st.size();++x){
            for(int t=0;t<2;++t){
                int al=l_sums[x];
                if(t)al=x-al;

                int ar=r_sums[x];
                if(!t)ar=(st.size()-x)-ar;

                answer=min(answer,al+ar);
            }
        }
        cout<<answer<<endl;
    }
}
void solveC(){
    int T;cin>>T;
    while(T--){
        int N,X;cin>>N>>X;
        X--;
        int cnt=0;
        for(int i=0;i<N-1;++i){
            int u,v;cin>>u>>v;u--;v--;
            if(u==X)cnt++;
            if(v==X)cnt++;
        }
        bool fi_win=false;
        if(cnt<=1)fi_win=true;
        else{
            fi_win=N%2==0;
        }
        if(!fi_win)cout<<"Ashish"<<endl;
        else cout<<"Ayush"<<endl;
    }
}

int say(vector<int>v){
    cout<<"? "<<v.size();
    for(auto x:v)cout<<' '<<1+x;
    cout<<endl;
    int a;cin>>a;
    return a;
}

vector<int>tk(vector<vector<int>>&ss,int l,int r){
    vector<int>lv;
    for(int x=l;x<r;++x){
        auto s=ss[x];
            for(auto x:s){
                lv.push_back(x);
            }
        
    }
    return lv;
}
void solveD(){
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<vector<int>>ss(K);
        for(int i=0;i<K;++i){
            int C;cin>>C;
            for(int j=0;j<C;++j){
                int  x;cin>>x;
                x--;
                ss[i].push_back(x);
            }
        }
        int l=0;
        int r=K;
        int amax;
        {
            vector<int>v(N);
            iota(v.begin(),v.end(),0);
            amax=say(v);
        }
        vector<int>anss(K);
        while(l+1!=r){
            int amid=(l+r)/2;

            vector<int>lv=tk(ss,l,amid);
           
            int l_max=say(lv);
            if(l_max==amax){
                for(int x=amid;x<r;++x)anss[x]=amax;
                r=amid;

            }else{
                for(int x=l;x<amid;++x){
                    anss[x]=amax;
                }
                l=amid;
            }
        }
        anss[l]=amax;

        {
            vector<int>v(N);
            iota(v.begin(),v.end(),0);
            for(auto x:ss[l]){
                v.erase(find(v.begin(),v.end(),x));
            }
            anss[l]=say(v);
        }
        // {
        //     vector<int>v=tk(ss,0,K);
        //     vector<int>n_v;
        //     for(int i=0;i<N;++i){
        //         if(find(v.begin(),v.end(),i)==v.end()){
        //             n_v.push_back(i);
        //         }
        //     }
        //     if(!n_v.empty()){
        //         int ans=say(n_v);
        //         for(int i=0;i<K;++i)anss[i]=max(anss[i],ans);
        //     }
        // }
        cout<<"!";
        for(int i=0;i<K;++i)cout<<' '<<anss[i];
        cout<<endl;
        string st;cin>>st;

    }
}

vector<int>as,bs,cs;
pair<ll,int> dfs(const Graph&g,int now,int from){

    ll cost_sum=0;

    int up=0,down=0;
    if(bs[now]==0&&cs[now]==1)up++;
    else if(bs[now]==1&&cs[now]==0)down++;
    for(auto e:g[now]){
        if(e==from)continue;
        else{
            auto p=dfs(g,e,now);
            cost_sum+=p.first;
            if(p.second>0)up+=p.second;
            else down+=-p.second;
        }
    }
    //WHATS(up)
    //WHATS(down)
    //WHATS(now)
    cost_sum+=ll(as[now])*min(up,down);
    return make_pair(cost_sum,up-down);
}
void dfs2(const Graph&g,int now,int from,int c){
    as[now]=min(as[now],c);
    for(auto e:g[now]){
        if(e==from)continue;
        dfs2(g,e,now,as[now]);
        
    }
}
void solveE(){
    int N;cin>>N;
    as=vector<int>(N);
    bs=as,cs=as;
    for(int i=0;i<N;++i){
        cin>>as[i];
        cin>>bs[i];
        cin>>cs[i];
    }
    Graph  g(N);
    for(int i=0;i<N-1;++i){
        int u,v;cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs2(g,0,-1,int(2e9));
    //WHATS(as)

    auto p=dfs(g,0,-1);
    //WHATS(p)
    if(p.second==0)cout<<2*p.first<<endl;
    else cout<<-1<<endl;
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie();
    solveE();
    // int T;cin>>T;
    // while(T--){
    //     int N;cin>>N;
    //     int a=0,b=0;
    //     int K;cin>>K;
    //     for(int i=0;i<N;++i){
    //         int x;cin>>x;
    //         if(x%2==1)a++;
    //         else b++;
    //     }
    //     bool ok=false;
    //     for(int a_num=0;a_num<=a;++a_num){
    //         int b_num=K-a_num;
    //         if(b_num>=0&&b_num<=b){
    //             if(a_num%2==1)ok=true;
    //         }
    //     }
    //     if(ok)cout<<"Yes"<<endl;
    //     else cout<<"No"<<endl;
    // }
	return 0;
}