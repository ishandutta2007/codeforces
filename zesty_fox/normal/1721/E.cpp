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

const int N=1e6+50,C=26;

char s[N];
int n;

int nxt[N],tr[N][C];
void append(char ch){
    s[++n]=ch,nxt[n]=tr[n-1][ch-'a'];
    for(int c=0;c<C;c++){
        if(s[nxt[n]+1]==c+'a') tr[n][c]=nxt[n]+1;
        else tr[n][c]=tr[nxt[n]][c];
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    scanf("%s",s+1);
    for(int i=1;s[i];i++) append(s[i]);
    int q=rdi();
    while(q--){
        static char t[N];scanf("%s",t+1);
        int lst=n;
        for(int i=1;t[i];i++) append(t[i]);
        for(int i=lst+1;i<=n;i++) cout<<nxt[i]<<' ';
        cout<<'\n';n=lst;
    }
    return 0;
}