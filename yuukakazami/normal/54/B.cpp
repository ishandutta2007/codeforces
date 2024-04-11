#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <numeric>
#include <climits>
#include <complex>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define FOREACH(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define FOR(i,a,b) for(int i=a;i<b;i++)//for i in [a,b)
#define MP make_pair
#define SIZE(x) int(x.size())
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.resize(unique(ALL(x))-x.begin())
#define CLR(x,t) memset(x,t,sizeof x)
#define ACM accumulate
#define MC(a,b) memcpy(a,b,sizeof a) //memcpy
#define TWO(a) (1<<(a))
#define CONTAIN(s,a) (((s)&TWO(a))!=0)
using namespace std;
typedef long long int64;
typedef pair<int,int> ipair;
typedef vector<int> vi;
typedef stringstream SS;
template<class T> inline void checkmin(T&x,T c){if(c<x)x=c;}
template<class T> inline void checkmax(T&x,T c){if(c>x)x=c;}
//Finished

template<class It>
string toString(It l,It r){
    SS ss;
    ss<<"[";
    for(It i=l;i!=r;i++)
    {
        ss<<*i;
        if(i+1!=r)
            ss<<",";
    }
    ss<<"]";
    return ss.str();
}

void show(vector<string> map){
    REP(i,SIZE(map))
        cout<<map[i]<<endl;
}
vector<string> rotate(vector<string> map){
    int n=SIZE(map),m=SIZE(map[0]);
    vector<string> res(m,string(n,'a'));
    REP(r,n)REP(c,m)
        res[c][n-1-r]=map[r][c];
    return res;
}

vector<string> Min(vector<string> map){
    vector<string> res=map;
    REP(cur,4){
        vector<string> next=rotate(map);
        checkmin(res,next);
        map=next;
    }
    return res;
}
int main(){
    vector<string> m;
    int A,B;
    cin>>A>>B;
    REP(i,A){
        string s;cin>>s;
        m.push_back(s);
    }
    ipair cut(100000,100000);
    int res=0;
    for(int x=1;x<=A;x++)
        for(int y=1;y<=B;y++)
            if(A%x==0&&B%y==0){
                set<vector<string> > Set;
                for(int sx=0;sx<A;sx+=x)
                    for(int sy=0;sy<B;sy+=y){
                        vector<string> mm;
                        REP(i,x){
                            string s;
                            REP(j,y)
                                s+=m[sx+i][sy+j];
                            mm.push_back(s);
                        }
                        Set.insert(Min(mm));
                    }
                if(Set.size()==A*B/(x*y)){
                    res++;
                    checkmin(cut,ipair(x*y,x));
                }
            }
    cout<<res<<endl;
    cout<<cut.second<<" "<<cut.first/cut.second<<endl;
}