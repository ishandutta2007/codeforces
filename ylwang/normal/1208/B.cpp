#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define reaD() read()
using namespace std;
#define int long long //
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 5005
int n, a[MAXN], b[MAXN];
map < int , int > num;
map < int , int > num2;
int sum = 0, sum2 = 0;
signed main() 
{
	n = read();
	For(i, 1, n) {
		b[i] = a[i] = read();
		num[b[i]]++; num2[b[i]]++;
	}
	int ans = n;
	for(auto i : num) sum2++;
	for(auto i : num) {
		if(i.second > 1) {
			goto qwqwq;
		}
	}
	cout << 0 << endl;
	return 0;
	qwqwq:;
//	cout << sum2 << endl; 
	For(i, 1, n) {
		num = num2;
		sum = 0;
		For(j, 1, n)
			if(num[a[j]] == 1) sum++;
		For(j, i, n) {
//			cout<< i << ' ' <<j <<' ' << sum << endl;
			num[a[j]]--;
			if(num[a[j]] == 1) sum++;
			if(sum == sum2) {
				ans = min(ans, j - i + 1);
				break;
			}
		} 
	}
	cout << ans << endl;
    return 0;
}