#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define ll long long
using namespace std;
inline int read()
{
    int num=0;
    char c=' ';
    int flag=1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define N 200005
int a[N], b[N], t[N]; 

int main()
{
	int n = read();
	For(i, 1, n-1) {
		a[i] = read();
	}
	For(i, 1, n-1) {
		b[i] = read();
	} 
	For(i, 1, n) {
		t[i] = 5;
	}
	int cnt = 0;
	For(_, 0, 3) {
		t[1] = _;
		For(i, 2, n) {
			bool flag = 0;
			For(j, 0, 3) {
				if((j | t[i-1]) == a[i-1] && (j & t[i-1]) == b[i-1]) {
					t[i] = j;
					flag = 1;
					break;
				}
			}
			if(!flag) {
				break;
			}
		}
		For(i, 1, n) {
			if(t[i] == 5) {
				goto M2;
			}
		}
		printf("YES\n");
		For(i, 1, n) {
			printf("%d ", t[i]);
		}
		return 0;
		M2:;
	}
	For(i, 1, n) {
		if(t[i] == 5) {
			printf("NO\n");
			return 0;
		}
	}
//	printf("YES\n");
//	For(i, 1, n) {
//		printf("%d ", t[i]);
//	}
	return 0;
}