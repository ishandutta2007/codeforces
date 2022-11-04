#include<bits/stdc++.h>
#define int long long
inline int read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int k=1,kk=0;if (c=='-')c=getchar(),k=-1;
	while (c>='0'&&c<='9')kk=kk*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(int x){if (x<0)putchar('-'),x=-x;if (x)write(x/10),putchar(x%10+'0');}
void writeln(int x){write(x);if (x==0)putchar('0');puts("");}
int a[1000000][4],last[1000000],f1[1000000],f2[1000000],kk,n,x,y,z,k; 
void dfs1(int x,int fa){
	for (int i=last[x];i;i=a[i][0])if (a[i][1]!=fa){
		dfs1(a[i][1],x);f2[a[i][1]]=max(f1[a[i][1]]-a[i][3],0ll);
		f1[x]+=f1[a[i][1]]-f2[a[i][1]]+a[i][2];
	}
}int dfs2(int x,int fa,int d){
	d+=f2[x];int ddd=d;
	for (int i=last[x];i;i=a[i][0])if (a[i][1]!=fa){
		int dd=dfs2(a[i][1],x,d);if (dd>d){puts("-1");exit(0);}
		d=dd;int kk=min(d,min(a[i][2]-1,a[i][3]-f1[a[i][1]]));
		d-=kk;a[i][2]-=kk;a[i][3]-=kk;
	}f1[x]-=ddd-d;return d;
}void doit(int x,int y,int z,int k){a[++kk][0]=last[x];a[kk][1]=y;a[kk][2]=z;a[kk][3]=k;last[x]=kk;}
signed main(){
	n=read();for (int i=1;i<n;i++)x=read(),y=read(),z=read(),k=read(),doit(x,y,z,k),doit(y,x,z,k);
	dfs1(1,0);dfs2(1,0,0);cout<<n<<endl;
	for (int i=1;i<n;i++)
		cout<<a[i*2][1]<<' '<<a[i*2-1][1]<<' '<<min(a[i*2-1][2],a[i*2][2])<<' '<<min(a[i*2-1][3],a[i*2][3])<<endl;
}