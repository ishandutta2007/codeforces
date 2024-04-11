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
template<class T>
ostream& operator << (ostream& os, const set<T>& s)  {
    os<<"{";
    if (!s.size()) 
        os<<"}"; 
    else
        for (auto x:s)
            os<<x<<",}"[x==*s.rbegin()];
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


#define maxn 500050
#define modu 998244353
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

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

struct Matrix   {
    static const int N=300;
    LL a[N][N];
    Matrix(int x=0)   {
        memset(a,0,sizeof(a));
        for (int i=0;i<N;++i)
            a[i][i]=x;
    }
    LL* operator [] (int x)    {
        return a[x];
    }

    friend Matrix operator * (Matrix a,Matrix b)    {
        Matrix c;
        rep(i,0,N)
            rep(k,0,N)  {
                if (!a[i][k]) continue;
                rep(j,0,N)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j])%modu;
            }
        return c;
    }
    friend ostream& operator << (ostream& os,Matrix b)    {
        rep(i,0,30)  {
            rep(j,0,30)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
        return os;
    }
};

int n,m;
string s[maxn],ms[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int n,m;
    read(n,m);
    readarray(s,n);

    int tot=1;
    map<string,int> suf;    
    rep(i,0,n)  
        rep(len,1,s[i].size()+1)  {
            string t=s[i].substr(0,len);
            if (!suf.count(t))  {
                // cout<<tot<<":"<<t<<endl;
                ms[tot]=t;
                suf[t]=tot++;
            }
        }
    
    Matrix trans(0),res(1);
    // dbg(tot);
    rep(i,1,6)
        rep(j,0,tot)
            trans[i*tot+j][(i-1)*tot+j]=1;
    auto join=[&](int i,int j,int len,int d=1)  {
        // cout<<ms[i]<<" -> "<<ms[j]<<" ~ "<<len<<endl;
        trans[j][(len-1)*tot+i]+=d;
    };

    
    rep(i,0,n) join(0,0,s[i].size()),join(0,suf[s[i]],s[i].size());
    rep(i,0,n)
        rep(j,0,n)  {
            if (s[j].size()>=s[i].size()) continue;
            if (s[i].substr(s[i].size()-s[j].size())==s[j])  {
                auto t=s[i].substr(0,s[i].size()-s[j].size());
                if (suf.count(t))
                    join(suf[t],0,s[j].size(),2);
            }
        }
    for (auto p:suf) 
        rep(i,0,n)  {
            auto t=p.first+s[i];
            if (t.size()<=5&&suf.count(t))  {
                join(p.second,suf[t],s[i].size());
            }

            if (s[i].size()<=p.first.size()) continue;
            if (s[i].substr(0,p.first.size())==p.first) {
                auto t=s[i].substr(p.first.size());
                if (suf.count(t))
                    join(p.second,suf[t],t.size());
            }
        }

    // cout<<trans<<endl;

    // rep(i,0,tot)
    //     rep(j,0,6*tot)
    //         if (trans[i][j])
    //             cout<<"("<<j/tot<<","<<ms[j%tot]<<") -> ("<<i/tot<<","<<ms[i%tot]<<")"<<endl;
    
    // rep(t,1,m+1)    {
    //     res=res*trans;
    //     rep(i,0,tot)
    //         if (res[i][0])
    //             cout<<"dp["<<t<<"]["<<ms[i%tot]<<"]="<<res[i][0]<<endl;
    //     cout<<endl;
    // }
    for (;m;m>>=1)  {
        if (m&1)
            res=res*trans;
        trans=trans*trans;
    }
    print(res[0][0]);
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/