#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=5005;
int n,ans=0;
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		int x=0,y=0;
		for (int j=i;j<=n;j++){
			if (s[j]=='?')
				y++;
			if (s[j]=='(')
				x++;
			if (s[j]==')')
				x--;
			while (y>x&&y>0)
				y--,x++;
			if (x<0)
				break;
			if (((j-i)&1)&&x==y)
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}