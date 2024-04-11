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
int n,t,a[105],flag,zs;
string ans;
int main(){
    n=read();
    for(int i=1;i<=n;i++){
    	t=__gcd(t,a[i]=read()); if(a[i]&1)flag++;
	}
	if(flag>=2){
		puts("0");
		for(int i=1;i<=n;i++){
			while(a[i]--){
				putchar(i+'a'-1);
			}
		}
		return 0;
	}else if(flag==1){
		writeln(t); for(int i=1;i<=n;i++)a[i]/=t;
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				zs=i;
			}
		    for(int j=1;(j<<1)<=a[i];j++){
					ans+='a'+i-1;
			}
		}
		ans+='a'+zs-1;
		for(int i=n;i;i--){
			for(int j=1;(j<<1)<=a[i];j++){
				ans+='a'+i-1;
			}
		}
		while(t--)cout<<ans;
	}else{
		writeln(t);
		for(int i=1;i<=n;i++)a[i]/=(t>>1);
		for(int i=1;i<=n;i++){
		    for(int j=1;(j<<1)<=a[i];j++){
				ans+='a'+i-1;
			}
		}
		for(int i=n;i;i--){
			for(int j=1;(j<<1)<=a[i];j++){
				ans+='a'+i-1;
			}
		}
		t/=2;
		while(t--)cout<<ans;
	}
}