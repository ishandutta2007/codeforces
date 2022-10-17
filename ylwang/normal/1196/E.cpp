#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int a[MAXN], n;
vector < int > ansx;
vector < int > ansy;

signed main()
{
	srand(time(0)); 
	int T = read();
	while(T--) {
		ansx.clear(), ansy.clear();
		int b = read(), w = read(), flag = 1;
		if(b < w) {swap(b, w); flag = 0;}
//		if(b > w) {
			int l = 5000000, r = 5000001;
			ansx.push_back(l); ansx.push_back(r);
			ansy.push_back(100); ansy.push_back(100);
			b--, w--;
			while(w) {
				l--, r++;
				w--, b--;
				ansx.push_back(l); ansx.push_back(r);
				ansy.push_back(100); ansy.push_back(100);
			}
			if(b > 0) {
				if((l-1)%2==0)
					ansx.push_back(l-1), ansy.push_back(100), l--;
				else 
					ansx.push_back(r+1), ansy.push_back(100), r++;
				b--; 
				if(b <= 0) goto print;
				for(int i = l; i <= r; i++) {
					if(i % 2 == 0) continue;
					b--; ansx.push_back(i); ansy.push_back(99);
					if(b <= 0) goto print;
				}
				for(int i = l; i <= r; i++) {
					if(i % 2 == 0) continue;
					b--; ansx.push_back(i); ansy.push_back(101);
					if(b <= 0) goto print;
				}
			}
			print:;//
			if(b) {
				printf("NO\n");
			} else {
				printf("YES\n");
				for(int i = 0; i < ansx.size(); i++) {
					printf("%d %d\n", ansx[i]-flag, ansy[i]);
					
				}
			}
//		}
	}
	
    return 0;
}