#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
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
const int N=200005;
int n,opt,ans,top1,top2,speed[N],chao[N],sudu;
int main(){
    n=read();
    while(n--){
    	int op=read();
    	if(op==1||op==3)opt=read();
    	if(op==1){
    		while(top1&&speed[top1]<opt){top1--; ans++;} sudu=opt;
		}else if(op==2){
			while(top2&&chao[top2]){top2--; ans++;}
		}else if(op==3){
			if(opt<sudu)ans++; else
			speed[++top1]=opt;
		}else if(op==4){
			chao[++top2]=0;
		}else if(op==5){
			speed[++top1]=305;
		}else{
			chao[++top2]=1;
		}
	}
	writeln(ans);
}