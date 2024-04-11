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




map<vector<int>,int>get_mp(int N){
    map<vector<int>,int>mp;
    for(int id=0;id<(1<<(N-1));++id){
        int num=0;
        vector<int>v;
        num=1;
        for(int i=0;i<N-1;++i){       
            if(id&(1<<i)){
                num++;
            }else{
                v.push_back(num);
                num=1;
            }
        }
        if(num)v.push_back(num);
        sort(v.begin(),v.end());
        mp[v]++;
    }
    return mp;
}
int places[1<<20];
int as[1<<21];
int dfs(int now,int depth,int H){
    if(now<0 )assert(false);
    int l_id=now*2+1;
    int r_id=now*2+2;

    if(as[l_id]==-1 && as[r_id]==-1){
        if(depth<=H){
            return -1;
        }else{
            int num=as[now];
            as[now]=-1;
            return num;
        }
    }else {
        if(as[l_id]>as[r_id]){
            int num=dfs(l_id,depth+1,H);
            if(num!=-1){
                int ret=as[now];
                as[now]=num;
                places[num]=now;

                return ret;
            }else{
                return -1;
            }
        }else{
            int num=dfs(r_id,depth+1,H);
            if(num!=-1){
                int ret=as[now];
                as[now]=num;
                places[num]=now;

                return ret;
            }else{
                return -1;
            }
        }
    }
}

int main() {
    for(int i=0;i<(1<<21);++i)as[i]=-1;
    //  ios::sync_with_stdio(false);
    //  cin.tie();
    int T;scanf("%d",&T);
    bool flag=false;
    while(T--){
        int G,H;scanf("%d %d",&G,&H);
        //if(G>=11)return 0;
        //if(G==10)flag=true;

        
        vector<int>nums;
        for(int i=0;i<(1<<G)-1;++i){
            int aa;
            scanf("%d",&aa);
            as[i]=aa;
            as[i]--;
            places[as[i]]=i;
            nums.push_back(as[i]);
        }
        if(flag){
            cout<<G<<' '<<H<<endl;
            continue;
        }
        sort(nums.begin(),nums.end());
        vector<int>answers;
        ll sum=0;
        //WHATS(as)
        for(int i=nums.size()-1;i>=0;--i){
            int ad=1;
            int num1=nums[i];
            {
                int nx=0;
                while(nx<places[num1]){
                    nx=nx*2+2;
                    ad++;
                }
            }
            //WHATS(ad)
            answers.push_back(places[num1]);
            sum+=num1+1;
            int num=dfs(places[num1],ad,H);
            if(num!=-1){
                places[num1]=-1;
                sum-=num1+1;

            }else{
                answers.pop_back();
            }
        

            //WHATS(as)
            //WHATS(places)
        }
        //WHATS(as)
        printf("%lld\n",sum);
        for(int i=0;i<answers.size();++i){
            printf("%d ",answers[i]+1);
        }
        printf("\n");
        for(int i=0;i<(1<<G)-1;++i){
            as[i]=-1;
        }
        //if(G>15)return 0;

    }
    return 0;
}