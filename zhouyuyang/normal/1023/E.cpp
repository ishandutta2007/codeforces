#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int x,int y,int X,int Y){
	if (x<1||y<1||x>n||y>n) return 0;
	if (X<1||Y<1||X>n||Y>n) return 0;
	printf("? %d %d %d %d\n",x,y,X,Y);
	fflush(stdout);
	char s[10];
	scanf("%s",s+1);
	return s[1]=='Y';
}
int main(){
	scanf("%d",&n);
	string ans1="",ans2="";
	int x=1,y=1;
	for (;x+y!=n+1;)
		if (check(x+1,y,n,n))
			ans1=ans1+"D",x++;
		else ans1=ans1+"R",y++;
	x=y=n;
	for (;x+y!=n+1;)
		if (check(1,1,x,y-1))
			ans2="R"+ans2,y--;
		else ans2="D"+ans2,x--;
	cout<<"! "+ans1+ans2;
}