#include <cstdio>
#include <cstring>
int n,p,lst,len,res,type,num1,num2;
char c,str[1010],ans[1010];
inline int read(){
	res=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
	return res;
}
inline bool dig(char c){
	return c>='0'&&c<='9';
}
inline bool ch(char c){
	return c>='A'&&c<='Z';
}
inline void work(int x){
	lst=1000;
	while(x)ans[--lst]=(x-1)%26+'A',x-=(x-1)%26+1,x/=26;
}
int main(){
	n=read();
	for(register int i=0;i<n;++i){
		scanf("%s",str);
		type=0,len=strlen(str);
		for(register int i=1;i<len;++i)if(dig(str[i])&&ch(str[i-1]))++type;
		if(type==1){
			num1=num2=0;
			for(register int i=0;i<len;++i){
				if(ch(str[i]))num1*=26,num1+=str[i]-'A'+1;
				if(dig(str[i]))num2*=10,num2+=str[i]-'0';
			}
			printf("R%dC%d\n",num2,num1);
		}
		if(type==2){
			p=num1=num2=0;
			while(str[++p]!='C')num1*=10,num1+=str[p]-'0';
			while(str[++p]!='\0')num2*=10,num2+=str[p]-'0';
			work(num2);
			printf("%s%d\n",ans+lst,num1);
		}
	}
	return 0;
}