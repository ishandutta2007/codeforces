#include<bits/stdc++.h>
#define ll long long
#define N 20010
#define M 1000000007
using namespace std;

ll n,m,cc,cnt[3];
struct Cz
{
    bool jj;
    ll l,h;
    bool operator < (const Cz &u) const{return l<u.l;}
}cz[N];
struct Jz
{
    ll num[3][3];
    Jz(){memset(num,0,sizeof(num));}
    void clear(){memset(num,0,sizeof(num));}
    Jz operator * (const Jz &u) const
    {
	ll i,j,k;
	Jz res;
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
		for(k=0;k<3;k++)
		{
		    res.num[i][j]+=num[i][k]*u.num[k][j]%M;
		    res.num[i][j]%=M;
		}
	    }
	}
	return res;
    }
    inline void out()
    {
	ll i,j;
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
		cout<<num[i][j]<<" ";
	    }
	    puts("");
	}
	puts("");
    }
}dw,now;

void build()
{
    ll i,j;
    dw.clear();
    for(i=0;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
	    if(abs(i-j)>1) continue;
	    if(cnt[j]) continue;
	    dw.num[i][j]=1;
	}
    }
    /*
    for(i=0;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
	    cout<<dw.num[i][j]<<" ";
	}
	puts("");
    }
    //*/
}

inline Jz po(Jz u,ll v)
{
    Jz res;
//    u.out();cout<<v<<endl;
    res.num[0][0]=res.num[1][1]=res.num[2][2]=1;
    for(;v;)
    {
	if(v&1) res=res*u;
	u=u*u;
	v>>=1;
    }
//    res.out();puts("");
    return res;
}

int main()
{
    ll i,j,p,q,o,a,b,c,pos;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
	scanf("%lld%lld%lld",&o,&p,&q);
	if(o==2&&(p==1 || q==m)) return puts("0"),0;
	p=max(p,2ll),q=min(q,m-1);
	cz[++cc]=(Cz){1,p,o};
	cz[++cc]=(Cz){0,q+1,o};
    }
    sort(cz+1,cz+cc+1);
    now.num[0][1]=1;
    for(i=1,pos=2;i<=cc;i=j)
    {
//	now.out();
//	if(cz[i].l-pos)
//	    cout<<endl<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cz[i].l-pos<<endl;
	build();
	now=now*po(dw,cz[i].l-pos);
	for(j=i;j<=cc&&cz[j].l==cz[i].l;j++)
	{
	    if(cz[j].jj) cnt[cz[j].h-1]++;
	    else cnt[cz[j].h-1]--;
	}
	pos=cz[i].l;
//	now.out();
//	cout<<now.num[0][0]<<" "<<now.num[0][1]<<" "<<now.num[0][2]<<endl;
    }
    build();
//    cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<m-pos+1<<endl;
    now=now*po(dw,m-pos+1);
    cout<<now.num[0][1];
}