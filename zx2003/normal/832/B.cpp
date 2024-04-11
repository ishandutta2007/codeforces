#include<cstdio>
#include<cstring>
const int N=100005;
char c[N],s[N];
int n,i,j,l,x,m,y;
bool b[300];
int main(){
	scanf("%s",c+1);
	for(i=1;c[i];++i)b[c[i]]=1;
	scanf("%s%d",c+1,&n);
	m=strlen(c+1);
	for(j=1;c[j]!='*' && j<=m;++j);
	x=m-j;
	y=j<=m;
	while(n--){
		scanf("%s",s+1);
		l=strlen(s+1);
		if(l<m-y || (j>m && m!=l)){
			puts("NO");
			continue;
		}
		for(i=1;i<j;++i){
			if(c[i]!='?' && c[i]!=s[i])break;
			if(c[i]=='?' && !b[s[i]])break;
		}
		if(i<j){
			puts("NO");
			continue;
		}
		if(j>m){
			puts("YES");
			continue;
		}
		for(i=1;i<=x;++i){
			if(c[m-i+1]!='?' && c[m-i+1]!=s[l-i+1])break;
			if(c[m-i+1]=='?' && !b[s[l-i+1]])break;
		}
		if(i<=x){
			puts("NO");
			continue;
		}
		for(i=j;i<=l-x;++i)if(b[s[i]])break;
		if(i<=l-x){
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}