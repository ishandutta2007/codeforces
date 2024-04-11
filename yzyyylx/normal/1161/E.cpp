#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

int T,n,top,num[N],ans[N];
char a[N];
vector<int>A,B,C;
map<P,bool>mm;

inline void ask()
{
    int i,j;
    if(!A.size()) return;
    printf("Q %d ",(int)A.size());
    for(i=0;i<A.size();i++) printf("%d %d ",A[i],B[i]);puts("");
    fflush(stdout);
    scanf("%s",a+1);
    for(i=1;i<=A.size();i++) mm[mp(A[i-1],B[i-1])]=(a[i]=='1');
}

int main()
{
    int i,j,t;
    cin>>T;
    while(T--)
    {
	top=0,mm.clear();
	memset(ans,0,sizeof(ans));
	scanf("%d",&n);
	A.clear(),B.clear();
	for(i=2;i<=n;i+=2)
	{
	    A.push_back(i-1);
	    B.push_back(i);
	}
	ask();
	A.clear(),B.clear();
	for(i=3;i<=n;i+=2)
	{
	    A.push_back(i-1);
	    B.push_back(i);
	}
	ask();
	num[++top]=1;
	for(i=2;i<=n;i++) if(!mm[mp(i-1,i)]) num[++top]=i;
//	for(i=1;i<=top;i++) cout<<num[i]<<"  ";puts("");
	A.clear(),B.clear();
	for(i=3;i<=top;i+=4) A.push_back(num[i-2]),B.push_back(num[i]);
	for(i=4;i<=top;i+=4) A.push_back(num[i-2]),B.push_back(num[i]);
	ask();
	A.clear(),B.clear();
	for(i=5;i<=top;i+=4) A.push_back(num[i-2]),B.push_back(num[i]);
	for(i=6;i<=top;i+=4) A.push_back(num[i-2]),B.push_back(num[i]);
	ask();
	ans[num[1]]=1;
	if(top>1) ans[num[2]]=2;
	for(i=3;i<=top;i++)
	{
	    if(mm[mp(num[i-2],num[i])]) ans[num[i]]=ans[num[i-2]];
	    else ans[num[i]]=6-ans[num[i-2]]-ans[num[i-1]];
	}
	A.clear(),B.clear(),C.clear();
	for(i=1;i<=n;i++)
	{
	    if(ans[i]) t=ans[i];
	    ans[i]=t;
	    if(ans[i]==1) A.push_back(i);
	    else if(ans[i]==2) B.push_back(i);
	    else if(ans[i]==3) C.push_back(i);
	}
	printf("A %d %d %d\n",(int)A.size(),(int)B.size(),(int)C.size());
	for(i=0;i<A.size();i++) printf("%d ",A[i]);puts("");
	for(i=0;i<B.size();i++) printf("%d ",B[i]);puts("");
	for(i=0;i<C.size();i++) printf("%d ",C[i]);puts("");
	fflush(stdout);
    }
}