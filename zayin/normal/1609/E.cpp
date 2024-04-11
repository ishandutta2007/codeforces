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

struct matrix {
    static const int N=3;
    int A[N][N];
    matrix() {
        memset(A,0x3f,sizeof(A));
    }
    friend matrix operator * (const matrix& a,const matrix& b)  {
        matrix ans;
        // memset(ans.A,0x3f,sizeof(ans.A));
        for (int i=0;i<N;++i)
            for (int k=0;k<N;++k)
                for (int j=0;j<N;++j)
                    ans.A[i][j]=min(ans.A[i][j],a.A[i][k]+b.A[k][j]);
        return ans;
    }
};



matrix get(char c)  {
    matrix ans;
    ans.A[0][0]=(c=='a');
    ans.A[1][0]=(c!='a');
    ans.A[1][1]=(c=='b');
    ans.A[2][1]=(c!='b');
    ans.A[2][2]=(c=='c');
    return ans;
}

ostream& operator << (ostream& os,const matrix& A)  {
    for (int i=0;i<3;++i)   {
        cout<<"[";
        for (int j=0;j<3;++j)
            cout<<A.A[i][j]<<" ";
        os<<"]"<<endl;
    }
    return os;
}

matrix T[maxn<<2];

int n,m;
char s[maxn];

void change(int k,int l,int r,int p)    {
    if (r<p||p<l) return ;
    if (l==r)
        T[k]=get(s[p]);
    else {
        int mid=(l+r)>>1;
        change(k<<1,l,mid,p);
        change(k<<1|1,mid+1,r,p);
        T[k]=T[k<<1|1]*T[k<<1];
    }
    // dbg(k,l,r,T[k]);
}

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s+1;
    for (int i=1;i<=n;++i)
        change(1,1,n,i);
    while (m--) {
        int i;
        cin>>i;
        cin>>s[i];
        change(1,1,n,i);
        int ans=n;
        for (int i=0;i<matrix::N;++i)
            for (int j=0;j<matrix::N;++j)   {
                // dbg(i,j,T[1].A[i][j]);
                ans=min(ans,T[1].A[i][j]);
            }
        cout<<ans<<endl;
    }
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/