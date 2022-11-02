#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
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
int pos1[1000005],pos2[3000005];
int n,L;

bool check(int dis){
	int left=0,right=3*n-1;
	for(int i=0;i<n;i++){
		while(pos1[i]-pos2[left]>dis)left++;
		while(pos2[right]-pos1[i]>dis)right--;
		left++; right++;
	}
	return left<=right;
}
int main(){
	int T; T=1;
	while(T--){
		n=read(); L=read(); //L++;
		for(int i=0;i<n;i++){
			pos1[i]=read();
		}
		for(int i=0;i<n;i++){
			pos2[i]=read();
			pos2[i+n]=pos2[i]-L;
			pos2[i+n*2]=pos2[i]+L;
		}
		sort(pos1,pos1+n);
		sort(pos2,pos2+n*3);
		int l=0,r=L;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	
}