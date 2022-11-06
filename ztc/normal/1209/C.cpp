#include<stdio.h>
char a[200002];int t,n;bool p[200002],q[200002];
int main(){
    scanf("%d",&t);
    while(t--){char maxx='0',minn='9';
        scanf("%d%s",&n,a+1);bool f=0;
        for(int i=1;i<=n;i++)if(a[i]<maxx)p[i]=1;else maxx=a[i];
        for(int i=n;i>=1;i--)if(a[i]>minn)q[i]=1;else minn=a[i];
        maxx='0';minn='9';
        for(int i=1;i<=n;i++){
            if(p[i]&&q[i])f=1;
            if(p[i]&&a[i]>maxx)maxx=a[i];
            if(q[i]&&a[i]<minn)minn=a[i];
        }
        if(maxx>minn||f)putchar('-');
        else for(int i=1;i<=n;i++){
            if(p[i])putchar('1');
            else if(q[i])putchar('2');
            else if(a[i]<maxx)putchar('1');
            else putchar('2');
        }
        puts("");for(int i=1;i<=n;i++)p[i]=q[i]=0;
    }
}