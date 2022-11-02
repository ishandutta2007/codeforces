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
int tt[300],zs,tong[300],an[3005];
int main(){
    cin>>ch; tong['a']=tong['e']=tong['o']=tong['u']=tong['i']=1;
    int len=ch.length();
    for(int i=0;i<len;i++){
    	if(tong[ch[i]]){zs=0; memset(tt,0,sizeof(tt)); continue;}
		zs++; tt[ch[i]]++; 
    	if(zs>=3){int kind=0;
    		for(int j='a';j<='z';j++){
    			if(tt[j])kind++;
			}
			if(kind>=2){an[i]=1; memset(tt,0,sizeof(tt)); tt[ch[i]]=1; zs=1;}
		}
	}
	string zs; zs.clear();
	for(int i=0;i<len;i++){
		if(an[i]){cout<<zs; putchar(' '); zs.clear();}
		zs+=ch[i];
	}cout<<zs;
}