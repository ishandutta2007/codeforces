#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=1010;

int n,d[N],d1[N],c[N],vis[N];

int query(int x){
    cout<<"? "<<x<<endl;
    return rdi();
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) d[i]=rdi();

    int col=0;
    while(true){
        int x=0;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&(!x||d[i]>d[x])) x=i;
        if(!x) break;
        c[x]=++col,vis[x]=1;
        vi vec;
        for(int i=1;i<=d[x];i++){
            int y=query(x);
            if(!vis[y]) vis[y]=1,c[y]=col,vec.pb(y);
            else{
                c[x]=c[y];
                for(auto y:vec) c[y]=c[x];
                break;
            }
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<c[i]<<' ';
    cout<<endl;

    for(int i=1;i<=n;i++) d[i]=c[i]=vis[i]=0;
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}