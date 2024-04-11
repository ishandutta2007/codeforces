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
int n,vis[10005];
struct data{
	int s[5];
}a[1005];
inline data make(data a,data b){
	data zs;
	for(int i=0;i<5;i++)zs.s[i]=a.s[i]-b.s[i];
	return zs;
}
inline bool chu(data a,data b){ int sum=0;
	for(int i=0;i<5;i++)sum+=a.s[i]*b.s[i];
	return sum>0;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
    	for(int j=0;j<5;j++)a[i].s[j]=read();
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		for(int k=j+1;k<=n;k++){
    			if(chu(make(a[i],a[j]),make(a[i],a[k]))){
    				vis[i]=1; break;
				}
			}
			if(vis[i])break;
		}
	}int ans=0;
	for(int i=1;i<=n;i++)if(!vis[i])ans++;
	writeln(ans);
	for(int i=1;i<=n;i++)if(!vis[i]){write(i); putchar(' ');}
}