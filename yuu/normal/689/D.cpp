#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "D"
struct rmq{
    bool minrmq;
    int a[200001][20], n;
    void init(){
        if(minrmq){
            for(int j=1, temp=2;temp<=n; j++, temp<<=1){
                for(int i=1; i+temp-1<=n; i++){
                    a[i][j]=min(a[i][j-1], a[i+(temp>>1)][j-1]);
                }
            }
        }
        else{
            for(int j=1, temp=2;temp<=n; j++, temp<<=1){
                for(int i=1; i+temp-1<=n; i++){
                    a[i][j]=max(a[i][j-1], a[i+(temp>>1)][j-1]);
                }
            }
        }
    }
    int get(int l, int r){
        if(l==r) return a[l][0];
        int z=__lg(r-l);
        if(minrmq)
            return min(a[l][z], a[r-(1<<z)+1][z]);
        else
            return max(a[l][z], a[r-(1<<z)+1][z]);
    }
} rA, rB;
int n;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    rA.minrmq=0;
    rB.minrmq=1;
    read(n);
    rA.n=n;
    rB.n=n;
    FOR(i, 1, n)
        read(rA.a[i][0]);
    FOR(i, 1, n)
        read(rB.a[i][0]);
    rA.init();
    rB.init();
    ll ans=0;
    FOR(i, 1, n){
        int l=1, r=i, m, res=0;
        while(l<=r){
            m=(l+r)/2;
            if(rA.get(m, i)>=rB.get(m, i)){
                res=m;
                l=m+1;
            }
            else
                r=m-1;
        }
        if(res){
            if(rA.get(res, i)!=rB.get(res, i)) continue;
            int res2=0;
            l=1, r=res;
            while(l<=r){
                m=(l+r)/2;
                if(rA.get(m, i)==rB.get(m, i)){
                    res2=m;
                    r=m-1;
                }
                else
                    l=m+1;
            }
            ans+=res-res2+1;
        }
    }
    writeln(ans);
}