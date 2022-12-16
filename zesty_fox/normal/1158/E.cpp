#include <bits/stdc++.h>

using namespace std;

using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define pb push_back

const int N=1010;

int n;
bitset<N> s[N],sl[N];

vi query(const vi &d){
    cout<<"? ";
    for(int i=0;i<n;i++) cout<<d[i]<<' ';
    cout<<endl;
    vi ret(n);string s;cin>>s;
    for(int i=0;i<n;i++) ret[i]=s[i]-'0';
    return ret;
}

int vis[N],pos[N];
void getdep(){
    vis[0]=1,sl[0][1]=1;
    for(int i=2;i<=n;i++) s[0][i]=1;
    while(count(vis,vis+n,1)<n){
        int tot=0;
        for(int i=0;i<n;i++) if(vis[i]) pos[++tot]=i;
        pos[tot+1]=n;
        for(auto st:{1,2}){
            vi d(n,0);
            for(int i=st;i<=tot;i+=2){
                int l=pos[i],r=pos[i+1],mid=(l+r+1)/2;
                if(mid!=r) for(int x=sl[l]._Find_first();x<=n;x=sl[l]._Find_next(x)) d[x-1]=mid-l;
            }
            vi tmp1=query(d);d=vi(n,0);
            for(int i=st;i<=tot;i+=2){
                int l=pos[i],r=pos[i+1],mid=(l+r+1)/2;
                if(mid!=r) for(int x=sl[l]._Find_first();x<=n;x=sl[l]._Find_next(x)) d[x-1]=mid-l-1;
            }
            vi tmp2=query(d);
            for(int i=st;i<=tot;i+=2){
                int l=pos[i],r=pos[i+1],mid=(l+r+1)/2;
                if(mid!=r){
                    vis[mid]=1;
                    for(int x=s[l]._Find_first();x<=n;x=s[l]._Find_next(x)){
                        if(!tmp2[x-1]){
                            s[l][x]=0,s[mid][x]=1;
                            if(tmp1[x-1]) sl[mid][x]=1,s[mid][x]=0;
                        }
                    }
                }
            }
        }
    }
}

int fa[N];
void getfa(){
    for(int st:{0,1,2}){
        for(int b=__lg(n);b>=0;b--){
            vi d(n,0);
            for(int i=st;i<n;i+=3)
                for(int x=sl[i]._Find_first();x<=n;x=sl[i]._Find_next(x))
                    if(x>>b&1) d[x-1]=1;
            auto tmp=query(d);
            for(int i=st+1;i<n;i+=3)
                for(int x=sl[i]._Find_first();x<=n;x=sl[i]._Find_next(x))
                    if(tmp[x-1]) fa[x]|=(1<<b);
        }
    }
}

int main(){
    n=rdi();
    getdep();getfa();
    cout<<"!\n";
    for(int i=2;i<=n;i++) cout<<fa[i]<<' '<<i<<endl;
    return 0;
}