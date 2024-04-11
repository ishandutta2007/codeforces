#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define N 1000005
double a[N];
double calc(double a, double b) {
	return (2*a+2*b) * (2*a+2*b) / a / b;
}
int main()
{
	int _ = read(), lstn = 0;
	while(_--) {
		For(i, 1, lstn) a[i] = 0;
		int n = read();
		lstn = n;
		For(i, 1, n) {
			a[i] = read();
		}
		sort(a + 1, a + 1 + n) ;
		int ak1, ak2;
		double ans = INF/2;
		For(i, 1, n) {
			if(a[i] == a[i+1]) {
				For(j, i+2, n) {
					if(a[j] == a[j+1]) {
						if(ans > calc(a[i], a[j])) {
//							cout << i <<' ' <<j << endl;
							ans = calc(a[i], a[j]);
							ak1 = i, ak2 = j;
						}
						break;
					}
				}
			}
		}
		printf("%.0lf %.0lf %.0lf %.0lf\n", a[ak1], a[ak1], a[ak2], a[ak2]);
	}


    return 0;
}