#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=100005;
struct data{
	int x,y,num;
}a[N];
int n,r,an[N];
inline bool cmp(data a,data b){
	return a.x>b.x;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read(); 
	for(int i=1;i<=n;i++){a[i].y=read(); a[i].num=i;}
	sort(&a[1],&a[n+1],cmp);
	if(n&1){
		for(int i=2;i<=n;i+=2){
			if(a[i].y>a[i+1].y)an[++r]=a[i].num;else an[++r]=a[i+1].num;
		}an[++r]=a[1].num;
	}else{
		an[++r]=a[1].num; an[++r]=a[2].num;
		for(int i=3;i<=n;i+=2){
			if(a[i].y>a[i+1].y)an[++r]=a[i].num;else an[++r]=a[i+1].num;
		}
	}
	sort(&an[1],&an[r+1]);
	writeln(r);
	for(int i=1;i<=r;i++){
		write(an[i]); putchar(' ');
	}
}