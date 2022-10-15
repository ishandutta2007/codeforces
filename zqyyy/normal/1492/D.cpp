#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
int a,b,k;
int main(){
    a=read(),b=read(),k=read();
    if(!a || b==1 || !k){
	if(k)puts("No"),exit(0);
	puts("YES");
	for(int i=1;i<=b;i++)putchar('1');
	for(int i=1;i<=a;i++)putchar('0');
	putchar('\n');
	for(int i=1;i<=b;i++)putchar('1');
	for(int i=b+1;i<=a+b;i++)putchar('0');
	putchar('\n');
	return 0;
    }
    if(k>a+b-2)puts("No"),exit(0);
    puts("Yes");
    for(int i=1;i<=b;i++)putchar('1');
    for(int i=b+1;i<=a+b;i++)putchar('0');
    putchar('\n');
    static int c[N];
    int K=k;k=min(k,a);
    for(int i=1;i<b;i++)c[i]=1;
    for(int i=b;i<b+k;i++)c[i]=0;
    c[b+k]=1;
    for(int i=b+k+1;i<=a+b;i++)c[i]=0;
    k=K-a;int pos=b-1;
    if(k>0){
	while(k--)swap(c[pos],c[pos+1]),pos--;
    }
    for(int i=1;i<=a+b;i++)printf("%d",c[i]);
    return 0;
}