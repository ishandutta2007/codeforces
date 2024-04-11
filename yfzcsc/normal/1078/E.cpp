#include<bits/stdc++.h>
using namespace std;
int inv(int d){
	int id;
	if(d=='u')id='d';
	else if(d=='d')id='u';
	else if(d=='l')id='r';
	else if(d=='r')id='l';
	return id;
}
int ifemp(int d){printf("s%ct",d);}
int if1(int d){printf("%c%cst",d,inv(d));}
int if0(int d){printf("%c%ct",d,inv(d));}
int ifnemp(int d){printf("%cs%ct",d,inv(d));}
void cp(int d){printf("%c10%ct",d,inv(d));}
void gor(int d){for(int i=0;i<70;++i)ifnemp(d);}
void gor2(int d){for(int i=0;i<9;++i)ifnemp(d);}
void st(int d){
	for(int j=0;j<60;++j)printf("%cl",d);
	for(int j=0;j<60;++j)printf("r");	
}
int main(){
//	freopen("out.txt","w",stdout);
	gor('l');
	for(int i=0;i<40;++i)printf("0l");
	printf("r");
	gor('r');
	printf("lu");
	gor('l');
	for(int i=0;i<40;++i)printf("0l");
	printf("r");
	gor('r');
	printf("ldd"),st('0');
	printf("uu");
	for(int i=0;i<35;++i){
		if(i>=1){
			printf("dddrr");
			cp('l'),cp('d'),cp('d');
			printf("uurr");
			cp('l'),cp('l'),cp('l'),cp('u');
			printf("uu");
		}
		for(int j=0;j<8;++j){
			cp('r');
			printf("ld"),cp('r');
			printf("ld"),cp('r');
			printf("uu");
			for(int k=0;k<3;++k){
				if(j>>k&1)if1('d');
				else if0('d');
			}
			int x=__builtin_popcount(j);
			printf("%dr%dl",x&1,x>=2);
			gor2('u'),printf("ld");
		}
		printf("l");
	}
	printf("dddddrr");
}