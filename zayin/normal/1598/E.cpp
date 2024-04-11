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
#define modu 998244353
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

int dir[][2]={{0,-1},{-1,0}};
LL cnt,sum,type[2][maxn][maxn];

int n,m,q;
int a[maxn][maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;

    cnt=n*m;
    for (int i=n;i;--i)
        for (int j=m;j;--j) {
            a[i][j]=1;
            rep(d,0,2) {
                type[d][i][j]=1+type[d^1][i-dir[d][0]][j-dir[d][1]];
                sum+=type[d][i][j];
                // dbg(i,j,d,type[d][i][j]);
            }
        }

    while (q--) {
        int x,y;
        cin>>x>>y;
        auto ins=[&](int sx,int sy) {
            cnt++;
            a[sx][sy]=1;
            rep(st,0,2) {
                int d=st,tmp=1+type[d^1][x-dir[d][0]][y-dir[d][1]];
                int x=sx,y=sy;
                // dbg(st,tmp,x-dir[d][0],y-dir[d][1]);
                while (x>=1&&y>=1&&a[x][y]==1) {
                    sum+=tmp;
                    type[d][x][y]+=tmp;
                    d^=1;
                    x+=dir[d][0];
                    y+=dir[d][1];
                }
            }
        };
        auto del=[&](int sx,int sy) {
            // cout<<"del"<<endl;
            cnt--;
            rep(st,0,2) {
                int d=st,tmp=1+type[d^1][x-dir[d][0]][y-dir[d][1]];
                int x=sx,y=sy;
                // dbg(st,tmp,x-dir[d][0],y-dir[d][1]);
                while (x>=1&&y>=1&&a[x][y]==1) {
                    sum-=tmp;
                    type[d][x][y]-=tmp;
                    d^=1;
                    x+=dir[d][0];
                    y+=dir[d][1];
                }
            }
            a[sx][sy]=-1;
        };
        if (a[x][y]==-1)
            ins(x,y);
        else
            del(x,y);
        cout<<sum-cnt<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/