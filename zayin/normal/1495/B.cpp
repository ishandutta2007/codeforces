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


#define maxn 500050
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

int n,a[maxn];
int L[maxn],R[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n);
    rep(i,1,n+1) read(a[i]);
    a[0]=a[n+1]=-maxn;

    rep(i,1,n+1)
        if (a[i-1]<a[i])
            L[i]=L[i-1]+1;
        else
            L[i]=1;
    rep(i,n,0)
        if (a[i+1]<a[i])
            R[i]=R[i+1]+1;
        else
            R[i]=1;
    
    int mx=0,cnt=0;
    rep(i,1,n+1)
        mx=max(mx,max(L[i],R[i]));
    rep(i,1,n+1)
        if (max(L[i],R[i])==mx)
            ++cnt;
    
    if (cnt>1)
        print("0");
    else {
        int ans=0;
        rep(i,1,n+1)    {
            if (max(L[i],R[i])==mx)   {
                // dbg(i,L[i],R[i]);
                int other=(L[i]^R[i]^mx)-1;
                other|=1;
                // dbg(other+2,mx,mx>=other+2);
                if (mx>=other+1) continue;
                // dbg("add");
                ++ans;
            }
        }
        print(ans);
        // print(mx&1);
    }
    return 0;
}