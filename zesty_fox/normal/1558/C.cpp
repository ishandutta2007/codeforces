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

const int N=4010;
int n,a[N];
vi res;
void operate(int x){
    reverse(a+1,a+x+1);
    res.pb(x);
}

void solve(){
    n=rdi();res.clear();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++){
        if((i^a[i])&1){
            puts("-1");
            return;
        }
    }
    for(int i=n;i>1;i-=2){
        int pos1,pos2;
        for(int j=1;j<=n;j++){
            if(a[j]==i) pos1=j;
        }
        operate(pos1);
        for(int j=1;j<=n;j++){
            if(a[j]==i-1) pos2=j;
        }
        operate(pos2-1);
        operate(pos2+1);
        operate(3);
        operate(i);
    }
    printf("%lu\n",res.size());
    for(auto tmp:res) printf("%d ",tmp);
    puts("");
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}