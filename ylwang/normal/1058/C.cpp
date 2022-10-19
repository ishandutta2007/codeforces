#include<bits/stdc++.h>
#define ll long long
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int gcd(int x,int y){while(x^=y^=x^=y%=x);return y;}
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define N 105
int a[N];
int sum[N];
queue < int > q;
int main()
{
	int n = read();
	string s;
	cin >> s;
	For(i, 0, n-1) a[i+1] = s[i] - '0';
	For(i, 1, n) sum[i] = sum[i-1] + a[i];
	q.push(0);
	For(i, 1, sum[n]-1) {
		if(sum[n] % i == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		int sum = 0;
		bool flag = 0;
		For(i, 1, n) {
			if(sum + a[i] > f) {
				flag = 1;
				break;	
			}
			sum += a[i];
			if(sum == f) {
				sum = 0;
			}
		}
		if(!flag) {
			cout << "YES" << endl;
			return 0;
		}
		
	}
	cout << "NO" <<endl;
    return 0;
}