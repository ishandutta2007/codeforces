#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
int s1[10],s2[10],s3[10],s4[10];
inline int chu(int x){
	if(x>4)x-=4; if(x<1)x+=4;
	return x;
}
int main(){
	for(int i=1;i<=4;i++){
		s1[i]=read(); s2[i]=read(); s3[i]=read(); s4[i]=read();
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(i==j) {if((s1[i]||s2[i]||s3[i])&&(s4[i])){
			puts("YES"); return 0;}}else
			if(j==chu(i+1)&&s3[i]&&s4[j]){
			puts("YES"); return 0;}else
			if(j==chu(i+2)&&s2[i]&&s4[j]){
			puts("YES"); return 0;}else{
			if(j==chu(i+3)&&s1[i]&&s4[j]){
			puts("YES"); return 0;}
			}
		}
	}
	puts("NO");
}