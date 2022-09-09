#include<bits/stdc++.h>
using namespace std;
int n,i,x,a[10],j;
pair<char,int> b[10][4];
char o;
inline void read(int&x){
	static char c;
	for(c=getchar();!isdigit(c);c=getchar());
	for(x=0;isdigit(c);c=getchar())x=x*10+c-48;
}
int main(){
	read(n);
	for(i=1;i<=n;++i){
		for(o=getchar();o!='|' && o!='&' && o!='^';o=getchar());read(x);
		if(o=='|'){
			for(j=0;j<10;++j)
				if(x>>j&1)a[j]=1,b[j][1]=make_pair(o,1);
		}else if(o=='&'){
			for(j=0;j<10;++j)
				if(!(x>>j&1))a[j]=1,b[j][1]=make_pair(o,0);
		}else{
			for(j=0;j<10;++j)
				if(x>>j&1){
					if(a[j] && b[j][a[j]].first==o)--a[j];
						else b[j][++a[j]]=make_pair(o,1);
				}
		}
	}
	puts("3");
	for(i=x=0;i<10;++i)if(a[i] && b[i][1].first=='&');else x|=1<<i;printf("& %d\n",x);
	for(i=x=0;i<10;++i)if(a[i] && b[i][1].first=='|')x|=1<<i;printf("| %d\n",x);
	for(i=x=0;i<10;++i)if(a[i] && b[i][a[i]].first=='^')x|=1<<i;printf("^ %d\n",x);
	return 0;
}