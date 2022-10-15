#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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

bool isprime(int x){
    if(x==1) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}

int n;
void solve(){
    n=rdi();
    if(n==1) puts("FastestFinger");
    else if(n&1) puts("Ashishgup");
    else{
        int cnt=0;
        while(n%2==0) n/=2,cnt++;
        if((cnt==1&&!isprime(n))||(cnt>1&&n>1)) puts("Ashishgup");
        else puts("FastestFinger");
    }
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}