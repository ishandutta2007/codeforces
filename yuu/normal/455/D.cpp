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
#define taskname "455D_sqrt_decomposition"
const int mahou=500;
const int shoujo=100000/mahou+2;
//const int mahou=3;
int cnt[shoujo][100001];
deque <int> x[shoujo];
int a[100002];
int from[100002];
int pos[100002];
int n;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n){
        from[i]=from[i-1]+(((i-1)%mahou)==0);
        pos[i]=(i%mahou)-1;
        if(pos[i]==-1) pos[i]=mahou-1;
    }
    FOR(i, 1, n){
        x[from[i]].pb(a[i]);
        cnt[from[i]][a[i]]++;
    }
    {
        int q, o, l, r, k;
        int ans=0;
        read(q);
        FOR(query_id, 1, q){
            read(o);
            read(l);
            read(r);
            l=(l+ans-1)%n+1;
            r=(r+ans-1)%n+1;
            if(l>r) swap(l, r);
            if(o==1){
                int vr=x[from[r]][pos[r]];
                x[from[r]].erase(x[from[r]].begin()+pos[r]);
                cnt[from[r]][vr]--;
                for(int j=from[r]-1; j>=from[l]; j--){
                    cnt[j][x[j].back()]--;
                    cnt[j+1][x[j].back()]++;
                    x[j+1].push_front(x[j].back());
                    x[j].pop_back();
                }
                x[from[l]].insert(x[from[l]].begin()+pos[l], vr);
                cnt[from[l]][vr]++;
            }
            else{
                read(k);
                k=(k+ans-1)%n+1;
                ans=0;
                for(; (l<=r)&&(from[l]==from[l-1]); l++) ans+=(x[from[l]][pos[l]]==k);
                for(; (l<=r)&&(from[r]==from[r+1]); r--) ans+=(x[from[r]][pos[r]]==k);
                if(l<=r) for(int i=from[l]; i<=from[r]; i++) ans+=cnt[i][k];
                writeln(ans);
            }
        }
    }
}