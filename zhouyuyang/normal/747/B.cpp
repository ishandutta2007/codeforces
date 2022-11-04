#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream> 
#define N 50005
#define eps 1e-9
using namespace std;
char s[260];
int n,a,b,c,d;
void la(){printf("==="); exit(0);}
int main(){
	scanf("%d%s",&n,&s);
	if (n%4) la();
	for (int i=0;i<n;i++){
		if (s[i]=='A') a++;
		if (s[i]=='G') b++;
		if (s[i]=='C') c++;
		if (s[i]=='T') d++;       
	}
	if (a>n/4||b>n/4|c>n/4||d>n/4) la();
	for (int i=0;i<n;i++){
		if (s[i]!='?') printf("%c",s[i]);
		else if (a!=n/4) printf("A"),a++;
		else if (b!=n/4) printf("G"),b++;
		else if (c!=n/4) printf("C"),c++;
		else if (d!=n/4) printf("T"),d++;
	}
	return 0;
}