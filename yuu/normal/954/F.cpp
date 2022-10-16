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
const ll base=1000000007;
class matrix{
public:
    ll f[3][3];
    matrix(int x){
//        bug(x);
        FFOR(i, 0, 3) FFOR(j, 0, 3) f[i][j]=0;
        FFOR(i, 0, 3) FOR(j, -1, 1) if(i+j>=0&&j+i<3) f[i][j+i]=1;
        FFOR(i, 0, 3) if(bit(x, i)) FFOR(j, 0, 3) f[j][i]=0;
    }
    matrix(){
        FFOR(i, 0, 3) FFOR(j, 0, 3) f[i][j]=0;
    }
    matrix operator *(matrix X){
        matrix res;
        FFOR(i, 0, 3) FFOR(j, 0, 3){
            FFOR(k, 0, 3) res.f[i][j]+=f[i][k]*X.f[k][j];
            res.f[i][j]%=base;
        }
        return res;
    }
    void operator *=(matrix X){
        (*this)=(*this)*X;
    }
};
matrix power(matrix a, ll x){
    if(x==1) return a;
    matrix res=power(a, x/2);
    res*=res;
    if(x%2) res*=a;
    return res;
}
int n;
ll m;
class event{
public:
    int a;
    ll pos;
    event(int a, ll pos){
        this->a=a;
        this->pos=pos;
    }
};
class cmp{
public:
    bool operator()(event A, event B){
        return A.pos>B.pos;
    }
};
priority_queue <event, vector <event>, cmp> q;
matrix ans;
int cnt[3];
int state;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    {
        int a;
        ll l, r;
        FOR(i, 1, n){
            read(a);
            read(l);
            read(r);
            a--;
            q.push(event(a, l));
            q.push(event(a-3, r+1));
        }
    }
    ans.f[0][1]=1;
    ll pos=1;
    while(!q.empty()){
//        bug(q.top().pos);
        if(q.top().pos-pos!=1){
            ans*=power(matrix(state), q.top().pos-pos-1);
            pos=q.top().pos-1;
        }
//        FFOR(i, 0, 3) FFOR(j, 0, 3) write(ans.f[i][j]), putchar(" \n"[j+1==3]);
        if(q.top().a<0){
            cnt[q.top().a+3]--;
            if(cnt[q.top().a+3]==0) state^=mask(q.top().a+3);
        }
        else{
            cnt[q.top().a]++;
            if(cnt[q.top().a]==1) state^=mask(q.top().a);
        }
        q.pop();
    }
    if(m-pos) ans*=power(matrix(state), m-pos);
    writeln(ans.f[0][1]);
}