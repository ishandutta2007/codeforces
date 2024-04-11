#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
int n;
int d[50];
int c[51][4];
ll f[50][316251];
int v[316251];
int id[6632550];
int get(int i, int j, int k, int l){
	return id[(((i*51)+j)*51+k)*51+l];
}
void get(int id, int *r){
	id=v[id];
	for(int i=4; i>=1; i--){
		r[i]=id%51;
		id/=51;
	}
}
int main(){
	for(int i=0; i<=50; i++) c[i][0]=1;
	for(int i=0; i<=50; i++) c[i][1]=i;
	for(int i=0; i<=50; i++) c[i][2]=i*(i-1)/2;
	for(int i=0; i<=50; i++) c[i][3]=i*(i-1)*(i-2)/6;
	int cnt=0;
	for(int i=0; i<=50; i++) for(int j=0; i+j<=50; j++) for(int k=0; i+j+k<=50; k++) for(int l=0; i+j+k+l<=50; l++){
		v[cnt]=(((i*51)+j)*51+k)*51+l;
		id[v[cnt]]=cnt;
		cnt++;
	}
	cin>>n;
	for(int i=0; i<n; i++) cin>>d[i];
	f[1][get(d[0]==2, d[0]==3, d[1]==2, d[1]==3)]=1;
	for(int i=1; i<n; i++){
		int a[5];
		for(int j=0; j<cnt; j++) if(f[i][j]){
			get(j, a);
			if((a[1]==0)&&(a[2]==0)){
				if(a[3]||a[4]){
					(f[i][get(a[3], a[4], 0, 0)]+=f[i][j])%=base;
				}
			}
			else{
				if(i+1<n){
					//attached to 1 thing
					if(a[1]) (f[i+1][get(a[1]-1, a[2], a[3]+(d[i+1]==2), a[4]+(d[i+1]==3))]+=f[i][j]*a[1])%=base;
					if(a[2]) (f[i+1][get(a[1]+1, a[2]-1, a[3]+(d[i+1]==2), a[4]+(d[i+1]==3))]+=f[i][j]*a[2])%=base;
					
					//attached to 2 things
					if(a[1]&&a[3]) (f[i+1][get(a[1]-1, a[2], a[3]-1+(d[i+1]==3), a[4])]+=(f[i][j]*a[1])%base*a[3])%=base;
					if(a[1]&&a[4]) (f[i+1][get(a[1]-1, a[2], a[3]+1+(d[i+1]==3), a[4]-1)]+=(f[i][j]*a[1])%base*a[4])%=base;
					
					if(a[2]&&a[3]) (f[i+1][get(a[1]+1, a[2]-1, a[3]-1+(d[i+1]==3), a[4])]+=(f[i][j]*a[2])%base*a[3])%=base;
					if(a[2]&&a[4]) (f[i+1][get(a[1]+1, a[2]-1, a[3]+1+(d[i+1]==3), a[4]-1)]+=(f[i][j]*a[2])%base*a[4])%=base;
					
					//attached to 3 things
					if(d[i+1]==3){
						
						if((a[3]>=2)&&a[1]) (f[i+1][get(a[1]-1, a[2], a[3]-2, a[4])]+=(f[i][j]*a[1])%base*c[a[3]][2])%=base;
						if((a[3]>=2)&&a[2]) (f[i+1][get(a[1]+1, a[2]-1, a[3]-2, a[4])]+=(f[i][j]*a[2])%base*c[a[3]][2])%=base;
						
						if((a[4]>=2)&&a[1]) (f[i+1][get(a[1]-1, a[2], a[3]+2, a[4]-2)]+=(f[i][j]*a[1])%base*c[a[4]][2])%=base;
						if((a[4]>=2)&&a[2]) (f[i+1][get(a[1]+1, a[2]-1, a[3]+2, a[4]-2)]+=(f[i][j]*a[2])%base*c[a[4]][2])%=base;
	
						if(a[1]&&a[3]&&a[4]) (f[i+1][get(a[1]-1, a[2], a[3], a[4]-1)]+=((f[i][j]*a[1])%base*a[3])%base*a[4])%=base;
						if(a[2]&&a[3]&&a[4]) (f[i+1][get(a[1]+1, a[2]-1, a[3], a[4]-1)]+=((f[i][j]*a[2])%base*a[3])%base*a[4])%=base;
						
					}
				}
			}
		}
	}
	cout<<f[n-1][get(0, 0, 0, 0)]<<'\n';;
}