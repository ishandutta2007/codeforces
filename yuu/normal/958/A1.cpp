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
#define taskname "A1"
int n;
class star_map{
public:
    string s[10];
    void input(){
        FFOR(i, 0, n) cin>>s[i];
    }
//    void output(){
//        FFOR(i, 0, n) cerr<<s[i]<<'\n';
//        cerr<<"______________________________________________\n";
//    }
    bool operator == (star_map &A){
        FFOR(i, 0, n) if(s[i]!=A.s[i]) return 0;
        return 1;
    }
    void flip(){
        FFOR(i, 0, n) reverse(s[i].begin(), s[i].end());
    }
    void rotate(){
        star_map temp=(*this);
        FFOR(i, 0, n) FFOR(j, 0, n) s[i][j]=temp.s[n-j-1][i];
    }
} M1, M2;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>n;
    M1.input();
//    M1.output();
    M2.input();
//    M2.output();
    FOR(i, 0, 1){
        FFOR(j, 0, 4){
//            M2.output();
            if(M1==M2){
                puts("Yes");
                return 0;
            }
            M2.rotate();
        }
        M2.flip();
    }
    puts("No");
}