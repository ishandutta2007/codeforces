#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define REP(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
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
#define taskname "D"
#include <algorithm>
#include <vector>
using namespace std;
int m;
long long p[200001];
vector <pair <long long, long long> > v;
long long lall[200010];
long long rall[200010];
long long ans=1;
const long long base=1000000007;
long long multi(long long x, long long y){
    if(y==0) return 1;
    long long temp=multi(x, y/2);
    temp=(temp*temp)%base;
    if(y%2)
        temp=(temp*x)%base;
    return temp;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(m);
    FOR(i, 1, m)
        read(p[i]);
    sort(p+1, p+m+1);
    v.push_back(make_pair(0, 0));
    FOR(i, 1, m){
        if(p[i]==v.back().first)
            v.back().second++;
        else v.push_back(make_pair(p[i], 1LL));
    }
    lall[0]=1;
    REP(i, 1, v.size()){
        pair<long long, long long> p=v[i];
        lall[i]=(lall[i-1]*(p.second+1LL))%(base-1);
    }
    rall[v.size()]=1;
    DFOR(i, v.size()-1, 1){
        pair<long long, long long> p=v[i];
        rall[i]=(rall[i+1]*(p.second+1LL))%(base-1);
    }
    REP(i, 1, v.size()){
        pair<long long, long long> p=v[i];
        long long temp=(lall[i-1]*rall[i+1])%(base-1);
        long long temp2=multi(p.first, p.second*(p.second+1LL)/2LL);
        ans=(ans*multi(temp2, temp))%base;
    }
    writeln(ans);
}