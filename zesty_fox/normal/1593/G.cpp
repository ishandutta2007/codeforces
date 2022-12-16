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

const int N=1000010;

char s[N];
int n,q,sum[2][N];

void solve(){
    scanf("%s",s+1);
    n=strlen(s+1);
    q=rdi();
    for(int i=1;i<=n;i++){
        sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
        sum[i&1][i]+=(s[i]=='('||s[i]==')');
    }
    while(q--){
        int l=rdi(),r=rdi();
        printf("%d\n",abs((sum[0][r]-sum[0][l-1])-(sum[1][r]-sum[1][l-1])));
    }
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}