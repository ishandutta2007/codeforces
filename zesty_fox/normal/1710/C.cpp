#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010,MOD=998244353;

char s[N];
i64 pw3[N],pw4[N];
int len;

i64 f[N][8][8];
i64 dfs(int x,int st,int lim){
    if(x<0) return st==7;
    if(f[x][st][lim]!=-1) return f[x][st][lim];
    auto &val=f[x][st][lim];val=0;
    for(int i=0;i<8;i++){
        int lim1=0,st1=st,fl=1;
        for(int j=0;j<3;j++){
            if((lim>>j&1)&&(i>>j&1)&&s[x]=='0') {fl=0;break;}
            else lim1|=((lim>>j&1)&&(i>>j&1)==s[x]-'0')<<j;
        }
        if(!fl) continue;
        if(i==1||i==6) st1|=1;
        if(i==2||i==5) st1|=2;
        if(i==3||i==4) st1|=4;
        val+=dfs(x-1,st1,lim1);
    }
    return val%=MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    scanf("%s",s);len=strlen(s);
    reverse(s,s+len);
    memset(f,-1,sizeof(f));
    cout<<dfs(len-1,0,7)<<'\n';
    return 0;
}