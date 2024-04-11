#include<stdio.h>
#include<vector>
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
std::vector<std::vector<int> >a;
int n,m,ans=2;
int main(){
    scanf("%d%d",&n,&m);
    a.resize(n);
    for(int i=0;i<n;i++)a[i].resize(m,0);a[0][0]=1;
    for(int i=0;i<n;i++){
        while(getchar()!='\n');
        for(int j=0;j<m;j++){
            if(getchar()=='.'){
                if(i)a[i][j]|=a[i-1][j];
                if(j)a[i][j]|=a[i][j-1];
            }
        }
    }for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i!=n-1||j!=m-1){
                if(i==n-1)a[i][j]&=a[i][j+1];
                else if(j==m-1)a[i][j]&=a[i+1][j];
                else a[i][j]&=(a[i+1][j]|a[i][j+1]);
            }
        }
    }
    for(int i=1;i<n+m-2;i++){int cnt=0;
        for(int j=Max(0,i-m+1);j<=Min(n-1,i);j++)cnt+=a[j][i-j];
        if(cnt==0)return printf("0")&0;
        else if(cnt==1)ans=1;
    }printf("%d",ans);
}