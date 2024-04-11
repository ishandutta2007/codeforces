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
#define taskname "E"
const ll base=1000003;
const ll phi=base-1;
ll n, k;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll temp=power(a, b/2);
	temp=(temp*temp)%base;
	if(b%2)
		temp=(temp*a)%base;
	return temp;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
	read(n);
	read(k);
	ll cnt2=n;
	ll p2=2;
	if(n<60LL){
		ll temp=1LL;
		FOR(i, 1, n)
			temp*=2LL;
		if(k>temp){
			puts("1 1");
			return 0;
		}
	}
	k--;
	while(p2<=k){
		cnt2=(cnt2+k/p2)%phi;
		p2*=2LL;
	}
	ll top;
	if(k>=base)
		top=0;
	else{
		ll temp=power(2, n%phi);
		top=1;
		FOR(i, 0, k){
			top=(top*temp)%base;
			temp=(temp+base-1)%base;
		}
	}
	ll temp=power(2LL, cnt2);
	top=(top*power(temp, base-2))%base;
	n%=phi;
	k=(k+1)%phi;
	cnt2=((n*k-cnt2)+phi)%phi;
	ll bot=power(2, cnt2);
	top=(bot-top+base)%base;
	write(top);
	putchar(' ');
	writeln(bot);
}