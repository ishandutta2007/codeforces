#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
int n,m,q,deg[N],ans;
int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        if(x>y) swap(x,y);
        deg[x]++;
    }
    for(int i=1;i<=n;i++)
        if(!deg[i]) ans++;
    q=rdi();
    while(q--){
        int op=rdi(),x,y;
        if(op==1){
            x=rdi(),y=rdi();
            if(x>y) swap(x,y);
            deg[x]++;
            if(deg[x]==1) ans--;
        }
        else if(op==2){
            x=rdi(),y=rdi();
            if(x>y) swap(x,y);
            deg[x]--;
            if(!deg[x]) ans++;
        }
        else printf("%d\n",ans);
    }
    return 0;
}