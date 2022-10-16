#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define REP(i, j, k) for(int i=j; i<k; i++)
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
#define taskname "C"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s, t, rs;
bool isins[256];
bool isint[256];
vector <pair<int, int> > ans;
void solve(int u){
    if(u>=t.size()) return;
    int l=u, r=t.size()-1;
    int res=0, tt;
    pair <int, int> temp;
    string str;
    while(l<=r){
        int m=(l+r)/2;
        str=t.substr(u, m-u+1);
        if((tt=s.find(str))!=-1){
            temp=make_pair(tt, tt+m-u);
            res=m;
            l=m+1;
        }
        else if((tt=rs.find(str))!=-1){
            temp=make_pair(s.size()-tt, s.size()-(tt+m-u));
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    ans.push_back(temp);
    solve(res+1);
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>s>>t;
    rs=s;
    s='0'+s;
    reverse(rs.begin(), rs.end());
    rs='0'+rs;
    t='0'+t;
    REP(i, 1, s.size())
        isins[s[i]]=1;
    REP(i, 1, t.size())
        if(!isins[t[i]]){
            puts("-1");
            return 0;
        }
    solve(1);
    writeln(ans.size());
    REP(i, 0, ans.size()){
        write(ans[i].first);
        putchar(' ');
        writeln(ans[i].second);
    }
}