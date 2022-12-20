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

int n;
int r[3],c[3];

void solve(){
    n=rdi();
    for(int i=0;i<3;i++)
        r[i]=rdi(),c[i]=rdi();

    int x=rdi(),y=rdi();

    if(count(r,r+3,1)==2&&count(c,c+3,1)==2){
        puts(x!=1&&y!=1?"NO":"YES");
        return;
    }
    if(count(r,r+3,n)==2&&count(c,c+3,1)==2){
        puts(x!=n&&y!=1?"NO":"YES");
        return;
    }
    if(count(r,r+3,1)==2&&count(c,c+3,n)==2){
        puts(x!=1&&y!=n?"NO":"YES");
        return;
    }
    if(count(r,r+3,n)==2&&count(c,c+3,n)==2){
        puts(x!=n&&y!=n?"NO":"YES");
        return;
    }
    for(int i=0;i<3;i++){
        if(x%2==r[i]%2&&y%2==c[i]%2)
            return (void)puts("YES");
    }
    puts("NO");
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--)
        solve();
    return 0;
}