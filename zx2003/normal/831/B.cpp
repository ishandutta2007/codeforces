#include<cstdio>
#include<cctype>
#include<cstring>
const int N=1005;
char a[N],b[N],c[N],y;
int x[1000],n,i;
int main(){
	scanf("%s%s%s",a+1,b+1,c+1);
	n=strlen(c+1);
	for(i=1;i<=26;++i)x[a[i]-'a']=i;
	for(i=1;i<=n;++i){
		if(isdigit(c[i])){
			putchar(c[i]);
		}
		if(isupper(c[i])){
			putchar(b[x[c[i]-'A']]-32);
		}
		if(islower(c[i])){
			putchar(b[x[c[i]-'a']]);
		}
	}
	putchar('\n');
	return 0;
}