#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=14;
const i64 INF=0x3f3f3f3f3f3f3f3f;

int n,a[N],b[N];
char s[N+1];

inline int toxdigit(int c) {return isdigit(c)?c-'0':c-'a'+10;} 

i64 solve(){
    static i64 sum[(1<<N)+1],f[(1<<N)+1];
    int tmp=0;
    for(int i=0;i<n;i++){
        if(b[i]<-15||b[i]>15) return INF;
        tmp+=b[i];
    }
    if(tmp) return INF;
    sum[0]=0;
    for(int i=1;i<(1<<n);i++){
        int lb=__builtin_ctz(i);
        sum[i]=sum[i^(1<<lb)]+b[lb];
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<(1<<n);i++){
        if(-sum[i]<0||-sum[i]>15) continue;
        for(int j=0;j<n;j++)
            if(i>>j&1) f[i]=min(f[i],f[i^(1<<j)]+((-sum[i])<<(j<<2)));
    }
    return f[(1<<n)-1];
}

int main(){
    scanf("%s",s);
    n=strlen(s),reverse(s,s+n);
    for(int i=0;i<n;i++) a[i]=toxdigit(s[i]);
    i64 ans=INF;
    for(int i=0;i<(1<<(n-1));i++){
        for(int j=0;j<n;j++) b[j]=a[j];
        for(int j=0;j<n;j++) if(i>>j&1) b[j]-=16,b[j+1]+=1;
        i64 tmp=solve();
        if(tmp!=-1&&tmp<ans) ans=tmp;
    }
    if(ans<INF){
        char fmt[100];sprintf(fmt,"%%0%dllx\n",n);
        printf(fmt,ans);
    }
    else puts("NO");
    return 0;
}