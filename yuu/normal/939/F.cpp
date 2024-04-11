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
#define taskname "F"
int n, k;
int l[102];
int r[102];
int f[102][100001];
deque <int> q1, q2;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(k);
    FOR(i, 1, k){
        read(l[i]);
        read(r[i]);
    }
    k++;
    l[k]=r[k]=n+n;
    FOR(i, 0, k) FOR(j, 0, n) f[i][j]=1e6;
    f[0][0]=0;
    FOR(i, 1, k){
        int next1=n;
        int next2=0;
        int skip=l[i]-r[i-1];
        int length=r[i]-l[i];
        q1.clear();
        q2.clear();
        FOR(j, 0, n){
            if(j>=length+skip){
                f[i][j]=min(f[i][j], f[i-1][j-(length+skip)]);
            }
            next1=min(next1, r[i]-j-skip);
            while(next1>=max(0, r[i]-length-j-skip)){
                while((!q1.empty())&&(f[i-1][q1.back()]>=f[i-1][next1])) q1.pop_back();
                q1.pb(next1);
                next1--;
            }
            while((!q1.empty())&&(q1.front()>r[i]-j-skip)) q1.pop_front();
            if(!q1.empty()){
                f[i][j]=min(f[i][j], f[i-1][q1.front()]+1);
            }
            next2=max(next2, j-skip-length);
            while(next2<=min(n, j-skip)){
                while((!q2.empty())&&(f[i-1][q2.back()]>=f[i-1][next2])) q2.pop_back();
                q2.pb(next2);
                next2++;
            }
            while((!q2.empty())&&(q2.front()<j-skip-length)) q2.pop_front();
            if(!q2.empty()) f[i][j]=min(f[i][j], f[i-1][q2.front()]+2);
        }
    }
    if(f[k][n]==1e6) puts("Hungry");
    else{
        puts("Full");
        write(f[k][n]);
    }
}