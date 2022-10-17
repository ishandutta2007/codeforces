#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5050;
int n,m,to[M],nxt[M],head[M],w[M],cnt=1,c[M];
void add(int x,int y,int z,int fl){
    to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; c[cnt]=z; w[cnt]=fl;
}
void jb(int x,int y,int z){
    add(x,y,z,1); add(y,x,-z,0); 
}
int q[M*10];
LL dis[M];
int pre[M],pe[M];
bool spfa(){

    int l=1,r=1; q[1]=1;
    ms(dis,1); LL inf=dis[0];
    dis[1]=0; 
    while (l<=r){
        int x=q[l++];
        for (int i=head[x];i;i=nxt[i]){
            int y=to[i];
            if (w[i] && dis[y]>dis[x]+c[i]){
                dis[y]=dis[x]+c[i];
                q[++r]=y;
                pre[y]=x;
                pe[y]=i;
            }
        }
    }
    return dis[n]!=inf;
}
double ts[M];
int main(){
    n=read(); m=read();
    F(i,1,m){
        int x=read(),y=read(),z=read();
        jb(x,y,z);
    }
    int num=0;
    while (spfa()){
        num++; ts[num]=ts[num-1]+dis[n];
        for (int x=n;;x=pre[x]){
            w[pe[x]]=0;
            w[pe[x]^1]=1;
            if (x==1) break;
        }
    }
    int Q=read();
    F(T,1,Q){
        int x=read();
        double ret=1e9;
        F(i,1,num){
            ret=min(ret,(ts[i]+x)/i);
        }
        cout<<fixed<<setprecision(10)<<ret<<"\n";
    }
	return 0;
}
/*

*/