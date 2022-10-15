#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
char c[202000];
int n,m,T,ans,t[25],lg[202000],f[202000],pos;
int main(){
	t[0]=1;
	lg[0]=lg[1]=0;
	F(i,2,200200){
		lg[i]=lg[i>>1]+1;
	}
	F(i,1,23){
		t[i]=t[i-1]<<1;
	}
	cin>>T;
	while(T--){
		scanf("%s",c+1);
		n=strlen(c+1);
		ans=0;m=0;
		F(i,1,n){
			f[i]=m;
			if(c[i]-'0'){
				m=i;
			}
		}
		f[n+1]=m;
		FOR(i,n,1){
			m=0;pos=f[i+1];
			while(pos&&i-pos<18){
				m+=(1<<(i-pos));
				if(m>i)break;
				if(i-pos+1<=m&&min(i,i-f[pos])>=m)ans++;
				pos=f[pos];
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}