#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=1005;
int n,f[N];
int main(){
	scanf("%d",&n);
	memset(f,0,sizeof f);
	f[1]=1,f[2]=1;
	f[3]=1;
	int x=2,y=3,z=x+y;
	while (z<=n)
		f[z]=1,x=y,y=z,z=x+y;
	for (int i=1;i<=n;i++)
		putchar(f[i]?'O':'o');
	return 0;
}