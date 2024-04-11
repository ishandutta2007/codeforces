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
#define taskname "C"
int n, m, d;
class coffee{
public:
    int id, a;
    void input(int i){
        read(a);
        id=i;
    }
} a[200001];
multiset <pair <int, int> > s;
int pos[200001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(d);
    FOR(i, 1, n) a[i].input(i);
    sort(a+1, a+n+1, [](coffee A, coffee B){
        return A.a<B.a;
    });
    FOR(i, 1, n){
        if(s.empty()){
            pos[a[i].id]=1;
            s.insert(mp(a[i].a, 1));
        }
        else{
            if(a[i].a-s.begin()->first>d){
                pos[a[i].id]=s.begin()->second;
                s.erase(s.begin());
                s.insert(mp(a[i].a, pos[a[i].id]));
            }
            else{
                pos[a[i].id]=s.size()+1;
                s.insert(mp(a[i].a, pos[a[i].id]));
            }
        }
    }
    writeln(s.size());
    FOR(i, 1, n){
        write(pos[i]);
        putchar(" \n"[i==n]);
    }
}