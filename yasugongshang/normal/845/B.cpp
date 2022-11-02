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
char ch[7];
int a[7],sum,mmax,j,ans;
int main(){
    scanf("%s",&ch);
    for(int i=1;i<=6;i++)a[i]=ch[i-1]-'0';
    sum=a[1]+a[2]+a[3]-a[4]-a[5]-a[6];
    while(sum!=0)if(sum>0){mmax=0;
    	for(int i=1;i<=3;i++){
    		if(a[i]>mmax){
    			mmax=a[i]; j=i;
			}
		}
		for(int i=4;i<=6;i++){
			if(9-a[i]>mmax){
				mmax=9-a[i]; j=i;
			}
		} ans++;
		if(sum>mmax){
			sum-=mmax; if(j<=3)a[j]=0; else a[j]=9;
		}else break;
	}else{mmax=0;
		for(int i=1;i<=3;i++){
    		if(9-a[i]>mmax){
    			mmax=9-a[i]; j=i;
			}
		}
		for(int i=4;i<=6;i++){
			if(a[i]>mmax){
				mmax=a[i]; j=i;
			}
		} ans++;
		if(-sum>mmax){
			sum+=mmax; if(j<=3)a[j]=9; else a[j]=0;
		}else break;
	}
	writeln(ans);
}