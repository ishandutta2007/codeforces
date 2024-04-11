#include<bits/stdc++.h>
#define mo 1000000007
#define Mo 7368817
#define ll long long
#define N 500005
#define bas 2333
#define P (1<<11)+5
using namespace std;
namespace FastInput{
	const int LBC=2333333;
	char LZH[LBC],*SSS=LZH,*TTT=LZH;
	inline char gc(){
		if (SSS==TTT){
			TTT=(SSS=LZH)+fread(LZH,1,LBC,stdin);
			if (SSS==TTT) return EOF;
		}
		return *SSS++;
	}
	inline int read(){
		int x=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			x=x*10-48+ch;
		return x;
	}
}
using namespace FastInput;
int a[N],b[N],dp[2][42];
int sum[(1<<16)+5],n,m,k,u;
ll v[42],jdb;
char s[42];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int countbit(ll x){
	int ans=0;
	for (;x;ans+=sum[x&65535],x>>=16);
	return ans;
}
struct Karp_De_Chant{
	int head[Mo];
	int tot,v[N*28];
	int nxt[N*28];
	ll hsh[N*28];
	Karp_De_Chant(){
		tot=0;
		memset(head,0,sizeof(head));
	}
	void clear(){
		while (tot){
			nxt[tot]=0;
			head[hsh[tot]%Mo]=0;
			hsh[tot]=0;
			v[tot]=0;
			tot--;
		}
	}
	void Upd(ll x,int y){
		int tmp=x%Mo;
		//printf("%d %lld\n",tmp,x);
		for (int i=head[tmp];i;i=nxt[i])//,printf("%d\n",i))
			if (hsh[i]==x){
				upd(v[i],y);
				return;
			}
		nxt[++tot]=head[tmp];
		head[tmp]=tot;
		hsh[tot]=x;
		v[tot]=y;
	}
}mp[2];
void update(int id,int x,int y,int k,int bit,int times,int v){
	k+=countbit(y&((1<<times)-1));
	k+=countbit(x>>(bit-times));
	y>>=times; x&=(1<<(bit-times))-1;
	mp[id].Upd(1ll*x*bas*bas+1ll*y*bas+k,v);
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int update(){
	int bit=(m<=29?0:m-29);
	int L=bit,R=min(m,28),c=0;
	int count2=0;
	for (int i=L;i<=R;i++)
		count2+=s[i];
	mp[0].clear();
	if (k!=1)
		mp[0].Upd(0,1);
	else mp[0].Upd(0,1); 
	for (int i=1;i<k;i++){
		int pr=a[i],times=0;
		mp[c^1].clear();
		for (int j=0;j<pr;j++) v[j]=0;
		for (int j=0;j<m;j++) v[j%pr]|=(1ll<<j);
		for (int p=0;p<Mo;p++)
			for (int j=mp[c].head[p];j;j=mp[c].nxt[j]){
				times++;
				//if (times%10000==0) printf("%d\n",times);
				ll sta=mp[c].hsh[j];
				int cnt=mp[c].v[j];
				for (int x=0;x<pr;x++){
					ll sta2=sta|v[x];
					if ((sta2|jdb)!=jdb) continue;
					if (i==k-1){
						int bit=max(0,m-29);
						int worktimes=(!a[k]||a[k]>=m?max(0,m-29):a[k]-29);
						int count1=countbit((sta2&((1ll<<(R+1))-1))>>L);
						ll x=sta2&((1ll<<L)-1);
						ll y=sta2>>(R+1);
						if (!worktimes) mp[c^1].Upd(1ll*x*bas*bas+1ll*y*bas+count1,cnt);
						else update(c^1,x,y,count1,bit,worktimes,cnt);
					}
					else
						mp[c^1].Upd(sta2,cnt);
				}
			}
		c^=1;
		//printf("%d %d %d\n",times,a[i],clock()-u); 
	}
	return c;
}
void work2(int id){
	//printf("%d\n",mp[id].tot);
	for (int i=1;i<=3;i++){
		int v=(i==1?29:(i==2?31:37));
		if (v>=m||a[::k]!=v) continue; ::k++;
		mp[id^1].clear();
		int worktimes=(a[k]>m||!a[k]?m-v:a[k]-v);
		int bit=(m<=v?0:m-v);
		int L=bit,R=min(m,v-1);
		int count2=0;
		for (int at=L;at<=R;at++)
			count2+=s[at];
		for (int p=0;p<Mo;p++)
			for (int j=mp[id].head[p];j;j=mp[id].nxt[j]){
				ll table=mp[id].hsh[j];
				int V=mp[id].v[j];
				int k=table%bas; table/=bas;
				int y=table%bas,x=table/bas;
				if (!v) continue;
				update(id^1,x,y,k,bit,worktimes,1ll*V*k%mo);
				update(id^1,x,y,k+1,bit,worktimes,1ll*V*(count2-k)%mo);
				for (int p=0;p<bit;p++){
					int ano=p+v;
					if (s[p]==0) continue;
					if (ano<m&&s[ano]==0) continue;
					int nx=x|(1<<p),ny=y;
					if (ano<m) ny|=1<<(ano-R-1);
					update(id^1,nx,ny,k,bit,worktimes,V);
				}
				for (int p=0;p<bit;p++){
					int xx=p+R+1,ano=xx-v;
					if (ano>=0||s[xx]==0) continue;
					int ny=y|(1<<p);
					update(id^1,x,ny,k,bit,worktimes,V);
				}
			}
		id^=1;
		//printf("%d %d\n",clock()-u,mp[id].tot);
	}
	for (int p=0;p<Mo;p++)
		for (int j=mp[id].head[p];j;j=mp[id].nxt[j]){
			ll table=mp[id].hsh[j];
			int V=mp[id].v[j];
			int igva=table%bas; table/=bas;
			int y=table%bas,x=table/bas;
			upd(dp[0][igva+sum[x]+sum[y]],V);
		}
}
ll calc(){
	int c=0;
	int sum=0;
	for (int i=0;i<m;i++)
		sum+=s[i];
	for (int i=k;i<=n;i++){
		ll pr=a[i];
		for (int j=0;j<=sum;j++){
			upd(dp[c^1][j],1ll*dp[c][j]*(pr-m+j)%mo);
			if (j<sum) upd(dp[c^1][j+1],1ll*dp[c][j]*(sum-j)%mo);
			dp[c][j]=0;
		}
		c^=1;
	}
	return dp[c][sum];
}
int main(){
	for (int i=1;i<1<<16;i++)
		sum[i]=sum[i>>1]+(i&1);
	scanf("%s",s); n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),b[i]=read();
	int flag=(a[1]==1537001);
	m=strlen(s);
	for (int i=0;i<m;i++) s[i]='1'-s[i];
	for (int i=0;i<m;i++) jdb|=(ll)s[i]<<i;
	ll ans=1;
	for (int i=1;i<=n;i++)
		ans=1ll*ans*power(a[i],b[i]-1)%mo;
	sort(a+1,a+n+1);
	for (k=1;k<=n&&a[k]<29;k++);
	int id=update(); work2(id);
	printf("%d",1ll*ans*calc()%mo);
	//printf("\n%d",clock()-u);
}