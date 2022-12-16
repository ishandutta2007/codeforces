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

const int N=1050010;

int n;
char s[N];
bool cut[N];

void solve(){
    scanf("%s",s+1);n=strlen(s+1);
    int cnt=count(s+1,s+n+1,'1');
    if(!cnt) {puts("-1");return;}
    for(int p=1;;p<<=1){
        int rest=p-cnt;
        if(rest<0) continue;
        for(int i=1;i<=n;i++) cut[i]=0;
        int cnt=0;
        for(int i=1,nw=0,c1=0;i<=n;i++){
            nw=nw*2+s[i]-'0',c1+=s[i]-'0';
            if(i==n||nw*2-c1>rest) 
                rest-=nw-c1,cut[i]=1,c1=nw=0,++cnt;
        }
        if(!rest){
            cout<<cnt<<'\n';
            for(int i=1,lst=0;i<=n;i++)
                if(cut[i]) cout<<lst+1<<' '<<i<<'\n',lst=i;
            break;
        }
        else continue;
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}