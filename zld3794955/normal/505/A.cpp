#include<bits/stdc++.h>
using namespace std;
const int L=110;
char ch[L]={};
int l;
void insert(int pos,char c)
{
	copy(ch+pos,ch+l+1,ch+pos+1);
	ch[pos]=c;
	++l;
}
void erase(int pos)
{
	copy(ch+pos+1,ch+l+1,ch+pos);
	ch[l--]='\0';
}
bool is_ok()
{
	char tmp[L]={};
	reverse_copy(ch+1,ch+l+1,tmp+1);
	return equal(ch+1,ch+l+1,tmp+1);
}
int main()
{
	cin>>(ch+1);
	l=strlen(ch+1);
	if(is_ok())
	{
		insert((l+1)/2,ch[l/2+1]);
		puts(ch+1);
	}
	else
	{
		for(int i=1;i<=l/2;++i)
			if(ch[i]!=ch[l+1-i])
			{
				if(ch[i]==ch[l-i])
				{
					insert(i,ch[l+1-i]);
					if(is_ok())
					{
						puts(ch+1);
						break;
					}
					else
						erase(i);
				}
				if(ch[i+1]==ch[l+1-i])
				{
					int p=l+2-i;
					insert(p,ch[i]);
					if(is_ok())
					{
						puts(ch+1);
						break;
					}
					else
						erase(p);
				}
				puts("NA");
				break;
			}
	}
	return 0;
}