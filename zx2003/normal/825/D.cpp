#include<cstdio>
#include<cstring>
int a[26],b[26],u,i,ls,x,lt,j,v,c[26],d[26],ans,e[1000010],w;
char s[1000010],t[1000010];
inline int idx(char c){
	return c-'a';
}
int main(){
	scanf("%s%s",s+1,t+1);
	ls=strlen(s+1);
	lt=strlen(t+1);
	if(ls<lt){
		for(i=1;i<=ls;++i){
			if(s[i]=='?')s[i]='a';
			putchar(s[i]);
		}
		return 0;
	}
	for(i=1;i<=ls;++i)
		if(s[i]!='?')++a[idx(s[i])];
			else ++x,e[++w]=i;
	for(i=1;i<=lt;++i)++b[idx(t[i])];
	for(i=0;i<26;++i)if(b[i])c[i]=a[i]/b[i],d[i]=a[i]%b[i];
	ans=1<<30;
	for(i=0;i<26;++i)if(c[i]<ans)ans=c[i];
	for(i=0;i<26;++i)c[i]-=ans;
	for(j=1;x;++j){
		u=0;
		for(i=0;i<26;++i)if(b[i] && !c[i])u+=b[i]-d[i];
		if(u<=x){
			x-=u;
			++ans;
			for(i=0;i<26;++i)
				if(c[i])--c[i];
					else{
						for(j=1;j<=b[i]-d[i];++j)s[e[w--]]=i+'a';
						d[i]=0;
					}
		}else break;
	}
	while(w)s[e[w--]]='a';
	printf("%s\n",s+1);
	return 0;
}