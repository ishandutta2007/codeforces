#include<cstdio>
#define int long long
#define _ 0
using namespace std;
int t ,a ,b ,wei;
int read() {
    char cc = getchar() ; int cn = 0  ,flus = 1;
    while(cc < '0' || cc > '9') {if(cc == '-') flus = - flus ; cc = getchar() ;}
    while(cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0' ,cc=  getchar();
    return flus * cn;
}
int getnumb(int x) {
    int ans = 0;
    while(x > 0) ++ans ,x /= 10;
    return ans - 1;
}
signed main() {
    t = read();
    while(t --) a = read() ,b = read() ,printf("%lld\n" ,a * getnumb(b + 1));//+199
    return ~~(0^_^0);
}