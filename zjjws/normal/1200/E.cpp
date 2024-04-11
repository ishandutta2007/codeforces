#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e6+3;
const int MOD=1290438239;
const int f_1=67;
int to[128];
LL s_a[MAX];
LL s_b[MAX];
char a[MAX];
char b[MAX];
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main() {
    int i,j;
    for(char c='A';c<='Z';c++)to[c]=c-'A'+1;
    for(char c='a';c<='z';c++)to[c]=c-'a'+27;
    for(char c='0';c<='9';c++)to[c]=c-'0'+53;
    int n=rin();
    int x,y;
    cin>>a;
    x=strlen(a);x--;
    s_a[0]=to[a[0]];
    for(i=1;i<=x;i++)s_a[i]=(s_a[i-1]*f_1%MOD+to[a[i]])%MOD;
    //s[i]=s[i-1]*f_1+to[a[i]]   %MOD;
    //s[j--n]=s[n]-s[j-1]*f_1^(n-j+1)
	//for(j=n;j>= ;j--)f=f*f_1%MOD if(((s_a[n]-s_a[j-1]*f_1%MOD+MOD)%MOD)==s_b[n-j+1])last=n-j+1;
    for(n--;n>0;n--)
    {
    	cin>>b;
    	y=strlen(b);y--;
    	s_b[0]=to[b[0]];
        for(i=1;i<=y;i++)s_b[i]=(s_b[i-1]*f_1%MOD+to[b[i]])%MOD;
        LL f=1;
        int ans=-1;
 //       for(i=0;i<=x;i++)printf("%c",a[i]);printf("\n");
  //      cout<<b<<endl;
    	for(j=x;j>=max(0,x-y);j--)
		{
			f=f*f_1%MOD;
//			printf("a:%d--%d,b:%d--%d ; s_a:%lld,s_b:%lld\n",j,x,0,x-j,(s_a[x]-s_a[j-1]*f%MOD+MOD)%MOD,s_b[x-j]);
			if(((s_a[x]-s_a[j-1]*f%MOD+MOD)%MOD)==s_b[x-j])ans=x-j;
		}
		for(ans++;ans<=y;ans++)a[++x]=b[ans],s_a[x]=(s_a[x-1]*f_1%MOD+to[a[x]])%MOD;
	}
    for(i=0;i<=x;i++)printf("%c",a[i]);
	return 0;
}