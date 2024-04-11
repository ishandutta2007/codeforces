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

void printr(ostream& os){os<<endl;}
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


#define maxn 550
#define modu 1000000007
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

int n,m;
string dt[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    read(T);
    while (T--) {
        read(n,m);
        rep(i,0,n)
            read(dt[i]);
        for (int i=0;i<n;i+=3)
            for (int j=0;j<m;++j)
                dt[i][j]='X';
        
        for (int i=0;i<3;++i)
            dt[n+i]=string(m,' ');
        for (int i=1;i<n;i+=3)  {
            int k=0;
            for (int j=0;j<m;++j)
                if (dt[i][j]=='X')
                    k=j;
            for (int j=0;j<m;++j)
                if (dt[i+1][j]=='X')
                    k=j;
            dt[i][k]=dt[i+1][k]='X';
        }
        if (n%3==0)
            for (int j=0;j<m;++j)
                if (dt[n-1][j]=='X')
                    dt[n-2][j]='X';
        rep(i,0,n)
            print(dt[i]);
        // print("");
    }
    return 0;
}