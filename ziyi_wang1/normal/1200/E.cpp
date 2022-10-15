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
char c[1010000],b[1010000],ans[1010000];
int n,m,nt[1010000],len,l,sum,p;
int main(){
	read(n);sum=0;
	scanf("%s",c+1);
	sum=strlen(c+1);
	F(i,1,sum){
		ans[i]=c[i];
	}
	F(i,2,n){
		scanf("%s",c+1);
		len=strlen(c+1);
		if(sum>=len){
			F(j,1,len){
				b[j]=c[j];
			}
			F(j,1,len){
				b[j+len]=ans[sum-len+j];
			}
			l=len<<1;
		}
		else{
			F(j,1,sum){
				b[j]=c[j];
			}
			F(j,1,sum){
				b[j+sum]=ans[j];
			}
			l=sum<<1;
		}
		nt[1]=0;p=0;
		F(j,2,l){
			while((p&&b[j]!=b[p+1])||p>(l>>1))p=nt[p];
			if(b[j]==b[p+1])p++;
			if(p>(l>>1))p=nt[p];
			nt[j]=p;
		}
		p=min(nt[l],l>>1);
		//cout<<p<<endl;
		F(j,p+1,len){
			ans[++sum]=c[j];
		}
	}
	F(i,1,sum){
		printf("%c",ans[i]);
	}
    return 0;
}