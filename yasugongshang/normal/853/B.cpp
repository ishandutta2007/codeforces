#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
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
const long long N=1000005,oo=1000000000005;
long long n,m,k,mmin[N],ans,dist[N],sum;
struct data{
	long long s,t,val;
};
vector <data> v[N],vv[N];
int main(){
    n=read(); m=read(); k=read();
    for(long long i=1;i<=m;i++){
    	long long ti=read();
		v[ti].push_back((data){read(),read(),read()});
	}
	for(long long i=1;i<=n;i++)mmin[i]=oo;
	for(long long i=N-1;i>k;i--){
		for(long long j=0;j<v[i].size();j++){
			data zs=v[i][j];
			if(zs.t){
				if(zs.val<mmin[zs.t]){
					vv[i].push_back((data){0,zs.t,mmin[zs.t]});
					mmin[zs.t]=zs.val;
				}
			}
		}
	}
	for(long long i=1;i<=n;i++)sum+=(dist[i]=oo)+mmin[i]; ans=sum;
	for(long long i=1;i<N-k-1;i++){
		for(long long j=0;j<v[i].size();j++){
			data zs=v[i][j];
			if(zs.s){
				if(zs.val<dist[zs.s]){
					sum-=dist[zs.s]-zs.val;
					dist[zs.s]=zs.val;
				}
			}
		}
		for(long long j=0;j<vv[i+k].size();j++){
			data zs=vv[i+k][j];sum+=zs.val-mmin[zs.t];
			mmin[zs.t]=zs.val; 
		}
		
		ans=min(ans,sum);
	}
	if(ans>=oo)puts("-1"); else
	writeln(ans);
}