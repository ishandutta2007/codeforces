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
#include<map>
int ycl[10],n,sss[70005][10][10];
map<int,int>M[10];
int main(){
    n=read();
    ycl[0]=1;
    for(int i=1;i<=9;i++)ycl[i]=ycl[i-1]*10;
    for(int i=1;i<=n;i++){
    	int s=read();
    	for(int j=1;j<=9;j++){
    		for(int k=j;k<=9;k++){
    			M[k-j][sss[i][j][k]=s%ycl[9-j+1]/ycl[9-k]]++;
			}
		}
	}int an; //writeln(sss[2][1][9]);
	for(int i=1;i<=n;i++){
		int l=1,r=9;an=0;
		while(l<r){
			int mid=l+r>>1,flag=0;
			for(int j=1;j+mid<=10;j++){
				M[mid-1][sss[i][j][j+mid-1]]--;
			}//cout<<i<<" "<<mid<<" "<<M[mid-1][sss[i][1][9]]<<endl;
			for(int j=1;j+mid<=10;j++){
				if(M[mid-1][sss[i][j][j+mid-1]]==0){an=j; flag=1; break;}
			}
			for(int j=1;j+mid<=10;j++){
				M[mid-1][sss[i][j][j+mid-1]]++;
			}
			if(flag)r=mid; else l=mid+1;
		}int t;
		if(an==0)t=sss[i][1][9]; else
		t=sss[i][an][an+l-1];
		for(int i=2;i<=l;i++)if(t<ycl[i-1])putchar('0');
		writeln(t);
	}
}