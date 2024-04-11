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
#define rdl read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010;
char s[N];
int n,ans;

int a[N];
void solve(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n+2;i++) a[i]=0;

    for(int i=1;i<=n;i++){
        if(i<=n-1&&s[i]==s[i+1]) a[i+1]|=1;
        if(i<=n-2&&s[i]==s[i+2]) a[i+2]|=2;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        if(a[i]==1){
            cnt++;
            a[i+1]&=2;
            a[i+2]&=1;
        }
        else if(a[i]==2){
            cnt++;
            a[i+1]&=2;
            a[i+2]&=1;
        }
        else if(a[i]==3){
            cnt++;
            a[i+1]&=2;
            a[i+2]&=1;
        }
    }
    printf("%d\n",cnt);
}

int T;
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
#endif
    T=rdi();
    while(T--) solve();
    return 0;
}