#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
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
#define taskname "E"
ll ans[11];
const ll base=1000003;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
class equation{
public:
    ll a[12];
    equation(int x, ll res){
        ll w=1;
        FOR(i, 0, 10){
            a[i]=w;
            w=(w*x)%base;
        }
        a[11]=res;
    }
    void convert_to_one(int pos){
        assert(a[pos]);
        ll f=power(a[pos], base-2);
        FFOR(i, 0, 12) a[i]=(a[i]*f)%base;
    }
    void eliminate(int pos, equation e){
        ll f=a[pos];
        FFOR(i, 0, 12) a[i]=((a[i]-e.a[i]*f)%base+base)%base;
    }
};
vector <equation> E;
ll a[11];
void test(ll x){
    ll n=1;
    ll res=0;
    FOR(i, 0, 10){
        res=(res+n*a[i])%base;
        n=(n*x)%base;
    }
    if(res==0){
        printf("! %I64d\n", x);
        fflush(stdout);
        exit(0);
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    FOR(i, 0, 10){
        printf("? %d\n", i);
        fflush(stdout);
        scanf("%d", ans+i);
        E.pb(equation(i, ans[i]));
    }
    FOR(i, 0, 10){
        if(E[i].a[i]==0){
            FOR(j, i+1, 10){
                if(E[j].a[i]){
                    swap(E[i], E[j]);
                    break;
                }
            }
        }
        if(E[i].a[i]==0) exit(-1);
        E[i].convert_to_one(i);
        FFOR(j, 0, i) E[j].eliminate(i, E[i]);
        FOR(j, i+1, 10) E[j].eliminate(i, E[i]);

//        FOR(i, 0, 10) FOR(j, 0, 11) cerr<<E[i].a[j]<<" \n"[j==11];
//        cerr<<"____________________________________________\n";
    }
    FOR(i, 0, 10){
        a[i]=E[i].a[11];
//        cerr<<a[i]<<" \n"[i==10];
    }
    FFOR(i, 0, base) test(i);
    puts("! -1");
    fflush(stdout);
}