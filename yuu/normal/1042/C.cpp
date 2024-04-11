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
int n;
int a[200001];
bool deleted[200002];
void output(){
    int des=1;
    while(deleted[des]) des++;
    FOR(i, des+1, n) if(!deleted[i]){
        write(1);
        putchar(' ');
        write(i);
        putchar(' ');
        writeln(des);
    }
}
vector <int> pos;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    int value=1;
    int zero=0;
    FOR(i, 1, n) if(a[i]<0) value=-value;
    else if(a[i]==0) zero++;
    if(!zero){
        if(value>0) output();
        else{
            int pos=0;
            a[0]=-1.5e9;
            FOR(i, 1, n) if((a[i]>a[pos])&&(a[i]<0)) pos=i;
            deleted[pos]=1;
            write(2);
            putchar(' ');
            writeln(pos);
            output();
        }
    }
    else{
        FOR(i, 1, n) if(a[i]==0) pos.pb(i);
        int res=n;
        FFOR(i, 1, pos.size()){
            write(1);
            putchar(' ');
            write(pos[i]);
            putchar(' ');
            writeln(pos[0]);
            deleted[pos[i]]=1;
            res--;
        }
        if(value<0){
            int p=0;
            a[0]=-1.5e9;
            FOR(i, 1, n) if((a[i]>a[p])&&(a[i]<0)) p=i;
            write(1);
            putchar(' ');
            write(p);
            putchar(' ');
            writeln(pos[0]);
            deleted[p]=1;
            res--;
        }
        if(res>1){
            write(2);
            putchar(' ');
            writeln(pos[0]);
            deleted[pos[0]]=1;
            output();
        }
    }
}