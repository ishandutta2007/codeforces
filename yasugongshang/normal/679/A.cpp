#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
char ch[10];
const int p[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int sum,pos;
void GG(int x){
	if(x)puts("prime"); else puts("composite");
	exit(0);
}
int main(){
	for(int i=0;i<4;i++){
		cout<<p[i]<<endl;
		fflush(stdout);
		scanf("%s",&ch);
		if(ch[0]=='y'){sum++; pos=i;}
	}
	if(sum==0){
		GG(1);
	}else if(sum>1)GG(0);
	for(int i=0;i<15&&p[i]*p[pos]<=100;i++){
		cout<<p[i]*p[pos]<<endl;
		fflush(stdout);
		scanf("%s",&ch);
		if(ch[0]=='y'){GG(0);}
	}
	GG(1);
}