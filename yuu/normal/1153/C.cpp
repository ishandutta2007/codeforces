#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "C"
string s;
bool q[300000];
int n;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>s;
    n-=2;
    if((s.size()%2)||(s[0]==')')||(s.back()=='(')){
        puts(":(");
        return 0;
    }
    s[0]='(';
    s.back()=')';
    int cnt=0;
    FOR(i, 1, n){
        if(s[i]=='(') cnt++;
        else if(s[i]==')') cnt--;
        else{
            q[i]=1;
            s[i]='(';
            cnt++;
        }
        if(cnt<0){
            puts(":(");
            return 0;
        }
    }
    DFOR(i, n, 1) if(q[i]&&cnt){
        s[i]=')';
        cnt-=2;
    }
    if(cnt){
        puts(":(");
        return 0;
    }
    cnt=0;
    FOR(i, 1, n){
        if(s[i]=='(') cnt++;
        else if(s[i]==')') cnt--;
        if(cnt<0){
            puts(":(");
            return 0;
        }
    }
    cout<<s<<'\n';
}