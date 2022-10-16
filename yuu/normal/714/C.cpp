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
#define taskname "C"
int t;
char c;
string s;
struct node{
	int c;
	int cnt;
	int g[2];
} T[2000000];
int sz;
void insert(const string &s){
	int inode=0;
	FOR(i, 0, 17){
		if(T[inode].g[s[i]]==0)
			T[inode].g[s[i]]=++sz;
		inode=T[inode].g[s[i]];
		T[inode].cnt++;
	}
}
void remove(const string &s){
	int inode=0;
	FOR(i, 0, 17){
		inode=T[inode].g[s[i]];
		T[inode].cnt--;
	}
}
int count(const string &s){
	int inode=0;
	FOR(i, 0, 17){
		if(T[inode].g[s[i]]==0)
			return 0;
		inode=T[inode].g[s[i]];
	}
	return T[inode].cnt;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	cin>>t;
	FOR(q, 1, t){
		cin>>c>>s;
		DFOR(i, s.size()-1, 0)
			s[i]%=2;
		while(s.size()<18)
			s=char(0)+s;
		if(c=='+')
			insert(s);
		else if(c=='-')
			remove(s);
		else
			writeln(count(s));
	}
}