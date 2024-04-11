#include <stdio.h>
#include <locale>
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
#define taskname "D"
#include <iostream>
using namespace std;
string s[500001];
int n;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    FOR(i, 1, n)
        cin>>s[i];
    DFOR(i, n-1, 1){
        for(int j=1, temp=min(s[i].size(), s[i+1].size()); j<temp; j++){
            if(s[i][j]!=s[i+1][j]){
                if(s[i][j]>s[i+1][j])
                    s[i].erase(s[i].begin()+j, s[i].begin()+s[i].size());
                goto line1;
            }
        }
        if(s[i].size()>s[i+1].size())
            s[i].erase(s[i].begin()+s[i+1].size(), s[i].begin()+s[i].size());
        line1:;
    }
    FOR(i, 1, n)
        cout<<s[i]<<'\n';
}