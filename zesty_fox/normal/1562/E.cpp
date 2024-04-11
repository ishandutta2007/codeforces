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

const int N=5010;
int n,lcp[N][N],f[N],ans;
char s[N];
void solve(){
    n=rdi();scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        f[i]=0;
        for(int j=1;j<=n;j++) lcp[i][j]=0;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(s[i]!=s[j]) lcp[i][j]=lcp[j][i]=0;
            else lcp[i][j]=lcp[j][i]=lcp[i+1][j+1]+1;
        }
    }
    for(int i=1;i<=n;i++){
        f[i]=n-i+1;
        for(int j=1;j<i;j++){
            int x=lcp[j][i];
            if(s[j+x]<s[i+x]) f[i]=max(f[i],f[j]+n-i-x+1);
        }
    }
    ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}