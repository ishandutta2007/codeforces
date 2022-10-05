#include<bits/stdc++.h>
#define out(x) printf("%d",x?7:4)
using namespace std;

int now,las;
bool ok(int a,int b,int ab,int ba){
	if (a<0||b<0||ab<0||ba<0) return 0;
	if (b<ab) return 0;
	if (a<ba) return 0;
	if (now==0){
		if (ab!=ba+1&&ab!=ba) return 0;
		if (b&&!ab) return 0;
	}else{
		if (ba!=ab+1&&ba!=ab) return 0;
		if (a&&!ba) return 0;
	}
	return 1;
}

int a,b,ab,ba;

void doit(){
	out(now);
	for (;a+b;out(now)){
	//	printf(" %d:: %d %d %d %d\n",now,a,b,ab,ba);
		las=now;
		now=0;
		if (ok(a-1,b,ab,ba-las)) {
			a-=1; ba-=las;
			continue;
		}
		now=1;
		if (ok(a,b-1,ab-!las,ba)) {
			b-=1; ab-=!las;
			continue;
		}
	}
	exit(0);
}

int main(){
	cin>>a>>b>>ab>>ba;
	now=0; a--; if (ok(a,b,ab,ba)) doit(); a++;
	now=1; b--; if (ok(a,b,ab,ba)) doit(); b++;
	printf("-1");
}