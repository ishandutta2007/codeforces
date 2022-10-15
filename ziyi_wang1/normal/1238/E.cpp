#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
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
const int INF=1e9+7;
char c[1010000];
int n,m,ans,a[21][21],X,Y,f[1<<20],cnt,sum;
IN lbt(int x){
	return x&(-x);
}
int main(){
	read(n);read(m);
	scanf("%s",c+1);
	F(i,2,n){
		if(c[i]!=c[i-1]){
			X=c[i]-'a';
			Y=c[i-1]-'a';
			a[X][Y]++;
			a[Y][X]++;
		}
	}
	memset(f,63,sizeof(f));
	f[0]=0;
	F(i,0,(1<<m)-1){
		cnt=0;X=i;
		while(X){
			cnt++;
			X-=lbt(X);
		}
		F(j,0,m-1){
			if(!(i&(1<<j))){
				sum=0;
				F(k,0,m-1){
					if(i&(1<<k))sum+=cnt*a[j][k];
					else sum-=cnt*a[j][k];
				}
				f[i|(1<<j)]=min(f[i|(1<<j)],f[i]+sum);
			}
		}
	}
	printf("%d",f[(1<<m)-1]);
    return 0;
}