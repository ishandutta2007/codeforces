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
long long to[30],tong[30],k;
char a[N],b[N];
inline bool check(long long x){long long zs=0;
	for(long long i=0;i<26;i++)zs+=max((long long)0,to[i]*x-tong[i]);
	return k>=zs;
}
int main(){
	scanf("%s%s",&a,&b);
	long long n=strlen(a),m=strlen(b);
	for(long long i=0;i<n;i++)if(a[i]!='?')tong[a[i]-'a']++; else k++;
	for(long long i=0;i<m;i++)to[b[i]-'a']++;
	long long l=0,r=n/m;
	while(l<r){
		long long mid=(l+r)>>1; mid++;
		if(check(mid))l=mid; else r=mid-1;
	}
	long long zs=0;
	for(long long i=0;i<26;i++){
		for(long long j=1;j<=max((long long)0,to[i]*l-tong[i]);j++){
			//cout<<i<<endl;
			while(a[zs]!='?')zs++;
			a[zs]=i+'a';
		}
	}
	for(long long i=0;i<n;i++)if(a[i]=='?')a[i]='a';
	cout<<a<<endl;
}