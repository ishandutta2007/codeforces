#include<iostream>
#include<cstdio>
using namespace std;
const int p=100005,mod=1000000007;
bool heshu[p]; int cnt[p],ans,tong[p],n,T,k,r,miu[p],que[p],m;
inline int pow(int a,int b){
	int t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
inline int read()// 
{
	int a=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	a=a*10+ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a;
}
inline void write(int a)
{
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
int main(){
	for(int i=2;i<p;i++){
	    if(!heshu[i]){que[++r]=i; miu[i]=-1;}
        for(int j=1;j<=r&&i<=(p-1)/que[j];j++){
            heshu[k=i*que[j]]=1;
            if (i%que[j]==0){miu[k]=0; break;}
            miu[k]=miu[i]*miu[que[j]];
        }
    }miu[1]=1;
    n=read();
    for(int i=1;i<=n;i++){ tong[read()]++;}
    for(int i=1;i<p;i++){
    	for(int j=i;j<p;j+=i)cnt[i]+=tong[j];
    	cnt[i]=pow(2,cnt[i])-1; if(cnt[i]<0)cnt[i]=mod-1;
    	ans=(ans+(long long)cnt[i]*miu[i])%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}