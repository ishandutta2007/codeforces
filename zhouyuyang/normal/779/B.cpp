#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
char s[15];
int x,l,tot,ans;
int main(){
	scanf("%s%d",&s,&x);
	l=strlen(s);
	for (int i=l-1;i>=0;i--)
		if (s[i]==48){
			tot++;
			if (tot==x){
				printf("%d",ans);
				return 0;
			}
		}
		else ans++;
	printf("%d",l-1);
}