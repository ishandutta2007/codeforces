#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i,begin,end) for (__typeof(begin) i=(begin),_end=(end),_step=1-2*((begin)>(end));i!=_end;i+=_step)

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}
template<class T>
ostream& operator << (ostream& os, const vector<T>& v)  {
    os<<"[";
    if (!v.size()) 
        os<<"]"; 
    else
        for (int i=0;i<v.size();++i)
            os<<v[i]<<",]"[i==v.size()-1];
    return os;
}

void printr(ostream& os){os<<'\n';}
template<class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args){
    os<<t; if (sizeof...(args)) os<<" ";
    printr(os,args...);
}
#define print(args...) printr(cout,##args)

// INPUT
template<class T>
void read(T& x) {cin>>x;}
template<class T, class... Args>
void read(T& t, Args&... args){
    read(t),read(args...);
}
template<class T>
void readarray(T* A,int n)  {
    rep(i,0,n) read(A[i]);
}


// DEBUG
void dbgr(ostream& os) { os<<endl; }
template<class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
    os<<t; if (sizeof...(args)) os<<", ";
    dbgr(os,args...); 
}
#define dbg(args...) cout<<#args<<" = ", dbgr(cout,##args) //cout can be changed


#define maxn 3000050
#define modu 998244353
typedef long long LL;

// COMMON FUNCTION
// min
template<class T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
// max
template<class T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n,a[maxn];
int pos[maxn];

vector<int> cur[maxn];
vector<pair<int,int> > diff[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n);
    readarray(a,n);
    rep(i,0,n) pos[i]=i;
    sort(pos,pos+n,[&](int i,int j){
        return a[i]<a[j];
    });

    auto output=[&](int x,int y,int i,int j){
        print("YES");
        print(x+1,y+1,i+1,j+1);
    };
    
    rep(i,0,n) cur[a[i]].push_back(i);
    vector<int> cnt2;
    rep(i,0,maxn)
        if (cur[i].size()>1)
            cnt2.push_back(i);
    if (cnt2.size()>=2) {
        output(cur[cnt2[0]][0],cur[cnt2[1]][0],cur[cnt2[0]][1],cur[cnt2[1]][1]);
        return 0;
    }


    for (int i=1;i<n;i+=2)  
        diff[a[pos[i]]-a[pos[i-1]]].emplace_back(pos[i],pos[i-1]);
    for (int i=0;i<maxn;++i)
        if (diff[i].size()>1)   {
            output(diff[i][0].first,diff[i][1].second,diff[i][0].second,diff[i][1].first);
            return 0;
        }
    
    for (int i=0;i<maxn;++i) diff[i].clear();
    
    assert(n<=3000);
    rep(i,0,n)
        rep(j,0,i)
            diff[a[pos[i]]-a[pos[j]]].emplace_back(pos[i],pos[j]);
    
    for (int d=0;d<maxn;++d)    {
        sort(diff[d].begin(),diff[d].end());
        // dbg(d);
        for (int i=0;i<diff[d].size();++i)
            for (int j=i+1;j<diff[d].size()&&j<i+4;++j)
                if (diff[d][i].first!=diff[d][j].first&&
                    diff[d][i].first!=diff[d][j].second&&
                    diff[d][i].second!=diff[d][j].first&&
                    diff[d][i].second!=diff[d][j].second) {
                        output(diff[d][i].first,diff[d][j].second,diff[d][i].second,diff[d][j].first);
                        return 0;
                    }
    }

    print("NO");


    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/