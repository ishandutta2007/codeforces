#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define F(i,j,k) for(int i=(j);i<=(k);i++)
#define DF(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
template<typename T>inline void read(T &n){
    T w=1;n=0;char ch=getchar();
    while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
    while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch^48);ch=getchar();}
    n*=w;
}
template<typename T>inline void write(T x){
    ull y=0;
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
template<typename T>inline void writes(T x){
    write(x);
    putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=a>b?a:b;}
template<typename T>inline void checkmin(T &a,T b){a=a<b?a:b;}
int s[1100],sum[1100];
int main(){
 	//freopen(".in","r",stdin);
 	//freopen(".out","w",stdout);
 	int n,a1,a2,a3;read(n);
 	cout<<"? 1 2"<<endl;
 	cout.flush();
 	read(a1);
 	cout<<"? 1 3"<<endl;
 	cout.flush();
 	read(a2);
 	cout<<"? 2 3"<<endl;
 	cout.flush();
 	read(a3);
 	s[1]=a2-a3;
 	s[2]=a1-s[1];
 	s[3]=a3-s[2];
 	sum[3]=s[1]+s[2]+s[3];
 	F(i,4,n){
 		cout<<"? 1 ";
 		cout<<i<<endl;
 		cout.flush();
 		int x;read(x);
 		s[i]=x-sum[i-1];
 		sum[i]=sum[i-1]+s[i];
 	}
 	cout<<"! ";
 	F(i,1,n)writes(s[i]);
 	cout<<endl;
 	cout.flush();
    return 0;
}