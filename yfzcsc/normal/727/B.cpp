#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char str[2011],res[2011],mres[2011];
double ans=0,mans=0;
char deal[2000];
int x=0,shuo[2000],m[2000],sz;
int getten(int x){
	int ans=1;
	for(int i=1;i<=x;++i)ans*=10;
	return ans;
}
int main(){
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<=len;++i){
		if((str[i]>='0'&&str[i]<='9')||str[i]=='.')deal[x++]=str[i];
		else {
			memset(shuo,0,sizeof(shuo));
			memset(m,0,sizeof(m));
			if(!x)continue;
			int sx=0,tp=0;
			for(int i=0;i<x;++i){
				for(;i<x&&deal[i]!='.';++i)
					shuo[tp]=shuo[tp]*10+deal[i]-'0',m[tp]++;
				tp++;
			}
			ans=shuo[0];
			for(int i=1;i<tp;++i){
				int z=m[i];
				if(z>=3){
					ans=ans*getten(z)+shuo[i];
				}else ans=ans+(double)shuo[i]/(double)getten(z);
			}
			mans+=ans;
			x=0;
		}
	}
//	printf("%.2lf",mans);
	if(mans==floor(mans))sprintf(res,"%.0lf",mans);
	else sprintf(res,"%.2lf",mans);
	int xlen=strlen(res);
	for(int i=xlen-1,tp=0;i>=0;--i){
		mres[sz++]=res[i];
		if(res[i]=='.')tp=0;
		else tp++;
		if(tp==3)mres[sz++]='.',tp=0;
	}
	while(mres[sz-1]=='.')sz--;
	for(int i=sz-1;i>=0;--i)printf("%c",mres[i]);
}