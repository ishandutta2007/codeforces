#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s[20];
int sum;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1,j=n;i<=j;i++,j--)
		if (s[i]!=s[j]) sum++;
	if (sum==1||(sum==0&&(n%2==1))) printf("YES");
	else printf("NO");
}