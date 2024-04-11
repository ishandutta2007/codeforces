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

const int N=55;

int n,m;
char s1[N],s2[N];
void solve(){
    cin>>n>>m>>s1>>s2;int fl=1;
    for(int i=1;i<=m;i++){
        if(s1[n-i]!=s2[m-i]){
            if(m-i>0) {fl=0;break;}
            bool flg=0;
            for(int j=n-i;j>=0;j--)
                if(s1[j]==s2[m-i]) {flg=1;break;}
            fl=flg;break;
        }
    }
    puts(fl?"YES":"NO");
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