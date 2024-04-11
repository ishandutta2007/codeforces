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
    
void solveL(){
    int N;cin>>N;
    vector<vector<int>>ks(N);
    for(int i=0;i<N;++i){
        int K;cin>>K;
        for(int j=0;j<K;++j){
            int t;cin>>t;
            ks[i].push_back(-t);
        }
    }
    set<pair<int,int>>one_set;
    set<pair<int,int>>two_set;
    vector<vector<int>>using_ids(N,vector<int>(2,-1));
    for(int i=0;i<N;++i){
        one_set.emplace(ks[i][0],i);
        using_ids[i][0]=(0);
        two_set.emplace(ks[i][0],i);
    
        if(ks[i].size()>=2){
            two_set.emplace(ks[i][1],i);
            using_ids[i][1]=1;
        }
    }
    int M;cin>>M;
    vector<int>anss(M);
    for(int i=0;i<M;++i){
        int a;cin>>a;
    
        bool using_one=false;
        auto it=one_set.begin();
        if(a==1){
            it=one_set.begin();
        }else{
            it=two_set.begin();
        }
        int id=it->second;
        anss[i]=it->first;
        
        if(one_set.find(*it)==one_set.end()){
            using_one=false;
        }else{
            using_one=true;
        }
        if(using_one){
            one_set.erase(*it);
            two_set.erase(*it);
            if(using_ids[id][1]==-1){
                using_ids[id][0]=-1;
            }
            else  if(ks[id].size()<=using_ids[id][1]+1){
                using_ids[id][0]=using_ids[id][1];
                using_ids[id][1]=-1;
            }else{
                using_ids[id][0]=using_ids[id][1];
                using_ids[id][1]++;
            }
            if(using_ids[id][0]!=-1)one_set.emplace(ks[id][using_ids[id][0]],id);
            if(using_ids[id][1]!=-1)two_set.emplace(ks[id][using_ids[id][1]],id);
        }else{
            two_set.erase(*it);
            if(ks[id].size()<=using_ids[id][1]+1){
                using_ids[id][1]=-1;
            }else{
                using_ids[id][1]++;
            }
            if(using_ids[id][1]!=-1)two_set.emplace(ks[id][using_ids[id][1]],id);
        }
        cout<<-anss[i]<<endl;
    }
}
vector<int>dfs(const Graph&g,int start){
    vector<int>costs(g.size(),int(1e8));
    costs[start]=0;
    queue<int>que;
    que.emplace(start);
    while(!que.empty()){
        int now(que.front());
        que.pop();
        for(auto e:g[now]){
            if(costs[e]>costs[now]+1){
                costs[e]=costs[now]+1;
                que.emplace(e);
            }
        }
    }
    return costs;
}
void solveM2(const vector<vector<int>>&ms,int from){
    vector<vector<int>>memo(ms.size(),vector<int>(1<<(int(ms.size())),int(1e9)));
    memo[from][1<<from]=0;
    priority_queue<pair<int,pair<int,int>>>que;
    que.emplace(0,make_pair(from,(1<<from)));
    int answer=-1;
    while(!que.empty()){
        auto p(que.top());
        que.pop();

        int now_place=p.second.first;
        
        int now=p.second.second;
        if(memo[now_place][now]!=-p.first)continue;
        int now_cost=-p.first;
    
        if(now==(1<<(int(ms.size())))-1){
            answer=now_cost;
            break;
        }
    
        for(int i=0;i<ms.size()-1;++i){
            if((now&(1<<i))==0){
                int next=now^(1<<i);
                int nextplace=i;
                int nextcost=now_cost+ms[now_place][nextplace];
                if(memo[nextplace][next]>nextcost){
                    memo[nextplace][next]=nextcost;
                    que.emplace(-nextcost,make_pair(nextplace,next));
                }
            }
        }
    }
    cout<<answer<<endl;
}
void solveM(){
    int N,M;cin>>N>>M;
    Graph g(N);
    for(int i=0;i<M;++i){
        int u,v;cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int S;cin>>S;S--;
    
    int K;cin>>K;
    vector<int>ks(K);
    
    for(int i=0;i<K;++i){
        cin>>ks[i];
        ks[i]--;
        
    }
    K++;
    ks.push_back(S);
    vector<vector<int>>ms(K,vector<int>(K));
    for(int i=0;i<K;++i){
        auto all_costs=dfs(g,ks[i]);
        for(int j=0;j<K;++j){
            ms[i][j]=all_costs[ks[j]];
        }
    }
    //return;
    //WHATS(ms)
    solveM2(ms,K-1);
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    string st;cin>>st;
    int num=count(st.begin(),st.end(),'(');
    num=num*2-st.size();
    if(num==-2){
        reverse(st.begin(),st.end());
        for(auto &c:st){
            if(c=='(')c=')';
            else c='(';
        }
    }
    int answer=0;
    if(abs(num)==2){
        int cnt=0;
        vector<int>sums(st.size()+1);
        for(int i=0;i<st.size();++i){
            if(st[i]=='(')cnt++;
            else cnt--;
            sums[i+1]=cnt;
        }
        for(int i=st.size();i>=1;--i){
            sums[i-1]=min(sums[i],sums[i-1]);
        }
        //WHATS(sums)
        cnt=0;
        for(int i=0;i<st.size();++i){
            if(st[i]=='(')cnt++;
            else cnt--;

            if(st[i]=='('&&sums[i+1]>=2){
                answer++;
            }
        }
        if(sums[0]<0)answer=0;
    }
    cout<<answer<<endl;
    return 0;
}