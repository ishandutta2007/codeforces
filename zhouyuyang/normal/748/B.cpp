#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char a[1005],b[1005];
int m[150],l,s;
void lala(){
	printf("-1");
	exit(0);
}
int main(){
	scanf("%s%s",&a,&b);
	l=strlen(a);
	for (int i=0;i<l;i++){
		if (m[a[i]]!=0&&m[a[i]]!=b[i]) lala();
		if (m[b[i]]!=0&&m[b[i]]!=a[i]) lala();
		m[a[i]]=b[i];
		m[b[i]]=a[i];
	}
	for (int i=97;i<123;i++)
		if (m[i]!=0&&m[i]!=i){
			s++;
			m[m[i]]=0;
		}
	printf("%d\n",s);
	for (int i=97;i<123;i++)
		if (m[i]!=0&&m[i]!=i) printf("%c %c\n",i,m[i]);
	return 0;
}