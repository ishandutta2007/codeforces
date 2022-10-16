#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "A"
int ans;
deque <int> f[300001];
int point[300001];
int up=1;
int n, t, q, o;
int cnt=0;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(q);
    FOR(i, 1, q){
        read(o);
        read(t);
        if(o==1){
            cnt++;
            point[cnt]=1;
            ans++;
            f[t].pb(cnt);
        }
        else if(o==2){
            while(!f[t].empty()){
                ans-=point[f[t].front()];
                point[f[t].front()]=0;
                f[t].pop_front();
            }
        }
        else{
            while(up<=t){
                ans-=point[up];
                point[up]=0;
                up++;
            }
        }
        writeln(ans);
    }
}