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
#define taskname "F"
int n;
int a[2500][2500];
bitset <2500> b[2500];
vector <pair <int, int> > v;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FFOR(i, 0, n) FFOR(j, 0, n) read(a[i][j]);
    FFOR(i, 0, n) FFOR(j, 0, n) if(a[i][j]!=a[j][i]){
        puts("NOT MAGIC");
        return 0;
    }
    FFOR(i, 0, n) if(a[i][i]){
        puts("NOT MAGIC");
        return 0;
    }
    FFOR(i, 0, n) FFOR(j, 0, n) b[i][j]=1;
    FFOR(i, 0, n) FFOR(j, i+1, n) v.pb(mp(i, j));
    sort(v.begin(), v.end(), [](pair <int, int> A, pair <int, int> B){
        return a[A.first][A.second]>a[B.first][B.second];
    });
    int j=0;
    for(pair <int, int> p: v){
        while((j<v.size())&&(a[v[j].first][v[j].second]>=a[p.first][p.second])){
            b[v[j].first][v[j].second]=0;
            b[v[j].second][v[j].first]=0;
            j++;
        }
        bitset <2500> temp=b[p.first]&b[p.second];
        if(temp!=0){
            puts("NOT MAGIC");
            return 0;
        }
    }
    puts("MAGIC");
}