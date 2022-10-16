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
string s;
string t;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>t;
    for(char c: t){
        if(c=='0'){
            if(!s.empty()) s+=c;
        }
        else s+=c;
    }
    if(s.empty()){
        cout<<"0";
        return 0;
    }
    int b=0;
    t=s;
    s="";
    FFOR(i, 0, t.size()){
        if(t[i]=='.') b=-(((int)t.size())-i-1);
        else s+=t[i];
    }
    while((!s.empty())&&(s.back()=='0')){
        s.pop_back();
        b++;
    }
    reverse(s.begin(), s.end());
    while((!s.empty())&&(s.back()=='0')) s.pop_back();
    reverse(s.begin(), s.end());
    if(s.empty()){
        cout<<"0";
        return 0;
    }
    cout<<s[0];
    b+=s.size()-1;
    if(s.size()>1){
        cout<<'.';
        FFOR(i, 1, s.size()) cout<<s[i];
    }
    if(b) cout<<"E"<<b;
}