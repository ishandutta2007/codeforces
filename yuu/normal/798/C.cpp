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
int n;
int a[100001];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	read(n);
	FOR(i, 1, n)
		read(a[i]);
	int gcd=a[1];
	FOR(i, 2, n)
		gcd=__gcd(gcd, a[i]);
	if(gcd>1){
		puts("YES");
		puts("0");
		return 0;
	}
	FOR(i, 1, n)
		a[i]%=2;
	int res=0;
	FOR(i, 1, n-1){
		if(a[i]==1){
			if(a[i+1]==1)
				res++;
			else res+=2;
			a[i+1]=0;
		}
	}
	if(a[n]==1)
		res+=2;
	puts("YES");
	writeln(res);
}