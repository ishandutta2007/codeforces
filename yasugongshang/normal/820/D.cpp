#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline long long read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const long long N=1000005;
long long n,sum,a[N],ans,ans1,f[N];
int main(){
	n=read(); 
	for(long long i=1;i<=n;i++)sum+=abs((a[i]=read())-i); ans=sum;
	for(long long i=1;i<=n;i++){
		if(a[i]<i){
			long long zs=n+a[i];
			f[n-i+1]--; f[0]++;  f[n-i+2]--; f[zs-i+1]++; f[zs-i+1]++;
			f[n-i+1]+=abs(a[i]-1)-abs(n-a[i]); f[n-i+2]+=abs(n-a[i])-abs(a[i]-1);
		}else{
			f[a[i]-i+1]++; f[0]--; f[a[i]-i+1]++; f[n-i+1]--; f[n-i+2]--;
			f[n-i+1]+=abs(a[i]-1)-abs(n-a[i]); f[n-i+2]+=abs(n-a[i])-abs(a[i]-1);
		}
	}
	for(long long i=1;i<n;i++){
		f[i]+=f[i-1];
		sum+=f[i];
		if(sum<ans){
			ans=sum; ans1=i;
		}
	}
	cout<<ans<<" "<<ans1<<endl;
}