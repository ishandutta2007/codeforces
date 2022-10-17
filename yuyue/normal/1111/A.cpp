#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const int M=1111;
char s1[M],s2[M];
int n;
int T(char p){
	if (p=='a' || p=='e' || p=='i'|| p=='o' || p=='u' ) return 1;
	return 0;
}
int main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	if (n!=strlen(s2+1)){
		puts("No");
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (T(s1[i])!=T(s2[i])){
			puts("No");
		return 0;
		}
	}
	puts("Yes");
	return 0;
}