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
#define taskname "E1"
class point{
public:
    ll x, y;
    void input(){
        read(x);
        read(y);
    }
    void operator-=(point A){
        x-=A.x;
        y-=A.y;
    }
} A[10], B[10];
class line{
public:
    ll a, b, c;
    point A, B;
    line(point A, point B){
        this->A=A;
        this->B=B;
        a=B.y-A.y;
        b=A.x-B.x;
        c=-(a*A.x+b*A.y);
        ll d=__gcd(abs(a), abs(b));
        d=__gcd(d, abs(c));
        a/=d;
        b/=d;
        c/=d;
        if(a<0){
            a=-a;
            b=-b;
            c=-c;
        }
        else if(a==0){
            if(b<0){
                b=-b;
                c=-c;
            }
        }
    }
    ll at(point P){
        return a*P.x+b*P.y+c;
    }
    bool cut(line d){
        return ((d.at(A)*d.at(B))<0)&&((at(d.A)*at(d.B))<0);
    }
};
int matchB[10];
int matchA[10];
bool cut[10][10][10][10];
int n, m;
bool iscut(point A, point B, point C, point D){
    return line(A, B).cut(line(C, D));
}
void backtrack(int u){
    if(u==n){
        puts("Yes");
        exit(0);
    }
    else{
        FFOR(i, 0, n) if(matchB[i]==-1){
            FFOR(j, 0, u) if(cut[j][matchA[j]][u][i]) goto line0;
            matchA[u]=i;
            matchB[i]=u;
            backtrack(u+1);
            matchB[i]=-1;
            line0:;
        }
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    if(n!=m){
        puts("No");
        return 0;
    }
    FFOR(i, 0, n) matchB[i]=-1;
    FFOR(i, 0, n) A[i].input();
    FFOR(i, 0, n) B[i].input();
    FFOR(i, 0, n) FFOR(j, 0, n) FFOR(k, 0, n) FFOR(l, 0, n){
        cut[i][j][k][l]=iscut(A[i], B[j], A[k], B[l]);
    }
    backtrack(0);
    puts("No");
}