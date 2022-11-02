#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int n,p;
int tot[N][3];
char s[N],ss[N];
int main(){
	scanf("%d%d",&n,&p);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		ss[i]=s[i]=='.'?'0':s[i];
	bool f=0;
	for (int i=1;i<=n;i++){
		if (i-p>0&&ss[i]!=ss[i-p]){
			f=1;
			break;
		}
		if (s[i]!='.')
			continue;
		if (i-p>0&&ss[i]==ss[i-p]){
			ss[i]='1';
			f=1;
			break;
		}
		if (i+p<=n&&ss[i]==ss[i+p]){
			ss[i]='1';
			f=1;
			break;
		}
	}
	if (f){
		puts(ss+1);
	}
	else
		puts("No");
	return 0;
}