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

using Graph=vector<vector<int>>;
	
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
int say(vector<int>v){
    assert(!v.empty());
    cout<<"? "<<v.size();
    for(auto x:v){
        cout<<' '<<x+1;
    }
    cout<<endl;
    ll num;cin>>num;
    return num;
}
void say2(vector<ll>v){
    cout<<"!";
    for(auto x:v){
        cout<<' '<<x;
    }
    cout<<endl;
}
#include<random>
const int mod=1e9+7;

void solveB(){
    int N;cin>>N;
    string st;cin>>st;
    vector<int>nums(2,0);
    int cnt=0;
    vector<int>nex_connects;
    for(int i=0;i<N;++i){
        if(st[i]=='G'){
            cnt++;
        }else{
            nums.push_back(cnt);
            cnt=0;
        }
    }
    int sum=count(st.begin(),st.end(),'G');
    nums.push_back(cnt);
    cnt=0;
    nums.push_back(0);
    nums.push_back(0);
    int answer=0;
    for(int l=2;l<nums.size()-2;++l){
        answer=max(answer,nums[l]+nums[l+1]+1);

    }
    answer=min(answer,sum);
    cout<<answer<<endl;
}
void solveC(){
    int N,M;cin>>N>>M;
    vector<vector<int>>powers(M);
    for(int i=0;i<N;++i){
        int a,b;cin>>a>>b;a--;
        powers[a].push_back(b);
    }
    for(auto &po:powers){
        sort(po.begin(),po.end(),greater<int>());
    }
    sort(powers.begin(),powers.end(),[](const vector<int>&l,const vector<int>&r){
        return l.size()>r.size();
    });

    vector<int>sums(M);
    int total=0;
    int answer=0;
    for(int use=1;use<=N;++use){
        for(int id=0;id<M;++id){
            if(powers[id].size()+1==use){
                total-=sums[id];

                sums[id]=0;
            }else if(powers[id].size()+1<use){
                
                break;
            }else{
                total-=sums[id];
                sums[id]+=powers[id][use-1];
                sums[id]=max(sums[id],0);
                total+=sums[id];
            }
        }
        answer=max(answer,total);
    }
    cout<<answer<<endl;
}
void solveD(){
    int N;cin>>N;
    map<int,vector<pair<int,int>>>mp;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        int xa=min(2,a);
        mp[xa].push_back(make_pair(a,i));
    }
    auto two_vs=mp[2];
    auto one_vs=mp[1];

    Graph g(N);
    vector<pair<int,int>>edges;
    for(int i=0;i<int(two_vs.size())-1;++i){
        edges.emplace_back(two_vs[i].second,two_vs[i+1].second);
    }
    vector<int>rest_ids;
    if(two_vs.size()>=2){
        rest_ids.push_back(two_vs.front().second);
        rest_ids.push_back(two_vs.back().second);

        for(int i=0;i<int(two_vs.size());++i){
            int num=two_vs[i].first-2;
            while(num--)rest_ids.push_back(two_vs[i].second);
            
        }
    }else{
        for(int i=0;i<int(two_vs.size());++i){
            int num=two_vs[i].first;
            while(num--)rest_ids.push_back(two_vs[i].second);

        }
    }
    reverse(rest_ids.begin(),rest_ids.end());
    bool ok=true;
    for(int i=0;i<one_vs.size();++i){
        if(rest_ids.empty()){
            ok=false;
        }else{
            edges.emplace_back(rest_ids.back(),one_vs[i].second);
            rest_ids.pop_back();
        }
    }

    int answer=two_vs.size();
    answer+=min(2,int(one_vs.size()));
    answer--;
    if(ok){
        cout<<"YES "<<answer<<endl;
        cout<<N-1<<endl;
        for(auto e:edges){
            cout<<e.first+1<<' '<<e.second+1<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
    

}
void solveE(){
    int N,A;cin>>N>>A;
    map<int,int>mp;
    int max_plus=0;
    int A_cnt=0;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        if(a==A){
            A_cnt++;
            auto it=mp.begin();
            while(it!=mp.end()){
                it->second--;
                if(it->second==0)it=mp.erase(it);
                else it++;
            }
            
        }else{
            mp[a]++;
            max_plus=max(max_plus,mp[a]);
        }
    }
    cout<<A_cnt+max_plus<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    solveE();
	return 0;
}