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
#define taskname "B"
int n, m;
int l[101];
int a[101];
set <int> s;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, m) read(l[i]);
    FOR(i, 1, n) s.insert(i);
    FFOR(i, 1, m){
        int temp=(l[i+1]-l[i]+n)%n;
        if(temp==0) temp=n;
        if(a[l[i]]){
            if(a[l[i]]!=temp){
                puts("-1");
                return 0;
            }
        }
        else if(s.find(temp)==s.end()){
            puts("-1");
            return 0;
        }
        else{
            a[l[i]]=temp;
            s.erase(temp);
        }
    }
    FOR(i, 1, n) if(a[i]==0){
        a[i]=*s.begin();
        s.erase(s.begin());
    }
    FOR(i, 1, n){
        write(a[i]);
        putchar(" \n"[i==n]);
    }
}