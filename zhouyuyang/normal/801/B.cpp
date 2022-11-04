#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105],t[105],ans[105];
int n;
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		if (t[i]>s[i]){
			printf("-1");
			return 0;
		}
		else ans[i]=t[i];
	printf("%s",ans+1);
}