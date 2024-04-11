#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n;
int main(){
	int x=read(),y=read(),z=read();
	int var=0;
	bool a1,a2,a3;
	a1=a2=a3=0;
	for (int i=0;i<=z;i++){
		int a=x+i;
		int b=y+z-i;
		if (a>b) {
			if (!a1) var++;
			a1=1;
		}
		if (a==b) {
			if (!a2) var++;
			a2=1;
		}
		if (a<b) {
			if (!a3) var++;
			a3=1;
		}
	}
	if (var==1){
		if (a1) puts("+");
				if (a2) puts("0");
				

		if (a3) puts("-");

	}
	else puts("?");
	return 0;
}