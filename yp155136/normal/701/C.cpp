#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int type[52];

int f(char c) {
	if (c<='Z') return c-'A';
	else return c-'a'+26;
}

const int MAX_N = 1e5+6;
char s[MAX_N];
int num;

bool check() {
	int ret=0;
	for (int x=0;52>x;x++) {
		if (type[x]!=0) ret++;
	}
//	cout<<"ret="<<ret<<" , num="<<num<<endl;
	return (ret==num);
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		getchar();
		scanf("%s",s);
		memset(type,0,sizeof(type));
		num=0;
		for (int x=0;n>x;x++) {
			if (type[f(s[x])]==0) {
				num++;
				type[f(s[x])]=1;
			}
		}
		memset(type,0,sizeof(type));
		int L=0,R=0;
		int ans=n;
		while (L<=n) {
//			cout<<L<<" ~ "<<R<<endl;
			if (check()) {
//				cout<<"in\n";
				ans=min(ans,R-L);
				type[f(s[L])]--;
				L++;
			}
			else {
				if (R==n) break;
				type[f(s[R])]++;
				R++;
			}
		}
		printf("%d\n",ans);
	}
}