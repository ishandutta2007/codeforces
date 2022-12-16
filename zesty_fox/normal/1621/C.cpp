#include <bits/stdc++.h>

using namespace std;

using ll=long long;
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=10010;

int n;

int query(int x){
    cout<<"? "<<x<<endl;
    return rdi();
}

vector<vi> lp;
int vis[N],p[N];
void solve(){
    
    n=rdi();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vi lp;
            while(1){
                int x=query(i);
                if(vis[x]) break;
                lp.pb(x),vis[x]=1;
            }
            for(int i=0;i<(int)lp.size();i++){
                p[lp[i]]=lp[(i+1)%lp.size()];
            }
        }
    }
    
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<p[i]<<' ';
    cout<<endl;
    
    for(int i=1;i<=n;i++) vis[i]=p[i]=0;
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}