#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define pb push_back

const int N=1010;

int n,p[N],vis[N];
char s[N][N];

void spj(){
    for(int i=1;i<=n;i++) if(p[i]!=i) return;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++) cout<<string(n,'.')<<'\n';
    exit(0);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    spj();

    for(int i=n,pos=1;i>=1;i--){
        if(vis[i]||p[i]==i) continue;
        vi l;int x=i;
        while(!vis[x]) vis[x]=1,l.pb(x),x=p[x];
        for(auto x:l){
            if(x==n) continue;
            if(x==l.back()){
                if(l[0]!=n) s[pos][x]=s[pos][n]='/',s[pos-l.size()+1][n]=s[pos-l.size()+1][l[0]]='\\',pos++;
                else s[pos][x]=s[pos][n]='/',pos++;
                break;
            }
            if(p[x]>x) s[pos][x]='/',s[pos][p[x]]='/';
            else s[pos][x]='\\',s[pos][p[x]]='\\';
            pos++;
        }
    }
    cout<<n-1<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) putchar(s[i][j]=='\0'?'.':s[i][j]);
        putchar('\n');
    }
    return 0;
}