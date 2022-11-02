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


#define maxn 2050
#define modu 1000000007
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

// COMMON FUNCTION
// random LL
LL randll(LL a,LL b)    {
    uniform_int_distribution<int> u(a,b);
    static mt19937 e(time(0));
    return u(e);
}

LL pw(LL a,LL k=modu-2) {
    LL ans=1;
    for (a%=modu;k;k>>=1)   {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int n;
char s[maxn],t[maxn];

LL f[maxn][maxn][2][2],g[maxn][maxn][2][2];

void add(LL &a,LL b)    {
    a=(a+b)%modu;
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _;
    read(_);
    while (_--) {
        cin>>n;
        cin>>s+1>>t+1;
        
        for (int i=0;i<=n;++i)
            for (int j=0;j<=n;++j)
                for (int c=0;c<=1;++c)
                    for (int s=0;s<=1;++s)
                        f[i][j][c][s]=g[i][j][c][s]=0;
        
        f[0][0][0][1]=1;
        for (int i=0;i<=n;++i)
            for (int j=i;j<=n;++j)  {
                // for (int c=0;c<=1;++c)
                //     for (int s=0;s<=1;++s)
                //         if (f[i][j][c][s])
                //             print("fg[",i,"][",j,"][",c,"][",s,"]=",f[i][j][c][s],",",g[i][j][c][s]);
                
                // if (i==n) continue;
                if (i==j)   {
                    LL F=(f[i][j][0][1]+f[i][j][1][1])%modu;
                    LL G=(g[i][j][0][1]+g[i][j][1][1])%modu;
                    // dbg(i,sum);
                    for (int a=0;a<=1;++a)
                        if (s[i+1]-'0'!=(a^1))  {
                            // dbg("type1",i,i+1,a,1,F,G);
                            add(f[i][i+1][a][1],F);
                            add(g[i][i+1][a][1],G);
                        }
                } else {
                    //s=1
                    for (int c=0;c<=1;++c)  {
                        // c,c^1,c,c^1,c,...
                        // if (!f[i][j][c][1]) continue;
                        // print("fg[",i,"][",j,"][",c,"][",1,"]=",f[i][j][c][1],",",g[i][j][c][1]);
                        if (t[i+1]-'0'!=(c^1))   {//t[i]=c
                            // print("type2",i+1,j,c,"???");
                            add(f[i+1][j][c^1][1],f[i][j][c][1]);
                            add(g[i+1][j][c^1][1],g[i][j][c][1]);
                        }
                        if (t[i+1]-'0'!=c)    {//t[i]=c^1
                            // print("type3",i+1,j,c);
                            add(f[i][j][c][0],f[i][j][c][1]);
                            add(g[i][j][c][0],g[i][j][c][1]);
                        }
                    }

                    //s=0
                    for (int c=0;c<=1;++c)  {
                        // if (!f[i][j][c][0]) continue;
                        // print("fg[",i,"][",j,"][",c,"][",0,"]=",f[i][j][c][0],",",g[i][j][c][0]);
                        // dbg(j+1,s[j+1]!=(c^((j-i-1)&1)),s[j+1]!=(c^((j-i)&1)));
                        // s[i+1]=c,c^1,c,c^1,c,...,s[j-1]=c^ [(j-1-i-1)&1]
                        // t[i+1]=c^1
                        if (j<n&&s[j+1]-'0'!=(c^((j-i)&1)))   {//s[j]=s[j-1]
                            // print("type4",i+1,j,c^1);
                            add(f[i+1][j+1][c^1][1],f[i][j][c][0]);
                            add(g[i+1][j+1][c^1][1],g[i][j][c][0]+f[i][j][c][0]*(j-i));
                        }
                        if (j<n&&s[j+1]-'0'!=(c^((j-i+1)&1)))    {//s[j]!=s[j-1]
                            // print("type5",i,j+1,c);
                            add(f[i][j+1][c][0],f[i][j][c][0]);
                            add(g[i][j+1][c][0],g[i][j][c][0]);
                        }
                    }
                }
            }
        
        LL ans=(g[n][n][0][1]+g[n][n][1][1])%modu;
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/