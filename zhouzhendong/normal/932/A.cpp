#include <cstring>
#include <cstdio>
#include <cmath>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=10005;
int n,m;
char ch[N],ans[N],now[N];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for (int i=1;i<=n;i++)
		printf("%c",ch[i]);
	for (int i=n;i>=1;i--)
		printf("%c",ch[i]);
	return 0;
}