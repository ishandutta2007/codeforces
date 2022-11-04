#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
char ch[20];
int n,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",ch);
		if (ch[0]=='C') ans+=6;
		if (ch[0]=='T') ans+=4;
		if (ch[0]=='O') ans+=8;
		if (ch[0]=='D') ans+=12;
		if (ch[0]=='I') ans+=20;
	}
	printf("%d",ans);
}