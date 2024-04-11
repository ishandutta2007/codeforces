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
int a[100001];
int n;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	read(n);
	int amin=1000000007;
	int amax=0;
	FOR(i, 1, n){
		read(a[i]);
		amin=min(amin, a[i]);
		amax=max(amax, a[i]);
	}
	int x=amax-amin, mid=(amin+amax)/2;
	FOR(i, 1, n)
		if(a[i]!=amin&&a[i]!=amax) goto line1;
	puts("YES");
	return 0;
	line1:;
	if((amin+amax)%2) goto line2;
	FOR(i, 1, n)
		if(a[i]!=mid&&a[i]!=amin&&a[i]!=amax) goto line2;
	puts("YES");
	return 0;
	line2:;
	puts("NO");
	
}