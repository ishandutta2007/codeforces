#include<stdio.h>
int n,k,a[200002],b[200002],cnt=0,l=1;bool t[200002];char c[200002];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        c[a[i]]=c[b[i]]='a'+l-1;
        if(t[a[i]])cnt--;else cnt++;t[a[i]]^=1;
        if(t[b[i]])cnt--;else cnt++;t[b[i]]^=1;
        if(cnt==0)l++;
        if(l>k){
            for(int i=1;i<=n;i++)if(c[i]==0)c[i]='a'+k-1;
            break;
        }
    }if(l<=k)printf("NO");
    else printf("YES\n%s",c+1);
}