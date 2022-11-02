#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read()//??????yy 
{
    int a=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    a=a*10+ch-'0';
    ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        a=a*10+ch-'0';
        ch=getchar();
    }
    return a;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    write(a); puts("");
}
const int N=200005;
struct data{
	int x,y;
}b[N];
int a[N],an[N];
inline bool cmp(data a,data b){
	return a.x>b.x;
}
int main(){ 
    int n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=(data){read(),i};
    sort(&a[1],&a[n+1]);
    sort(&b[1],&b[n+1],cmp);
    for(int i=1;i<=n;i++)an[b[i].y]=a[i];
    for(int i=1;i<=n;i++){
    	write(an[i]); putchar(' ');
	}
}