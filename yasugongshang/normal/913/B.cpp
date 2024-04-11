#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int n,x,in[20001],no[20001],fa[20001];
int main(){
	n=read();
	for(int i=2;i<=n;i++){
		x=read();
		fa[i]=x;
		no[x]=1;
	}
	for(int i=1;i<=n;i++)	if(!no[i])	in[fa[i]]++;
	for(int i=1;i<=n;i++)	if(no[i]&&in[i]<3)	{puts("No");return 0;}
	puts("Yes");
}