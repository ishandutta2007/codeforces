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
#define taskname "D"
#define left Mikoto
#define right Index
multiset <ll> left, right;
int n;
int a[100001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) right.insert(a[i]);
    ll sum=0;
    FOR(i, 1, n) sum-=a[i];
    FOR(i, 0, n){
        if(i){
            sum+=a[i]*2;
            left.insert(a[i]);
            right.erase(right.find(a[i]));
        }
        if(sum%2) continue;
        if(sum==0){
            puts("YES");
            return 0;
        }
        if(sum>0){
            if(left.find(sum/2)!=left.end()){
                puts("YES");
                return 0;
            }
        }
        else{
            if(right.find(-sum/2)!=right.end()){
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
}