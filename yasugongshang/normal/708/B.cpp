#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
long long zs,s[10],num0,num1,t,sum;
inline bool check(long long x){
	long long zs=sqrt(x*2);
	if(zs*(zs+1)/2!=x)return 1; else return 0;
}
int main(){
    for(long long i=0;i<4;i++)sum+=(s[i]=read());
    if(sum==1){
    	if(s[0])puts("00"); else if(s[1])puts("01"); else if(s[2])puts("10"); else if(s[3])puts("11"); return 0;
	}
	if(check(s[0])||check(s[3])){
    	puts("Impossible"); return 0;
	}
	if(s[0]==0&&s[3]==0){
		if(!sum){
			puts("0"); return 0;
		}else {
			puts("Impossible"); return 0;
		}
	}else if(s[0]==0||s[3]==0){
		if(s[1]==0&&s[2]==0){
			if(s[3])s[0]=s[3]; s[0]=sqrt(s[0]*2)+1;
			while(s[0]--)if(s[3])putchar('1'); else putchar('0');
			return 0;
		}
	}
	num0=sqrt(s[0]*2)+1; num1=sqrt(s[3]*2)+1; //cout<<num0<<" "<<num1<<endl;
	if(sum!=(num0+num1)*(num0+num1-1)/2){
		puts("Impossible"); return 0;
	}
	long long zs=s[1];
	for(long long i=1;i<=num1;i++){
		t=zs/(num1-i+1); 
		num0-=t;
		while(t--){
			putchar('0');
		}
		zs%=num1-i+1;
		putchar('1'); 
	}
	while(num0--){
		putchar('0');
	}
}