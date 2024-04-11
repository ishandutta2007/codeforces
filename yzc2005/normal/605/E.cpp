#include <bits/stdc++.h>
using namespace std;

namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;

const int N = 1005;
int n, e[N][N];
double dp[N], rest[N];
bool vis[N];

int main() {
    qio >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            qio >> e[i][j];
        }
    }

    fill(rest + 1, rest + n + 1, 1);
    rest[n] = 0;

    for (int t = 1; t <= n; ++t) {
        int u = -1;
        double mn = 1e18;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && rest[i] != 1 && (dp[i] + 1) / (1 - rest[i]) < mn) {
                mn = (dp[i] + 1) / (1 - rest[i]);
                u = i;
            } 
        }

        vis[u] = true;
        dp[u] = (dp[u] + 1) / (1 - rest[u]);
        for (int v = 1; v <= n; ++v) {
            if (!vis[v]) {
                dp[v] += rest[v] * e[v][u] / 100.0 * dp[u];
                rest[v] *= 1 - e[v][u] / 100.0;
            }
        }
    }

    printf("%.6f\n", dp[1] - 1);
    
    return 0;
}