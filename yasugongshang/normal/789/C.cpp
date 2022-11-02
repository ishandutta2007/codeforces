#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
inline long long	read()// 
{
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
const long long N=100005;
long long n,a[N];
long long sum1[N],sum2[N],f1[N],f2[N],ans;
int main(){
	n=read();
	for(long long i=1;i<=n;i++)a[i]=read();
	for(long long i=1;i<=n;i++)a[i]=abs(a[i]-a[i+1]); n--;
	for(long long i=1;i<=n;i++){sum1[i]=a[i]*(i%2?1:-1)+sum1[i-1]; sum2[i]=a[i]*(i%2?-1:1)+sum2[i-1];}
	for(long long i=n;i;i--){
		f1[i]=max(f1[i+1],sum1[i]); f2[i]=max(f2[i+1],sum2[i]);
	}
	//for(long long i=1;i<=n;i++)cout<<f1[i]<<" "<<f2[i]<<" "<<sum1[i]<<" "<<sum2[i]<<endl;
	for(long long i=0;i<n;i++){
		if(i%2==0){
			ans=max(ans,f1[i+1]-sum1[i]);
			
		}else{
			ans=max(f2[i+1]-sum2[i],ans);
		}
	}
	cout<<ans<<endl;
}