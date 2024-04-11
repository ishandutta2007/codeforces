 #include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define For(i,j,k)	for(ll i=j;i<=k;i++)
#define Dow(i,j,k)	for(ll i=k;i>=j;i--)
#define ll long long
using namespace std;
int n,k,a[1001],b[1001];
int main(){
scanf("%d%d",&n,&k);
For(i,1,n)	scanf("%d",&a[i]);
For(i,1,k)	scanf("%d",&b[i]);
sort(b+1,b+k+1);
int p=1;
Dow(i,1,n)
if(a[i]==0)	a[i]=b[p],p++;
For(i,2,n)
if(a[i-1]>a[i]){puts("Yes");return 0;}
puts("No");	
}