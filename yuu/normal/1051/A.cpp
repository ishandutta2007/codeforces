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
#define taskname "A"
string s;
void solve(){
    cin>>s;
    pair <vector <int>, char> pos[3];
    pos[0].second='0';
    pos[1].second='a';
    pos[2].second='A';
    FFOR(i, 0, s.size()) if(isdigit(s[i])) pos[0].first.pb(i);
    else if(islower(s[i])) pos[1].first.pb(i);
    else pos[2].first.pb(i);
    sort(pos, pos+3, [](pair <vector <int>, char> A, pair <vector <int>, char> B){
        return A.first.size()<B.first.size();
    });
    if(pos[0].first.empty()){
        if(pos[1].first.empty()){
            s[0]=pos[0].second;
            s[1]=pos[1].second;
            cout<<s<<'\n';
        }
        else{
            s[pos[2].first[0]]=pos[0].second;
            cout<<s<<'\n';
        }
    }
    else{
        cout<<s<<'\n';
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    int t;
    read(t);
    while(t--) solve();
}