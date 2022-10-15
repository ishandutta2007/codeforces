#include <cstdio>
#include <cstring>
int t,len;
char m,rec,str[110];
bool tag;
int main(){
	scanf("%d",&t);
	do{
		scanf("%s",str);
		tag=false,rec='z'+1,len=strlen(str);
		for(register int i=0;i<len;++i)if(str[i]<rec)rec=str[i];
		putchar(rec),putchar(' ');
		for(register int i=0;i<len;++i){
			if(!tag&&str[i]==rec){tag=true;continue;}
			putchar(str[i]);
		}
		putchar('\n');
	}while(--t);
	return 0;
}