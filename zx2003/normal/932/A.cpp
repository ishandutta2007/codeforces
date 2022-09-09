#include<bits/stdc++.h>
const int N=10005;
char c[N];
int n,i;
int main(){
	scanf("%s",c);printf("%s",c);n=strlen(c);
	std::reverse(c,c+n);puts(c);return 0;
}