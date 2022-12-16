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

const int N=100010;

int n,m,k,a[N];
void solve(){
    n=rdi(),m=rdi(),k=rdi();
    for(int i=1;i<=k;i++) a[i]=rdi();
    sort(a+1,a+k+1,greater<int>());
    auto chk = [&](){
        i64 sum=0,s=0;
        for(int i=1;i<=k;i++){
            int c=a[i]/n;
            if(c>=2){
                if(sum+c<=m){
                    sum+=c,s+=c-2;
                    if(sum==m) return true;
                }
                else{
                    i64 d=sum+c-m;
                    if(d<c-1||s>=d) return true;
                }
            }
        }
        return false;
    };
    if(chk()) {puts("Yes");return;}
    swap(n,m);
    if(chk()) {puts("Yes");return;}
    puts("No");
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