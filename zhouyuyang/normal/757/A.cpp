#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define N 1000005
using namespace std;
int a,b,c,d,e,f,g,h,l;
char ch[1000005];
int main(){
	scanf("%s",&ch);
	l=strlen(ch);
	for (int i=0;i<l;i++){
		if (ch[i]=='B') a++;
		if (ch[i]=='u') b++;
		if (ch[i]=='l') c++;
		if (ch[i]=='b') d++;
		if (ch[i]=='a') e++;
		if (ch[i]=='s') f++;
		if (ch[i]=='r') h++;
	}
	a=min(min(a,b/2),min(c,d));
	e=min(min(e/2,f),h);
	printf("%d",min(a,e));
}