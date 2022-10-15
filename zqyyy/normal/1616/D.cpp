    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    inline int read(){
    	int f=1,r=0;char c=getchar();
    	while(!isdigit(c))f^=c=='-',c=getchar();
    	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
    	return f?r:-r;
    }
    const int N=50007;
    int n,pre[N];
    //,f[N][2];
    ll x,a[N],s[N];
    //ll lg[N],st[N][17];
    //inline 
    inline void work(){
    	n=read();
    	for(int i=1;i<=n;i++)a[i]=read();
    	x=read(),s[0]=0;
    	for(int i=1;i<=n;i++)a[i]-=x,s[i]=s[i-1]+a[i];
    	if(n==1){puts("1");return;}
    	pre[1]=0;
    	for(int i=2;i<=n;i++){
    		if(s[i]>=s[i-2] && (i==2 || s[i]>=s[i-3]))pre[i]=pre[i-1];
    		else pre[i]=i,s[i-1]=s[i-2]=-1e18;
    	}
    	//f[1][0]=0,f[1][1]=1;
    	int ans=0;
    	for(int i=1;i<=n;i++)ans+=pre[i]==i;//,cout<<s[i]<<" "<<pre[i]<<" "<<endl;
    	ans=n-ans;
    	printf("%d\n",ans);
    	/*int mx=0;
    	for(int i=1;i<=n;i++){
    		if(pre[i]==i)mx=-1e9;
    		else if(i>1)mx=max(mx,f[i-2][0]-i+2);
    		f[i][0]=max(f[i-1][0],f[i-1][1]);
    		f[i][1]=f[i-1][0]+1;
    		if(i>1)f[i][1]=max(i+mx,f[i][1]);//,mx=max(mx,f[i-1][0]-i+1);
    		cout<<pre[i]<<" "<<s[i]<<" "<<f[i][0]<<" "<<f[i][1]<<endl;
    	}
    	printf("%d\n",max(f[n][0],f[n][1]));*/
    }
    int main(){
    //	freopen("1.in","r",stdin);
    //	freopen("1.out","w",stdout);
    	int test=read();
    	while(test--)work();
        return 0;
    }