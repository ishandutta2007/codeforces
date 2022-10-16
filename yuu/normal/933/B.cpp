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
#define taskname "B"
ll p;
int k;
deque <int> q;
deque <int> ans;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(p);
    read(k);
    while(p>0){
        q.pb(p%k);
        p/=k;
    }
    FFOR(i, 0, q.size()){
        if(q[i]<0){
            if(i+1==q.size()) q.pb(0);
            while(q[i]<0){
                q[i]+=k;
                q[i+1]--;
            }
        }
        else if(q[i]>=k){
            if(i+1==q.size()) q.pb(0);
            while(q[i]>=k){
                q[i]-=k;
                q[i+1]++;
            }
        }
        if(i%2==0) ans.pb(q[i]);
        else if(q[i]>0){
            ans.pb(k-q[i]);
            if(i+1==q.size()) q.pb(0);
            q[i+1]++;
        }
        else ans.pb(0);
    }
    while(ans.back()==0) ans.pop_back();
    writeln(ans.size());
    for(int x: ans) write(x), putchar(' ');
}