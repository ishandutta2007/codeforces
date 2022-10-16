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
#define next _next
int n, start, x;
vector <int> v;
int next[50001];
int value[50001];
bool asked[50001];
int random(int x){
    return (rand()*rand())%x;
}
int from_vector(vector <int> &x){
    int r=random(x.size());
    swap(x[r], x.back());
    r=x.back();
    x.pop_back();
    return r;
}
int ans=15e8;
bool ask(int i){
    if(asked[i]) return 0;
    asked[i]=1;
    cout<<"? "<<i<<'\n';
    fflush(stdout);
    cin>>value[i]>>next[i];
    if(value[i]>=x) ans=min(ans, value[i]);
    return 1;
}
void answer(int a){
    if(a==15e8) a=-1;
    cout<<"! "<<a<<'\n';
    fflush(stdout);
    exit(0);
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    srand(time(NULL));
    cin>>n>>start>>x;
    FOR(i, 2, n) v.pb(i);
    ask(start);
    if(value[start]>=x) answer(value[start]);
    FFOR(i, 1, min(1000, n)) ask(from_vector(v));
    int b=start;
    FOR(i, 1, n) if(asked[i]) if(value[i]<x&&value[i]>value[b]) b=i;
    int t=next[b], r=900;
    while(t!=-1&&r>0){
        r--;
        ask(t);
        if(value[t]>=x) break;
        t=next[t];
    }
    answer(ans);
}