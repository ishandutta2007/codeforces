#include<bits/stdc++.h>
#define N 300
#define M 1010
#define MN 100100
using namespace std;

int n,m,a,b,c,dp[N][N][N],nxt[MN][30],pos[30];
char str[MN],A[N],B[N],C[N],cz[5],ch;

inline void Min(int &u,int v){if(v<u) u=v;}
int main()
{
    memset(dp,0x3f,sizeof(dp));
    int i,j,t;
    cin>>n>>m;
    scanf("%s",str+1);
    for(i=0;i<26;i++) pos[i]=n+1;
    memcpy(nxt[n+1],pos,sizeof(pos));
    for(i=n;i>=1;i--)
    {
	memcpy(nxt[i],pos,sizeof(pos));
	pos[str[i]-'a']=i;
    }
    memcpy(nxt[0],pos,sizeof(pos));
    dp[0][0][0]=0;
    while(m--)
    {
	scanf("%s%d",cz+1,&t);
	if(cz[1]=='-')
	{
	    if(t==1) a--;
	    else if(t==2) b--;
	    else c--;
	    if(dp[a][b][c]<=n) puts("YES");
	    else puts("NO");
	    continue;
	}
	scanf("%s",cz+1);
	ch=cz[1];
//	cout<<ch<<endl;
	if(t==1)
	{
	    A[++a]=ch;
	    for(i=0;i<=b;i++)
	    {
		for(j=0;j<=c;j++)
		{
		    dp[a][i][j]=nxt[dp[a-1][i][j]][ch-'a'];
//		    cout<<a-1<<" "<<i<<" "<<j<<" "<<dp[a-1][i][j]<<"|"<<a<<" "<<i-1<<" "<<j<<" "<<dp[a][i-1][j]<<"|"<<a<<" "<<i<<" "<<j-1<<" "<<dp[a][i][j-1]<<endl;
		    if(i) Min(dp[a][i][j],nxt[dp[a][i-1][j]][B[i]-'a']);
		    if(j) Min(dp[a][i][j],nxt[dp[a][i][j-1]][C[j]-'a']);
//		    cout<<"get:"<<a<<" "<<i<<" "<<j<<" "<<dp[a][i][j]<<endl;
		}
	    }
	}
	else if(t==2)
	{
	    B[++b]=ch;
	    for(i=0;i<=a;i++)
	    {
		for(j=0;j<=c;j++)
		{
		    dp[i][b][j]=nxt[dp[i][b-1][j]][ch-'a'];
		    if(i) Min(dp[i][b][j],nxt[dp[i-1][b][j]][A[i]-'a']);
		    if(j) Min(dp[i][b][j],nxt[dp[i][b][j-1]][C[j]-'a']);
		}
	    }
	}
	else
	{
	    C[++c]=ch;
	    for(i=0;i<=a;i++)
	    {
		for(j=0;j<=b;j++)
		{
//		    cerr<<" "<<i<<" "<<j<<" "<<c-1<<" "<<dp[i][j][c-1]<<"|"<<ch-'a'<<" "<<nxt[0][ch-'a']<<endl;
		    dp[i][j][c]=nxt[dp[i][j][c-1]][ch-'a'];
		    if(i) Min(dp[i][j][c],nxt[dp[i-1][j][c]][A[i]-'a']);
		    if(j) Min(dp[i][j][c],nxt[dp[i][j-1][c]][B[j]-'a']);
		}
	    }
	}
//	for(i=1;i<=a;i++) cout<<A[i];puts("");
//	for(i=1;i<=b;i++) cout<<B[i];puts("");
//	for(i=1;i<=c;i++) cout<<C[i];puts("");
//	cout<<' '<<a<<" "<<b<<" "<<c<<" "<<dp[a][b][c]<<endl;
	if(dp[a][b][c]<=n) puts("YES");
	else puts("NO");
    }
}