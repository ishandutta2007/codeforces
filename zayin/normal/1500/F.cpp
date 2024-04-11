#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define mt make_tuple
#define rep(i,begin,end) for (__typeof(begin) i=(begin),_end=(end),_step=1-2*((begin)>(end));i!=_end;i+=_step)

// OUTPUT
template<class a, class b>
ostream& operator << (ostream& os, const pair<a,b>& p)  {
    os<<"["<<p.first<<","<<p.second<<"]";
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


#define maxn 1500050
#define modu 998244353
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

template<class S,class T>
pair<S,T> operator + (const pair<S,T>& a,const pair<S,T>& b)  {
    return mp(a.first+b.first,a.second+b.second);
}
template<class S,class T,class U>
pair<S,T> operator + (const pair<S,T>& a,const U& b)  {
    return mp(a.first+b,a.second+b);
}
template<class S,class T,class U>
pair<S,T> operator * (const pair<S,T>& a,const U& b)  {
    return mp(a.first*b,a.second*b);
}

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

int n;
LL C,w[maxn];


namespace List  {
    int sz,len;
    LL rev,offset;
    int head,tail,dir;
    int nxt[maxn][2];
    pll I[maxn];

    int size()  {
        return len;
    }
    void insert(LL l,LL r)    {
        int k=++sz;
        if (rev)
            I[k]=mp(offset-r,offset-l);
        else
            I[k]=mp(l-offset,r-offset);
        
        if (!len++)
            head=tail=k;
        else
            nxt[tail][dir]=k,nxt[k][dir^1]=tail,tail=k;
        
    }
    pll norm(pll p) {
        if (rev)
            return mp(offset-p.second,offset-p.first);
        return p+offset;
    }
    pll front()   {
        return norm(I[head]);
    }
    pll back()   {
        return norm(I[tail]);
    }
    void pop()  {
        tail=nxt[tail][dir^1];
        nxt[tail][dir]=0;
        if (--len==1)
            head=tail;
    }
    void reverse()  {
        rev^=1,dir^=1;
        swap(head,tail);
        offset=-offset;
    }
    void shift(LL d)    {
        offset+=d;
    }
    void clear() {
        rev=offset=len=dir=0;
    }
    void pr()    {
        int k=head;
        // dbg(head,tail,len);
        rep(turn,0,len) {
            cout<<norm(I[k])<<" ";
            k=nxt[k][dir];
        }
        cout<<endl;
    }
}

LL type1[maxn],type2[maxn];
LL d[maxn];

int main()  {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    read(n,C);
    readarray(w+1,n-2);

    List::insert(0,w[1]);
    // List::pr();
    rep(i,1,n-1)    {
        type2[i]=List::front().first;
        while (List::size()&&List::back().first>w[i]) List::pop();
        if (!List::size())  {
            print("NO");
            return 0;
        }
        assert(List::back().first<=w[i]);
        if (List::back().second>=w[i]) {
            type1[i]=1;
            List::clear();
            List::insert(0,w[i]);
        } else {
            List::reverse();
            List::shift(w[i]);
            if (List::back().second<w[i])
                List::insert(w[i],w[i]);
        }
        // List::pr();
        // print("");
    }

    d[n-2]=List::front().first;
    rep(i,n-3,-1)    {
        if (type1[i+1])
            d[i]=w[i+1];
        else
        if (d[i+1]==w[i+1])
            d[i]=type2[i+1];
        else
            d[i]=w[i+1]-d[i+1];
    }

    // rep(i,0,n-1)
    //     dbg(i,d[i]);

    rep(i,1,n-1)    {
        if (max({abs(d[i]),abs(d[i-1]),abs(d[i]+d[i-1])})!=w[i])
            d[i]=-d[i];
        // dbg(i,d[i-1],d[i],w[i],max({abs(d[i]),abs(d[i-1]),abs(d[i]+d[i-1])}));
        assert(max({abs(d[i]),abs(d[i-1]),abs(d[i]+d[i-1])})==w[i]);
    }

    vector<LL> res(1,0);
    rep(i,0,n-1)
        res.push_back(res.back()+d[i]);
    rep(i,1,n-1)
        assert(max({res[i-1],res[i],res[i+1]})-min({res[i-1],res[i],res[i+1]})==w[i]);
    LL mn=min(res);
    print("YES");
    for (LL x:res) cout<<x-mn<<" ";
    return 0;
}
/*README
1. Is modu correct?
2. Is maxn correct?
*/