#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
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
#define taskname "B"
#define left left__
#define right right__
int x[60001];
int v[60001];
int n;
typedef long double ld;
vector <ld> left;
vector <ld> right;
ld res;
bool cmp(ld a, ld b){
    return a>b;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n)
        read(x[i]);
    FOR(i, 1, n)
        read(v[i]);
    ld l=0;
    ld r=1000000000;
    FOR(cnt, 1, 150){
        ld m=(l+r)/2;
        left.clear();
        right.clear();
        FOR(i, 1, n){
            left.push_back(ld(x[i])-m*v[i]);
            right.push_back(ld(x[i])+m*v[i]);
        }
        sort(left.begin(), left.end(), cmp);
        sort(right.begin(), right.end(), cmp);
        int temp=0, ans=0;
        FOR(i, 1, n){
            temp++;
            while(!right.empty()&&right.back()<left.back()){
                right.pop_back();
                temp--;
            }
            left.pop_back();
            ans=max(ans, temp);
        }
        if(ans==n){
            r=m;
            res=r;
        }
        else l=m;
    }
    cout<<setprecision(10)<<fixed<<res;
}