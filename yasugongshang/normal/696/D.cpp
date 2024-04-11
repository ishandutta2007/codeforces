#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const long long kind=26,N=201,M=201,oo=4e18;
struct data{
    long long nexta[kind]; long long count,fail;
}f[N];
char ch[M];
long long mx,a[N],cnt=1,n,i,que[N],m,j,k,size;
inline void zero(long long x){
    memset(f[x].nexta,0,sizeof(f[x].nexta));
    f[x].count=0; f[x].fail=0;
}
inline void build(char a[],long long val){
    long long p=0,len=strlen(a),t;
    for (long long i=0;i<len;i++) {
        t=a[i]-'a'; 
        if (!f[p].nexta[t]){
            f[p].nexta[t]=cnt;
            zero(cnt); cnt++;
        }
        p=f[p].nexta[t]; 
    }
   f[p].count+=val;
}
inline void makefail(){
    long long l=0; que[1]=0; long long r=0,p; f[0].fail=-1;
        for(long long i=0;i<kind;i++)if(f[0].nexta[i]){que[++r]=f[0].nexta[i]; f[f[0].nexta[i]].fail=0;}
        while(l<r){
            long long k=que[++l];  f[k].count+=f[f[k].fail].count;
            for(long long i=0;i<kind;i++)if(f[k].nexta[i]){{
                    for(p=f[k].fail;p>=0;p=f[p].fail)
                        if(f[p].nexta[i]){
                            f[f[k].nexta[i]].fail=f[p].nexta[i]; break;
                        }
                }
                que[++r]=f[k].nexta[i];
            }else{f[k].nexta[i]=f[f[k].fail].nexta[i]; }
        }
}
struct matrix{
    long long a[201][201];
}zs,ans,ycl;
matrix cheng(matrix x,matrix y){
    matrix tmp=ycl;
    for(long long i=0;i<size;i++)
     for(long long j=0;j<size;j++){tmp.a[i][j]=0-oo;
      for(long long k=0;k<size;k++){
          tmp.a[i][j]=max(tmp.a[i][j],x.a[i][k]+y.a[k][j]);
          //if(tmp.a[i][j]>0)cout<<tmp.a[i][j]<<" "<<i<<" "<<j<<" "<<x.a[i][k]<<" "<<y.a[k][j]<<endl,exit;
      }}
    return tmp;
}
matrix quick(matrix zs,long long k){
    matrix ans=ycl;
    ans.a[0][0]=0; 
    while(k){
        if(k&1)ans=cheng(ans,zs);
        zs=cheng(zs,zs);
        k>>=1;
    }
    return ans;
}
int main(){
    cnt=1; zero(0); 
    cin>>n>>m; 
    for(long long i=1;i<=n;i++)cin>>a[i];
    for(long long i=1;i<=n;i++){
    	scanf("%s",&ch); build(ch,a[i]);
	}
	makefail();
	for(long long i=0;i<cnt;i++)for(long long j=0;j<cnt;j++)zs.a[i][j]=ycl.a[i][j]=-oo;
	for(long long i=0;i<cnt;i++){
		for(long long j=0;j<26;j++){
			//if(f[i].nexta[j])cout<<i<<" "<<j<<" "<<f[i].nexta[j]<<" "<<f[f[i].nexta[j]].count<<endl;
			zs.a[i][f[i].nexta[j]]=f[f[i].nexta[j]].count;
		}
	}
	size=cnt;
	//ans=ycl; ans.a[0][i]=0;
	//for(int i=1;i<=m;i++)ans=cheng(ans,zs);
	ans=quick(zs,m); 
	mx=-oo;
	for(long long i=0;i<cnt;i++)mx=max(mx,ans.a[0][i]);
	cout<<mx<<endl;
}