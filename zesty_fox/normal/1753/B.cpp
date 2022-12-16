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

const int N=5e5+10;

int n,x,a[N],cnt[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),x=rdi();
    for(int i=1;i<=n;i++) cnt[rdi()]++;
    for(int i=1;i<x;i++){
        if(cnt[i]%(i+1)){
            puts("No");
            return 0;
        }
        cnt[i+1]+=cnt[i]/(i+1),cnt[i]=0;
    }
    puts("Yes");
    return 0;
}