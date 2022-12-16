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

const int N=1000010;
int n,a[N];
vector<pii> res;
void operate(int x,int y){
    res.pb(mp(x,y));
    a[x]=(a[x]+a[y]-1)/a[y];
}

void print_ans(){
    printf("%lu\n",res.size());
    for(auto tmp:res) printf("%d %d\n",tmp.fi,tmp.se);
}

const int MID=16;
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=i;
    res.clear();
    if(n<=MID){
        for(int i=3;i<n;i++) operate(i,i+1);
        while(a[n]>1) operate(n,2);
    }
    else{
        for(int i=3;i<n;i++)
            if(i!=MID) operate(i,i+1);
        while(a[n]>1) operate(n,MID);
        while(a[MID]>1) operate(MID,2);
    }
    print_ans();
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}