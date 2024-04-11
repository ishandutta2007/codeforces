//

#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int MOD=1e9+7,N=1e6+10;

char s[N];
int n;

i64 calc(char s[],int n){
    if(s[1]=='0'||s[n]=='0'){
        int p1=1,p2=n;
        while(p1<=n&&s[p1]=='0') ++p1;
        if(p1>n) return n;
        while(p2>=1&&s[p2]=='0') --p2;
        return (i64)p1*(n-p2+1)%MOD*calc(s+p1-1,p2-p1+1)%MOD;
    }
    static int cnt[N];int tot=0;
    for(int i=2,c=0;i<=n;i++){
        if(s[i]=='1') cnt[++tot]=c,c=0;
        else ++c;
    }
    static i64 f[N],sum[N];
    static int st[N],tp;
    f[0]=sum[0]=1;
    for(int i=1;i<=tot;i++){
        int lst=i-1;
        while(tp&&cnt[st[tp]]<cnt[i]){
            f[i]+=(sum[lst-1]+MOD-(st[tp-1]?sum[st[tp-1]-1]:0))*(cnt[i]-cnt[st[tp]])%MOD;
            lst=st[tp-1],--tp;
        }
        (f[i]+=f[i-1]*(cnt[i]+1))%=MOD;
        sum[i]=(sum[i-1]+f[i])%MOD;
        st[++tp]=i;
    }
    return sum[tot];
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    scanf("%s",s+1);
    n=strlen(s+1);
    cout<<calc(s,n)<<'\n';
    return 0;
}