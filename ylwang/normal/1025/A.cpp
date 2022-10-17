#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
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
int t[1001];
int main()
{
	int n = read();
	if(n == 1) {
		printf("Yes\n");
		return 0;
	}
	string s;
	cin >> s;
	s = " " + s; 
	For(i, 1, n) {
		t[s[i]]++;
	}
	int max = 0;
	For(i, 1, 200) {
		if(t[i] > max) {
			max = t[i];
		}
	}
	if(max < 2) {
		printf("No\n");
//		return 0; 
	} else {
		printf("Yes\n");
	}
//	For(i, 1, 200) {
//		if(t[i] >= 2) {
//			For(j, 1, 200) {
//				if(t[j] <= 1) {
//					
//				}
//			}
//		}
//	}
	return 0;
}