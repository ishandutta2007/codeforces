#include<cstring>
#include<cmath>   
#include<cstdio>  
#include<iostream>  
#include<cstdlib>   
#include<algorithm>
#define ll long long
using namespace std;
char s[105],a[4];
int len,r,b,y,g;
int main(){
	scanf("%s",&s);
	len=strlen(s);
	for (int i=0;i<len;i++) if (s[i]!='!') a[i%4]=s[i];
	for (int i=0;i<len;i++)
		if (s[i]=='!'){
			if (a[i%4]=='R') r++;
			if (a[i%4]=='B') b++;
			if (a[i%4]=='Y') y++;
			if (a[i%4]=='G') g++;
		}
	printf("%d %d %d %d",r,b,y,g);
}