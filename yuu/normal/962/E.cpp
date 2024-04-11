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
#define taskname "E"
int n;
ll x[200001];
char c[200001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(x[i]);
        while(!isalpha(c[i]=getchar()));
    }
    ll ans=0;
    int first=1;
    FOR(i, 1, n) if(c[i]=='P'){
        if(first){
            FFOR(j, 1, i) if(c[j]=='B'){
                ans+=x[i]-x[j];
                break;
            }
            FFOR(j, 1, i) if(c[j]=='R'){
                ans+=x[i]-x[j];
                break;
            }
            first=0;
        }
        int j=i+1;
        int first_r=0, first_b=0;
        int last_r=0, last_b=0;
        while((j<=n)&&(c[j]!='P')){
            if(c[j]=='R'){
                if(first_r==0) first_r=j;
                last_r=j;
            }
            else{
                if(first_b==0) first_b=j;
                last_b=j;
            }
            j++;
        }
        if(j>n){
            if(first_b) ans+=x[last_b]-x[i];
            if(first_r) ans+=x[last_r]-x[i];
        }
        else{
            ll tog=x[j]-x[i];
            if(first_b){
                tog+=x[j]-x[i];
                ll best=max(x[first_b]-x[i], x[j]-x[last_b]);
                int last=first_b;
                FOR(k, first_b+1, last_b) if(c[k]=='B'){
                    best=max(best, x[k]-x[last]);
                    last=k;
                }
                tog-=best;
            }
            if(first_r){
                tog+=x[j]-x[i];
                ll best=max(x[first_r]-x[i], x[j]-x[last_r]);
                int last=first_r;
                FOR(k, first_r+1, last_r) if(c[k]=='R'){
                    best=max(best, x[k]-x[last]);
                    last=k;
                }
                tog-=best;
            }
            if(!(first_b||first_r)) ans+=tog;
            else ans+=min(tog, (x[j]-x[i])*2);
        }
        i=j-1;
    }
    if(first){
        int first_r=0, first_b=0;
        int last_r=0, last_b=0;
        FOR(i, 1, n){
            if(c[i]=='R'){
                if(first_r==0) first_r=i;
                last_r=i;
            }
            else{
                if(first_b==0) first_b=i;
                last_b=i;
            }
        }
        ans=x[last_r]-x[first_r]+x[last_b]-x[first_b];
    }
    writeln(ans);
}