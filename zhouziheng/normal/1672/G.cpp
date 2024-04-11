#include<cstdio>
#include<vector>

using namespace std;

const int MOD=998244353;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

int pw2[5000000];
void init_pw2(int n)
{
	pw2[0]=1;for(int i=1;i<=n;i++)pw2[i]=add(pw2[i-1],pw2[i-1]);
}

struct BCJ
{
	int fa[10000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){fa[fnd(x)]=fnd(y);}
}B;

vector<int> V[10000];

char b[2500][2500];

int cnt_r[2500],cnt_c[2500];

int main()
{
	init_pw2(4000000);
	int r=0,c=0;scanf("%d%d",&r,&c);int cnt_q=0;
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)
	{
		scanf(" %c",&b[i][j]);
		if(b[i][j]=='?')cnt_q++;
		else if(b[i][j]=='1')cnt_r[i]^=1,cnt_c[j]^=1;
	}
	
	if(r%2==0&&c%2==0)
	{
		printf("%d",pw2[cnt_q]);return 0;
	}
	if(c%2==0)
	{
		int ans=cnt_q;bool flag=1;
		for(int j=1;j<=c;j++)
		{
			int x=0;for(int i=1;i<=r;i++)if(b[i][j]=='?'){x=1;break;}
			if(x){ans--;}
			else{if(cnt_c[j]){flag=0;break;}}
		}
		int sum=flag?pw2[ans]:0;
		
		ans=cnt_q,flag=1;
		for(int j=1;j<=c;j++)
		{
			int x=0;for(int i=1;i<=r;i++)if(b[i][j]=='?'){x=1;break;}
			if(x){ans--;}
			else{if(!cnt_c[j]){flag=0;break;}}
		}
		if(flag)sum=add(sum,pw2[ans]);
		
		printf("%d",sum);return 0;
	}
	if(r%2==0)
	{
		int ans=cnt_q;bool flag=1;
		for(int i=1;i<=r;i++)
		{
			int x=0;for(int j=1;j<=c;j++)if(b[i][j]=='?'){x=1;break;}
			if(x){ans--;}
			else{if(cnt_r[i]){flag=0;break;}}
		}
		int sum=flag?pw2[ans]:0;
		
		ans=cnt_q;flag=1;
		for(int i=1;i<=r;i++)
		{
			int x=0;for(int j=1;j<=c;j++)if(b[i][j]=='?'){x=1;break;}
			if(x){ans--;}
			else{if(!cnt_r[i]){flag=0;break;}}
		}
		if(flag)sum=add(sum,pw2[ans]);
		
		printf("%d",sum);return 0;
	}
	
	int ans=cnt_q;bool flag=1;
	B.init(r+c);
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++){if(b[i][j]=='?'){B.conn(i,j+r);}}
	for(int i=1;i<=r+c;i++){V[B.fnd(i)].push_back(i);}
	
	for(int i=1;i<=r+c;i++)
	{
		if(V[i].size())
		{
			int x=0;for(int j=0;j<V[i].size();j++)if(V[i][j]>r)x^=cnt_c[V[i][j]-r];else x^=cnt_r[V[i][j]];
			if(x){flag=0;break;}
			else ans-=V[i].size()-1;
		}
	}
	int sum=flag?pw2[ans]:0;
	
	ans=cnt_q,flag=1;
	for(int i=1;i<=r+c;i++)
	{
		if(V[i].size())
		{
			int x=0;for(int j=0;j<V[i].size();j++)if(V[i][j]>r)x^=cnt_c[V[i][j]-r]^1;else x^=cnt_r[V[i][j]]^1;
			if(x){flag=0;break;}
			else ans-=V[i].size()-1;
		}
	}
	if(flag)sum=add(sum,pw2[ans]);
	
	printf("%d",sum);
}