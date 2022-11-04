#include<cstring>
#include<cmath>   
#include<cstdio>  
#include<iostream>  
#include<cstdlib>   
#include<algorithm>
#define ll long long
using namespace std;
char s[70];
ll n,ppp,qqq,head,last;
inline ll get(ll head,ll end){
	ll ppp=0;
	while (head<=end){
		ppp=ppp*10+s[head]-48;
		head++;
	}
	return ppp;
}
inline ll uuu(ll n){
	ll s=0;
	while (n){
		n/=10;
		s++;
	}
	return s;
} 
int main(){
	scanf("%I64d%s",&n,&s);
	ppp=1;
	qqq=0;
	last=strlen(s)-1;
	while (last>=0){
		head=last-uuu(n)+1;
		if (head<0) head=0;
		while ((get(head,last)>=n||s[head]=='0')&&head!=last) head++;
		qqq+=get(head,last)*ppp;
		ppp*=n;
		last=head-1;
	}
	printf("%I64d",qqq);
}