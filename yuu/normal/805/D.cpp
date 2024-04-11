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
#define taskname "D"
ll p2[1000001];
ll base=1000000007;
string s;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    p2[0]=1;
    cin>>s;
    FOR(i, 1, s.size())
        p2[i]=(p2[i-1]*2)%base;
    int acnt=0;
    ll bcnt=0;
    ll ans=0;
    int i=0;
    while(i<s.size()){
        if(s[i]=='a'){
            acnt++;
            i++;
        }
        else{
            bcnt=0;
            while(i<s.size()&&s[i]=='b'){
                i++;
                bcnt++;
            }
            i--;
            ans=(ans+(p2[acnt]-1)*bcnt)%base;
            i++;
        }
    }
    ans=(ans+base)%base;
    write(ans);
}