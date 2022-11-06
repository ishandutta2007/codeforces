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
using ll=long long;
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
#include<fstream>

const bool SUBMIT=false;
string from10="./ic/a1.in";
string from11="./ic/a2.in";
string from12="./ic/a3.in";

string from2="./in.txt";
Graph in(){
    
    int a,b;
    vector<pair<int,int>>ps;
    int x=0;

    std::ifstream ifs(from12);
    std::cin.rdbuf(ifs.rdbuf());
    while(cin>>a>>b){
        //cout<<x<<endl;
        ps.emplace_back(a,b);
        x=max(a,x);
        x=max(b,x);
        //cout<<a<<endl;
    }
    Graph g(x+1);
    for(auto p:ps){
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }
    return g;
}
void out(vector<vector<int>>&nums){
    for(int i=0;i<nums.size();++i){
        for(int j=0;j<nums[i].size();++j){
            cout<<nums[i][j];
            if(j==nums[i].size()-1)printf("\n");
            else cout<<' ';
        }
    }
    return ;
}

ld get_score(Graph g,vector<vector<int>>vs){
    int N=g.size();
    int E=0;
    for(auto es:g){
        for(auto e:es){
            E+=1;
        }
    }
    E/=2;
    vector<int>types(N);
    for(int i=0;i<vs.size();++i){
        for(auto x:vs[i]){
            types[x]=i;
        }
    }
    vector<ld>e_ins(N),e_outs(N);
    for(int i=0;i<g.size();++i){
        for(auto j:g[i]){
            if(types[i]==types[j]){
                if(i<j)e_ins[types[i]]++;
            }else{
                e_outs[types[i]]++;
            }

        }
    }
    ld modu=0;

    for(int i=0;i<vs.size();++i){
        int type=i;
        ld kk=e_ins[i]/ld(E);
        ld tt=2*e_ins[i]+e_outs[i];
        tt/=2*E;
        tt=tt*tt;

        modu+=kk-tt;
    }
    ld dense=0;
    for(int type=0;type<vs.size();++type){
        int c=vs[type].size();
        if(c==1){
            dense++;
        }else{
            dense+=e_ins[type]*2/c/(c-1);
        }
    }
    dense/=vs.size();
    //WHATS(dense)
    //WHATS(dense)
    dense-=ld(vs.size())/N;
    //WHATS(dense)
    dense/=2;
    WHATS(dense)
    //WHATS(modu)
    ld score=dense+modu;
    WHATS(modu)
    return dense+modu;
}

#include<random>
void say(Graph&g){
    map<int,int>mp;
    for(auto es:g)mp[es.size()]++;
    for(auto m:mp){
        cout<<m.first<<' '<<m.second<<endl;
    }
}
vector<vector<int>>solve(Graph g,ld val_a,ld val_b){
    if(!SUBMIT)WHATS(val_a)
    if(!SUBMIT)WHATS(val_b)

    int N=g.size();
    std::mt19937 mt(10000*val_a+3505*val_b);

    vector<vector<int>>vs;
    vector<int>types(N);
    int id=0;

    vector<pair<int,int>>ps(g.size());
    for(int i=0;i<g.size();++i){
        ps[i]=make_pair(g[i].size(),i);
    }
    
    sort(ps.begin(),ps.end(),greater<pair<int,int>>());
    shuffle(ps.begin(),ps.end(),mt);
    // for(int i=0;i<1000;++i)cout<<ps[i].first<<' '<<ps[i].second<<' ';
    // cout<<endl;
    vector<int>used(N);
    for(int ttt=0;ttt<g.size();++ttt){
        int i=ps[ttt].second;
        pair<ld,int>p(val_a/(ld(vs.size())+1),-1);
        map<int,ld>mp;
        for(auto to:g[i]){
            if(used[to]){
                mp[types[to]]+=ld(1)/pow(vs[types[to]].size(),val_b);
            }
        }
        for(auto m:mp){
            //WHATS(p)
            p=max(p,make_pair(m.second,m.first));
        }
        if(p.second!=-1){
            types[i]=p.second;
            vs[types[i]].push_back(i);
        }else{
            vs.push_back(vector<int>());
            types[i]=id++;
            vs.back().push_back(i);
        }
        used[ttt]=true;
    }
    WHATS(vs.size())
    say(vs);
    //WHATS(types)
    return vs;
}

map<int,vector<int>>dfs(const Graph&g,int start,const vector<int>&types){
    vector<int>costs(g.size(),100000000);
    costs[start]=0;
    queue<int>que;
    map<int,vector<int>>mps;
    que.emplace(start);
    while(!que.empty()){
        int now(que.front());
        // WHATS(now)
        // WHATS(g[now].size())
        // WHATS(mps.size())
        que.pop();
        if(types[now]==-1){
            mps[costs[now]].push_back(now);
        }

        for(auto e:g[now]){
            if(costs[e]>costs[now]+1){
                costs[e]=costs[now]+1;
                que.emplace(e);
            }
        }
    }
    return mps;
}
vector<vector<int>> solve2(const Graph&g){
    int KK=10;
    std::mt19937 mt(5545);
    const int N=g.size();
    vector<int>types(g.size(),-1);
    int rest=N;
    for(int i=0;i<KK;++i){
        //WHATS(i)
        //WHATS(rest)
        if(!rest)break;
        int id=mt()%N;
        while(types[id]!=-1||g[id].size()==0){
            id++;
            if(id==N)id=0;
        }
        auto mps=dfs(g,id,types);
        //WHATS(mps.size())
        int cnt=rest/(KK-i);
        int sum=0;
        for(auto m:mps){
            //WHATS(m)
            sum+=m.second.size();
            for(auto xx:m.second)types[xx]=i;
            if(sum>=cnt){
                rest-=sum;
                break;
            }
        }
    }
    vector<vector<int>>vs(KK);
    for(int i=0;i<N;++i){
        vs[types[i]].push_back(i);
    }
    return vs;
}
vector<int>memo(2e7,-1);
int asum(int a){
    if(memo[a]!=-1)return memo[a];
    string st=to_string(a);
    int sum=0;
    for(auto c:st)sum+=c-'0';
    return memo[a]=sum;
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie();

    vector<vector<int>>anss(151,vector<int>(10,1000000000));
    for(int x=0;x<=1000000;++x){
        int sum=0;
        for(int t=0;t<10;++t){
            sum+=asum(x+t);
            if(sum<=150)anss[sum][t]=min(anss[sum][t],x);
        }
    }
    int T;cin>>T;
    while(T--){
        int N,K;cin>>K>>N;
        ll answer=-1;
        if(N>=2||K<=40){
            answer=anss[K][N];
            if(answer>1e8)answer=-1;
            cout<<answer<<endl;
        }else{
            if(N==0){
                int nine_cnt=K/9;
                int rest=K%9;
                if(rest)cout<<rest;
                for(int i=0;i<nine_cnt;++i)cout<<9;
                cout<<endl;
            }else{
                if(K%2==1){
                    int nine_cnt=(K-17)/2/9;
                    int rest=((K-17)/2)%9;
                    if(rest)cout<<rest;
                    for(int i=0;i<nine_cnt;++i)cout<<9;
                    cout<<8;
                    cout<<endl;
                }else{
                    int nine_cnt=(K-26)/2/9;
                    int rest=((K-26)/2)%9;
                    if(rest)cout<<rest;
                    for(int i=0;i<nine_cnt;++i)cout<<9;
                    cout<<89;
                    cout<<endl;
                }
            }
        }
    }
   // WHATS(anss);
	return 0;
}