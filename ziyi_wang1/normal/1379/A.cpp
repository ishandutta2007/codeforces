#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
char c[110],d[110],s[8]={'0','a','b','a','c','a','b','a'};
int n,m,T,cnt,sn;
IN ck(int x){
	F(i,1,n)d[i]=c[i];
	F(i,1,7)if(d[x+i]=='?')d[x+i]=s[i];
	F(i,1,n)if(d[i]=='?')d[i]='z';
	re num=0,fg;
	F(i,0,n-7){
		fg=1;
		F(j,1,7)if(d[i+j]!=s[j]){
			fg=0;break;
		}
		num+=fg;
	}
	return num==1;
}
int main(){
	read(T);
	while(T--){
		read(n);cin>>c+1;cnt=sn=0;
		F(i,0,n-7){
			sn=1;
			F(j,1,7){
				if(c[i+j]!=s[j]){
					sn=0;break;
				}
			}
			cnt+=sn;
		}
		if(cnt>1){
			cout<<"No"<<endl;continue;
		}
		if(cnt==1){
			F(i,1,n)if(c[i]=='?')c[i]='z';
			cout<<"Yes"<<endl;
			F(i,1,n)cout<<c[i];cout<<endl;
			continue;
		}
		sn=0;
		F(i,0,n-7){
			cnt=0;
			F(j,1,7)if(c[i+j]!=s[j]){
				if(c[i+j]!='?'){
					cnt=10000;break;
				}
			}
			if(cnt||!ck(i))continue;
			sn=1;
			F(j,1,7)if(c[i+j]=='?')c[i+j]=s[j];
			break;
		}
		if(sn){
			F(i,1,n)if(c[i]=='?')c[i]='z';
			cout<<"Yes"<<endl;
			F(i,1,n)cout<<c[i];cout<<endl;
			continue;
		}
		cout<<"No"<<endl;
	}
	return 0;
}