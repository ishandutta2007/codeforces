#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
#pragma GCC target("avx")
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
template<typename T>inline void write(T x){
    LL y=0;
    T l=0;
    if(x<0){x=-x;putchar('-');}
    if(!x){putchar(48);return;}
    while(x){y=y*10+x%10;x/=10;l++;}
    while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
    write(x);
    puts("");
}
const int mod=1e9+7;
int dp[70][11];
LL work(LL x){
	if (x==1) return 1;
	if (x==2) return 2;
	if (x==3) return 2;
	if (x%2==1) return work(x-1);
	if (x%4==0){
		return (x/4+1+work(x-2))%mod;
	}
	return (x/4+1)%mod*((x/4+2)%mod)%mod;
}
int main(){
	int T=read();
	int num=1,lst=0;
	while (T--){
		cout<<work(read())<<"\n";
////		LL x=read();
//		LL x=num;
//		F(i,0,7) dp[0][i]=0;
//		F(i,0,7) if ((i&1)==(x&1)) dp[0][i/2]++;
//		F(i,1,60){//???
//			int o=(x>>i&1);
//			F(j,0,7) dp[i][j]=0;
//			F(j,0,7){
//				if (!dp[i-1][j]) continue;
////				cout<<j<<" "<<o<<" "<<<<"\n";
//				
//				for (int k=((j^o)&1),now=(j+k)/2;k<8;k+=2,now++){
////					if (((j+k)&1)==o){
//						dp[i][now]=(dp[i][now]+dp[i-1][j])%mod;
////					}
//				}
//			}
////			F(j,0,4) cout<<dp[i][j]<<" ";
////			cout<<"\n";
//		}
//		cout<<dp[60][0]-lst<<" "<<num<<"    fuck  ";
//		writeln(lst=dp[60][0]);
//		num++;
////		cout<<dp[60][0]<<"\n";
	}
	return 0;
}