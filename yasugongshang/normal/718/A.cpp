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
string s;
int n,t,j;
inline int check(string s){
	for(int i=0;i<j-1;i++)if(s[i]!='9')return 0;
	for(int i=j;i<n;i++)if(s[i]<'4')return 0; else if(s[i]>'4')break;
	putchar('1');
	for(int i=0;i<j-1;i++)putchar('0'); return 1;
}
int main(){
    n=read(); t=read()-1; 
    cin>>s; 
    for(int i=0;i<n;i++){
    	if(s[i]=='.'){j=i+1; break;}
	}
    if(check(s))return 0;
	for(int i=j;i<n;i++){
		if(s[i]>='5'){
		    if(s[i-1]=='.')s[i-2]++; else s[i-1]++; int k=i-1;
		    while(s[k]>='5'){
		    	if(t--==0)break; s[k]=0; if(s[k-1]=='.')s[(--k)-1]++; else s[--k]++;
			}
			if(s[k]=='.'){k--;int l=k; while(s[l]-1=='9'){s[l]='0'; s[--l]++;}}
			for(int l=0;l<=k;l++)putchar(s[l]);
			return 0;
		}
	}
	cout<<s<<endl;
}