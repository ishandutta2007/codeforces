#include <bits/stdc++.h>
using namespace std;
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;
const int N = 500005;
int n, c;
long long a[N], b[N];
int main() {
    qio >> n >> c;
    for (int i = 1; i <= n; ++i) {
    	qio >> b[i];
	}
	for (int i = 1; i <= n; ++i) {
		qio >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
        a[i] += 1ll * c * (n - i);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] -= b[i];
    }
    __int128 sum = accumulate(b + 1, b + n + 1, 0ll);
    __int128 ans = sum;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        ans = min(ans, sum - __int128(c) * i * (i - 1) / 2);
    }
    qio << ans << '\n';
    return 0;
}