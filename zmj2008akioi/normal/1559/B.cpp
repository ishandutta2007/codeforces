#include <cstdio>
int t,n,pointer;
char s[110];
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d\n%s",&n,s+1);
		s[n+1]=0;
		for(register int j=1;!(j>n);++j){
			if(s[j]=='?')continue;
			pointer=j;
			while(s[pointer-1]=='?')s[--pointer]='B'+'R'-s[pointer+1];
		}
		pointer=n;
		while(s[pointer]=='?')--pointer;
		if(!pointer)s[0]='B';
		while(pointer<n)s[++pointer]='B'+'R'-s[pointer-1];
		puts(s+1);
	}
	return 0;
}