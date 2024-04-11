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
ll a[501][501];
int px, py; 
int n;
bool check(){
	ll sum=0;
	FOR(i, 1, n)
		sum+=a[1][i];
	FOR(i, 2, n){
		ll temp=0;
		FOR(j, 1, n)
			temp+=a[i][j];
		if(temp!=sum) return 0;
	}
	FOR(i, 1, n){
		ll temp=0;
		FOR(j, 1, n)
			temp+=a[j][i];
		if(temp!=sum) return 0;
	}
	ll temp=0;
	FOR(i, 1, n)
		temp+=a[i][i];
	if(temp!=sum) return 0;
	temp=0;
	FOR(i, 1, n)
		temp+=a[i][n+1-i];
	if(temp!=sum) return 0;
	return 1;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	read(n);
	FOR(i, 1, n)
		FOR(j, 1, n){
			read(a[i][j]);
			if(a[i][j]==0){
				px=i;
				py=j;
			}
		}
	if(n==1){
		puts("1");
		return 0;
	}
	int c=1+(px==1);
	ll sum=0;
	FOR(i, 1, n)
		sum+=a[c][i];
	FOR(i, 1, n)
		sum-=a[px][i];
	a[px][py]=sum;
	if(check()&&a[px][py]>0)
		writeln(a[px][py]);
	else writeln(-1);
}