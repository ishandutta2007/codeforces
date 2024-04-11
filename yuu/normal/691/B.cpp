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
#define taskname "B"
bool symmetric[256];
const string with_symmetric="AHIMOTUVWXYbdopqvwx";
const string symmetric_with="AHIMOTUVWXYdboqpvwx";
char mirror[256];
string s;
void output(int signal){
    puts(signal?"TAK":"NIE");
    exit(0);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    for(char c: with_symmetric) symmetric[c]=1;
    FFOR(i, 0, with_symmetric.size()) mirror[with_symmetric[i]]=symmetric_with[i];
    cin>>s;
    int i=0, j=s.size()-1;
    while(i<=j){
        if(!symmetric[s[i]]) output(0);
        if(!symmetric[s[j]]) output(0);
        if(mirror[s[i]]!=s[j]) output(0);
        i++;
        j--;
    }
    output(1);
}