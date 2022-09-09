#include<cstdio>
#include<cstring>
const int N=3005;
bool b[260];
char c[N];
int pre[N],i,j,n;
int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	j=1;
	b['a']=b['e']=b['i']=b['o']=b['u']=1;
	for(i=1;i<=n;++i){
		if(i>=j+2 && (c[i]!=c[i-1] || c[i-1]!=c[i-2] || c[i-2]!=c[i]) && !b[c[i]] && !b[c[i-1]] && !b[c[i-2]]){
			putchar(' ');
			j=i;
		}
		putchar(c[i]);
	}
	return 0;
}