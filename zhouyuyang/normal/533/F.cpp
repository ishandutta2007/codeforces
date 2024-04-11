#include<bits/stdc++.h>
#define bas 47
#define N 200005
#define ll long long
using namespace std;
char s1[N],s2[N];
int l1,l2,now,la,cnt,tot;
int vis[233],nx[N][26],id[26],ans[N],v[26];
ll p[N],hsh[N][26],hsh1,hsh2;
int main(){
	scanf("%d%d%s%s",&l1,&l2,s1+1,s2+1);
	p[0]=1;
	for (int i=1;i<=l1;i++)
		p[i]=p[i-1]*bas;
	for (int i=1;i<=l2;i++)
		hsh2=hsh2*bas+s2[i]-'a'+1;
	for (int i=0;i<26;i++)
		nx[l1+1][i]=l1+1,id[i]=i;
	for (int i=l1;i>=1;i--)
		for (int j=0;j<26;j++)
			nx[i][j]=(s1[i]=='a'+j?i:nx[i+1][j]);
	for (int i=1;i<=l1;i++)
		for (int j=0;j<=26;j++)
			hsh[i][j]=hsh[i-1][j]*bas+(s1[i]=='a'+j?1:0);
	for (int i=1;i+l2-1<=l1;i++){
		hsh1=0;
		memset(v,0,sizeof(v));
		for (int j=0;j<26;j++){
			if (nx[i][j]<=i+l2-1){
				int ano=s2[nx[i][j]-i+1]-'a';
				if (!v[j]&&!v[ano]){
					v[j]=ano+1; v[ano]=j+1;
				}
				hsh1+=v[j]*(hsh[i+l2-1][j]-hsh[i-1][j]*p[l2]);
			}
		}
		if (hsh1==hsh2)
			ans[++tot]=i;
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++)
		printf("%d ",ans[i]);
}