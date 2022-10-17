#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
int a[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
int ans[] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
inline int check(int x) {
	For(i, 1, 25) {
		if(x < a[i]-1) {
			return a[i]-1;
		} else if(x == a[i]-1) {
			return ans[i];
		}
	}
}
int main()
{
	int _ = read();
	while(_--) {
		int n = read();
		int pos = check(n);
		printf("%d\n", pos);;
	}
	return 0;
}