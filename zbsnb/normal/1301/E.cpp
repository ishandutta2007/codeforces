#include<iostream>
using namespace std;

int sum[510][510][255];

void print(int n,int m){
    for(int k=1;k<=3;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<sum[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    char mp[510][510];
    for(int i=1;i<=n;i++){
        cin>>mp[i]+1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=min(n,m)/2;k++){
                int a=i+1-k,b=j+1-k,c=i+k,d=j+k;
                if(a<=0||b<=0||c>n||d>m)break;
                int flg=0;
                for(int x=a;x<=i;x++)if(mp[x][b]!='R')flg=1;
                for(int y=b;y<=j;y++)if(mp[a][y]!='R')flg=1;

                for(int x=i+1;x<=c;x++)if(mp[x][b]!='Y')flg=1;
                for(int y=b;y<=j;y++)if(mp[c][y]!='Y')flg=1;

                for(int x=a;x<=i;x++)if(mp[x][d]!='G')flg=1;
                for(int y=j+1;y<=d;y++)if(mp[a][y]!='G')flg=1;

                for(int x=i+1;x<=c;x++)if(mp[x][d]!='B')flg=1;
                for(int y=j+1;y<=d;y++)if(mp[c][y]!='B')flg=1;

                if(flg)break;
                sum[a][b][k]++;
            }
        }
    }

    // print(n,m);

    int lim=min(n,m)/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=lim;k++)
                sum[i][j][k]+=sum[i][j-1][k];
        }
    }

    // print(n,m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=lim;k++)
                sum[i][j][k]+=sum[i-1][j][k];
        }
    }

    // print(n,m);

    for(int i=1;i<=q;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        int ans=0;
        for(int k=1;k<=lim;k++){
            int x=c-k*2+1,y=d-k*2+1;
            if(x<a||y<b)break;
            int tmp=sum[a-1][b-1][k]+sum[x][y][k]-sum[a-1][y][k]-sum[x][b-1][k];
            // cout<<sum[a-1][b-1][k]<<" "<<sum[x][y][k]<<" "<<sum[a-1][y][k]<<" "<<sum[x][b-1][k]<<endl;
            // cout<<"! "<<a<<" "<<b<<" "<<x<<" "<<y<<" "<<k<<" "<<tmp<<endl;
            if(tmp<=0)break;
            ans=k;
        }
        cout<<ans*ans*4<<"\n";
    }

}