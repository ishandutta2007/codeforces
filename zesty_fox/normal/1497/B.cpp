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

const int N=100010;
int n,m,cnt[N],ans;
void solve(){
    n=rdi(),m=rdi();ans=0;
    for(int i=0;i<=m;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[rdi()%m]++;
    for(int i=0;i<=m/2;i++){
        if((i==m-i||i==0)&&cnt[i]) ans++;
        else if(cnt[i]==cnt[m-i]&&cnt[i]) ans++;
        else ans+=cnt[i]+cnt[m-i]-min(cnt[i],cnt[m-i])*2;
    }
    printf("%d\n",ans);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}