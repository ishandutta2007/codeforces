#include<bits/stdc++.h>
using namespace std;
#define re register int
#define Fr(x,y,z) for(re x=y;x<=z;x++)
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
	res=(res<<3)+(res<<1)+(ch^48);;
	ch=getchar();
	}
	res*=g;
}
char c;
int n,m,k,ans,sum,l[2020],r[2020],v[2020],a[2020][2020],f[2020][2020],g[2020][2020];
int main(){
    read(n);read(m);
    Fr(i,1,n){
        Fr(j,1,n){
            cin>>c;
            if(c=='B')a[i][j]=1;
            else a[i][j]=0;
        }
    }
    Fr(i,1,n){
    	l[i]=n+1;
    	r[i]=0;
    	v[i]=0;
	}
	ans=0;
	Fr(i,1,n){
		Fr(j,1,n){
			if(a[i][j]){
				l[i]=min(l[i],j);
				r[i]=max(r[i],j);
			}	
		}
		if(!r[i])ans++;
		else if(r[i]-l[i]>=m)continue;
		else v[i]=1;
	}
	sum=0;
	Fr(j,1,n-m+1){	
		sum=0;
		Fr(i,1,m){
			if(v[i]&&j<=l[i]&&r[i]<=m+j-1)sum++;
		}
		f[1][j]=sum;
		Fr(i,m+1,n){
			if(v[i-m]&&j<=l[i-m]&&r[i-m]<=m+j-1)sum--;
			if(v[i]&&j<=l[i]&&r[i]<=m+j-1)sum++;
			f[i-m+1][j]=sum;
		}
	}
	Fr(i,1,n){
    	l[i]=n+1;
    	r[i]=0;
    	v[i]=0;
	}
	Fr(j,1,n){
		Fr(i,1,n){
			if(a[i][j]){
				l[j]=min(l[j],i);
				r[j]=max(r[j],i);
			}	
		}
		if(!r[j])ans++;
		else if(r[j]-l[j]>=m)continue;
		else v[j]=1;
	}
	sum=0;
	Fr(j,1,n-m+1){	
		sum=0;
		Fr(i,1,m){
			if(v[i]&&j<=l[i]&&r[i]<=m+j-1)sum++;
		}
		g[j][1]=sum;
		Fr(i,m+1,n){
			if(v[i-m]&&j<=l[i-m]&&r[i-m]<=m+j-1)sum--;
			if(v[i]&&j<=l[i]&&r[i]<=m+j-1)sum++;
			g[j][i-m+1]=sum;
		}
	}
	sum=0;
	Fr(i,1,n-m+1){
		Fr(j,1,n-m+1){
			sum=max(sum,f[i][j]+g[i][j]);
		}	
	}
	cout<<ans+sum;
	return 0;
}