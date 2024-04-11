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
string a, b;
string ans;
int cnt[256];
int temp[256];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>a>>b;
    if(b.size()>a.size()){
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout<<a;
        return 0;
    }
    for(auto t: a) cnt[t]++;
    bool good=0;
    FFOR(i, 0, b.size()){
        string res="";
        FFOR(j, 0, i) res+=b[j];
        FOR(i, '0', '9') temp[i]=cnt[i];
        DFOR(x, b[i]-1, '0') if(temp[x]){
            temp[x]--;
            res+=x;
            break;
        }
        DFOR(i, '9', '0'){
            while(temp[i]){
                temp[i]--;
                res+=i;
            }
        }
        if(res<=b) ans=max(ans, res);
        cnt[b[i]]--;
        if(cnt[b[i]]<0) break;
    }
    cout<<ans;
}