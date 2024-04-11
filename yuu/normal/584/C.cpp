#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "C"
string s1, s2;
int n, t, diff;
string ans;
vector <int> pdiff;
vector <int> psame;
char word(char a, char b){
    if(a>b) swap(a, b);
    if(b=='a') return 'b';
    if(a=='a'){
        if(b=='b') return 'c';
        return 'b';
    }
    return 'a';
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>n>>t;
    cin>>s1>>s2;
    n--;
    FOR(i, 0, n){
        if(s1[i]!=s2[i]){
            pdiff.pb(i);
            diff++;
        }
        else psame.pb(i);
    }
    if((diff+1)/2>t){
        cout<<-1;
        return 0;
    }
    string ans=s1;
    if(pdiff.size()%2){
        t--;
        ans[pdiff.back()]=word(s1[pdiff.back()], s2[pdiff.back()]);
        pdiff.pop_back();
    }
    n++;
    int x=n-t;
    while(pdiff.size()<x+t) x--;
    while(x>0){
        t--;
        x--;
        pdiff.pop_back();
        ans[pdiff.back()]=s2[pdiff.back()];
        pdiff.pop_back();
    }
    while(!pdiff.empty()){
        t--;
        ans[pdiff.back()]=word(s1[pdiff.back()], s2[pdiff.back()]);
        pdiff.pop_back();
    }
    while(t>0){
        ans[psame.back()]=((ans[psame.back()]=='a')?'b':'a');
        psame.pop_back();
        t--;
    }
    cout<<ans;
}