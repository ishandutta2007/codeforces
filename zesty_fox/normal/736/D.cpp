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

const int N=2010,M=500010;
int n,m;
bitset<N*2> a[N];
void qiuni(){
    for(int i=1;i<=n;i++) a[i][i+n]=1;
    for(int i=1;i<=n;i++){
        if(!a[i][i]){
            for(int j=i+1;j<=n;j++){
                if(a[j][i]) {swap(a[i],a[j]);break;}
            }
        }
        for(int j=1;j<=n;j++){
            if(i!=j&&a[j][i]) a[j]^=a[i];
        }
    }
}

pii q[M];
int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        q[i].fi=rdi(),q[i].se=rdi();
        a[q[i].fi][q[i].se]=1;
    }
    qiuni();
    for(int i=1;i<=m;i++){
        puts(a[q[i].se][q[i].fi+n]?"NO":"YES");
    }
    return 0;
}