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
#define taskname "A"
string s;
string a, b;
void process(string t){

    for(char c: t) if(!isdigit(c)){
        if(b.empty()) b+='"';
        else b+=',';
        b+=t;
        return;
    }
    if((t.empty())||((t.size()>1)&&(t[0]=='0'))){
        if(b.empty()) b+='"';
        else b+=',';
        b+=t;
        return;
    }
    if(a.empty()) a+='"';
    else a+=',';
    a+=t;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>s;
    string temp="";
    for(char c: s){
        if((c==';')||(c==',')){
            process(temp);
            temp="";
        }
        else temp+=c;
    }
    process(temp);
    if(a.empty()) a="-"; else a+='"';
    if(b.empty()) b="-"; else b+='"';
    cout<<a<<'\n'<<b;
}