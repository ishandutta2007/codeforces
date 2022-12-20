#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int N=100010,MOD=1e9+7;
char s[N];
int n;
ll ans=1,frac[N],f[N];
void pre(){
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%MOD;
}

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);pre();
    for(int i=1;i<=n;i++){
        if(s[i]=='w'||s[i]=='m'){
            puts("0");
            return 0;
        }
    }
    int len=0;
    for(int i=1;i<=n+1;i++){
        if(s[i]=='u') len++;
        else if(len) (ans*=f[len])%=MOD,len=0;
    }
    len=0;
    for(int i=1;i<=n+1;i++){
        if(s[i]=='n') len++;
        else (ans*=f[len])%=MOD,len=0;
    }
    cout<<ans<<endl;
    return 0;
}