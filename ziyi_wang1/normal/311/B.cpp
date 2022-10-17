#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
I read(ll &res){
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
typedef double db;
ll n,m,p,s[101000],dis[101000],pos,T,t[101000],q[101000][110],f[101000][110],l[110],r[110];
inline db slope(int x,int y,int w){
	return (db)((db)(f[y][w]*1.0-f[x][w]*1.0+s[y]*1.0-s[x]*1.0)/(db)((y-x)*1.0));
}
int main(){
	read(n);read(m);read(p);
	t[1]=0;
	F(i,2,n){
		read(dis[i]);
		dis[i]+=dis[i-1];
	}
	F(i,1,m){
		read(pos);read(T);
		t[i]=T-dis[pos];
	}
	sort(t+1,t+1+m);
	s[0]=0;
	F(i,1,m){
		s[i]=t[i]+s[i-1];
	}
	f[0][0]=0;
	F(i,1,p-1){
		l[i]=1;r[i]=1;q[1][i]=0;
	}
	F(i,1,m){		
		/*F(j,1,min(i,p)){
			cout<<q[l[j-1]][j-1]<<" ";
		}*/
		f[i][1]=i*t[i]-s[i];
		while(l[1]<r[1]&&slope(q[l[1]][1],q[l[1]+1][1],1)<t[i]*1.0)l[1]++;
		while(l[1]<r[1]&&slope(q[r[1]-1][1],q[r[1]][1],1)>slope(q[r[1]][1],i,1))r[1]--;
		q[++r[1]][1]=i;
		F(j,2,min(i,p)){
			f[i][j]=f[q[l[j-1]][j-1]][j-1]+(i-q[l[j-1]][j-1])*t[i]-s[i]+s[q[l[j-1]][j-1]];
			if(j==p)continue;
			while(l[j]<r[j]&&slope(q[l[j]][j],q[l[j]+1][j],j)<t[i]*1.0)l[j]++;
			while(l[j]<r[j]&&slope(q[r[j]-1][j],q[r[j]][j],j)>slope(q[r[j]][j],i,j))r[j]--;
			q[++r[j]][j]=i;
		}
		/*F(j,1,min(i,p)){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;*/
	}
	printf("%I64d",f[m][min(m,p)]);
    return 0;
}