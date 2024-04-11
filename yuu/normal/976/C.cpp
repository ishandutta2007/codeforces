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
class segment{
public:
    int l, r, id;
    void input(int id){
        this->id=id;
        read(l);
        read(r);
    }
} s[300001];
int n;
set <pair <int, int> > q;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) s[i].input(i);
    sort(s+1, s+n+1, [](segment A, segment B){
        return (A.l<B.l)||((A.l==B.l)&&(A.r>B.r));
    });
    FOR(i, 1, n){
        while((!q.empty())&&(q.begin()->first<s[i].l)) q.erase(q.begin());
        if(!q.empty()){
            if(q.rbegin()->first>=s[i].r){
                write(s[i].id);
                putchar(' ');
                writeln(q.rbegin()->second);
                return 0;
            }
        }
        q.insert(mp(s[i].r, s[i].id));
    }
    puts("-1 -1");
}