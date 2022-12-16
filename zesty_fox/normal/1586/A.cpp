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

const int N=110;
int n,a[N],b[N],ans;
bool isprime(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}
void solve(){
    n=rdi();int sum=0;
    for(int i=1;i<=n;i++) a[i]=rdi(),sum+=a[i];
    if(!isprime(sum)){
        printf("%d\n",n);
        for(int i=1;i<=n;i++) printf("%d ",i);
        puts("");return;
    }
    for(int i=1;i<=n;i++){
        if(!isprime(sum-a[i])){
            printf("%d\n",n-1);
            for(int j=1;j<=n;j++) if(j!=i) printf("%d ",j);
            puts("");return;
        }
    }
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}