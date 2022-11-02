#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,l;
char ch[20]={};
inline int kind()
{	
	l=strlen(ch);
	int C_pos(0);
	if(ch[0]!='R')
		return 1;
	while(C_pos<l && ch[C_pos]!='C')
		++C_pos;
	if(C_pos==l || C_pos==1)
		return 1;
	for(int i=1;i<C_pos;++i)
		if(ch[i]>='A' && ch[i]<='Z')
			return 1;
	return 0;
}
inline void turn_to_0()
{	
	int i(0),line=0,row=0;
	for(i=0;i<l && ch[i]>='A' && ch[i]<='Z';++i)
	{	
		line*=26;
		line+=ch[i]-'A'+1;
	}
	for(;i<l;++i)
	{	
		row*=10;
		row+=ch[i]-'0';
	}
	printf("R%dC%d\n",row,line);
}
inline void turn_to_1()
{	
	static const int p[6]={1,26,676,17576,456976,0x7fffffff};
	int i(0),line(0),row(0),top(0),t=0;
	char s[20]={};
	for(i=1;ch[i]!='C';++i)
	{	
		row*=10;
		row+=ch[i]-'0';
	}
	for(++i;i<l;++i)
	{	
		line*=10;
		line+=ch[i]-'0';
	}
	//cout<<line<<' '<<row<<endl;
	while(p[t]<=line)
	{	
		line-=p[t];
		++t;
	}
	while(top<t)
	{	
		s[++top]=line%26+65;
		line/=26;
	}
	for(i=top;i>=1;--i)
		printf("%c",s[i]);
	printf("%d\n",row);
}
int main()
{	
	scanf("%d\n",&n);
	while(n--)
	{	
		gets(ch);
		//cout<<strlen(ch)<<endl;
		if(kind()==1)
			turn_to_0();
		else
			turn_to_1();
	}
	return 0;
}