#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
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
#define taskname "D1"
class rational{
public:
    ll a, b;
    int id;
    void input(int id){
        this->id=id;
        int a, b, c;
        read(a);
        read(b);
        read(c);
        this->a=a+b;
        this->b=c;
    }
} r[200001];
int ans[200001];
int n;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FOR(i, 1, n) r[i].input(i);
    sort(r+1, r+n+1, [](rational A, rational B){
        return A.a*B.b<A.b*B.a;
    });
    FOR(i, 1, n){
        int j=i;
        while((j+1<=n)&&(r[i].a*r[j+1].b==r[i].b*r[j+1].a)) j++;
        FOR(k, i, j) ans[r[k].id]=j-i+1;
        i=j;
    }
    FOR(i, 1, n){
        write(ans[i]);
        putchar(" \n"[i==n]);
    }
}