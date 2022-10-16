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
#define taskname "B"
int n;
string s[51];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	cin>>n;
	FOR(i, 1, n)
		cin>>s[i];
	FOR(i, 2, n)
		if(s[i].size()!=s[1].size()){
			puts("-1");
			return 0;
		}
	int sz=s[1].size();
	FOR(i, 1, n)
		s[i]+=s[i];
	string t;
	int ans=-1;
	FOR(i, 0, sz-1){
		t=s[1].substr(i, sz);
		int res=0;
		FOR(i, 1, n){
			if(s[i].find(t)==-1) goto line1;
			res+=s[i].find(t);
		}
		if(ans==-1)
			ans=res;
		else ans=min(ans, res);
		line1:;
	}
	writeln(ans);
}