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
char s[200005];
int i;
int main(){
    cin>>s;
    int len=strlen(s);
    for(i=0;i<len;i++){
    	if(s[i]!='a')break;
	}if(i==len){
		s[len-1]='z'; puts(s); return 0;
	}
	for(;i<len;i++){
		if(s[i]=='a')break;
		s[i]--;
	}
	cout<<s<<endl;
}