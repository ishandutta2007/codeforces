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
#define mp make_pair
#define pb push_back

const int MAXN=10000010,N=200010;
const int PRS=510,LIM=3300;

int pr[MAXN],pcnt,v[MAXN],id[MAXN];
void init(int lim){
    v[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,pr[++pcnt]=i;}
        for(int j=1;j<=pcnt;j++){
            if(pr[j]>v[i]||pr[j]>lim/i) break;
            v[pr[j]*i]=pr[j];
        }
    }
    for(int i=1;i<=pcnt;i++) id[pr[i]]=i;
}

int frac(int x){
    for(int i=1;pr[i]<=x/pr[i];i++){
        if(x%pr[i]==0){
            while(x%pr[i]==0&&(x/pr[i]%pr[i]==0)) x/=pr[i],x/=pr[i];
        }
    }
    return x;
}

int n,k;
set<int> s;
void solve(){
    n=rdi(),k=rdi();
    
    s.clear();
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x=rdi(),tmp=frac(x);
        if(s.find(tmp)!=s.end()) cnt++,s.clear(),s.insert(tmp);
        else s.insert(tmp);
    }
    cnt++;printf("%d\n",cnt);
}

int T;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    T=rdi();init(MAXN-10);
    while(T--) solve();
    return 0;
}