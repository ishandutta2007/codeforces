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
string ch;
int ans;
inline int chu(string ch){
	int sum=0;
	for(int i=0;i<ch.length()-1;i++){
		if(ch[i]=='V'&&ch[i+1]=='K')sum++;
	}
	return sum;
}
int main(){
    cin>>ch;
    ans=chu(ch);
    for(int i=0;i<ch.length();i++){
    	if(ch[i]=='K')ch[i]='V'; else ch[i]='K';
		ans=max(ans,chu(ch));
		if(ch[i]=='K')ch[i]='V'; else ch[i]='K';
	}
	writeln(ans);
}