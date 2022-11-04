#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
char s[1000];
int n,ans,ans2,cnt;
int chu(int *a){
	int x=0;
	for (int i=a[0];i;i--){
		x=x*10+a[i];
		a[i]=x/12; x%=12;
	}
	for (;a[0]&&!a[a[0]];a[0]--);
	return x;
}
void cheng(int *a){
	for (int i=1;i<=a[0];i++) a[i]*=12;
	for (int i=1;i<=a[0]+1;i++)
		a[i+1]+=a[i]/10,a[i]%=10;
	a[0]+=2;
	for (;a[0]&&!a[a[0]];a[0]--);
}
void add(int *a,int *b){
	a[0]=max(a[0],b[0])+1;
	for (int i=1;i<=a[0];i++) a[i]+=b[i];
	for (int i=1;i<=a[0];i++)
		a[i+1]+=a[i]/10,a[i]%=10;
	for (;a[0]&&!a[a[0]];a[0]--);
}
void jian(int *a,int *b){
	for (int i=1;i<=a[0];i++) a[i]-=b[i];
	for (int i=1;i<=a[0];i++)
		if (a[i]<0) a[i]+=10,a[i+1]--;
	for (;a[0]&&!a[a[0]];a[0]--);
}
int main(){
	scanf("%s",s+1);
	a[0]=strlen(s+1);
	reverse(s+1,s+a[0]+1);
	for (int i=1;i<=a[0];i++) a[i]=s[i]-'0';
	for (;a[0];) if ((b[++n]=chu(a))>2) return puts("NO"),0;
	for (int i=1;i<=n;i++) cnt+=b[i];
	if (cnt!=2) return puts("NO"),0;
	int x=1;
	for (;x<=n;x++)
		if (b[x]) break;
	if (x==n) ans=n*2-1;
	else ans=(n-x+1)+(x-1)*2;
	ans2=min((ans+1)/2,1000);
	printf("YES\n1\n%d\n%d\n",ans,ans2-1);
	memset(a,0,sizeof(a));
	a[0]=a[1]=1;
	for (int i=1;i<=ans/2;i++) cheng(a);
	memcpy(b,a,sizeof(b));
	if (!(ans&1)) chu(b);
	for (int i=1;i<=ans2;i++){
		add(a,b);
		if (x!=(ans+1)/2-i+1){
			for (int j=a[0];j;j--)
				printf("%d",a[j]);
			puts("");
		}
		jian(a,b);
		cheng(a); chu(b);
	}
}