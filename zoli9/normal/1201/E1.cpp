#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<pii> di = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
int n, m;
int X1, Y1, X2, Y2;
queue<pii> q1, q2;
bool isValid(pii cell)
{
    return (1<=cell.F && cell.F<=n && 1<=cell.S && cell.S<=m);
}
int dist1[1009][1009];
int dist2[1009][1009];
pii dad1[1009][1009];
pii dad2[1009][1009];
bool was1[1009][1009];
bool was2[1009][1009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>X1>>Y1>>X2>>Y2;
    q1.push({n/2, m/2});
    dist1[n/2][m/2]=0;
    was1[n/2][m/2]=true;
    while(!q1.empty())
    {
        pii cur=q1.front();
        q1.pop();
        for(pii d: di)
        {
            pii neighbour;
            neighbour.F=cur.F+d.F;
            neighbour.S=cur.S+d.S;
            if(!isValid(neighbour)) continue;
            if(was1[neighbour.F][neighbour.S]) continue;
            dist1[neighbour.F][neighbour.S]=dist1[cur.F][cur.S]+1;
            dad1[neighbour.F][neighbour.S]=cur;
            was1[neighbour.F][neighbour.S]=true;
            q1.push(neighbour);
        }
    }
    q2.push({n/2+1, m/2});
    dist2[n/2+1][m/2]=0;
    was2[n/2+1][m/2]=true;
    while(!q2.empty())
    {
        pii cur=q2.front();
        q2.pop();
        for(pii d: di)
        {
            pii neighbour;
            neighbour.F=cur.F+d.F;
            neighbour.S=cur.S+d.S;
            if(!isValid(neighbour)) continue;
            if(was2[neighbour.F][neighbour.S]) continue;
            dist2[neighbour.F][neighbour.S]=dist2[cur.F][cur.S]+1;
            dad2[neighbour.F][neighbour.S]=cur;
            was2[neighbour.F][neighbour.S]=true;
            q2.push(neighbour);
        }
    }

    if(dist1[X1][Y1]<dist1[X2][Y2] && dist1[X1][Y1]<=dist2[X2][Y2])
    {
        cout<<"WHITE"<<endl;
        fflush(stdout);
        while(1)
        {
            pii uj=dad1[X1][Y1];
            X1=uj.F;
            Y1=uj.S;
            cout<<X1<<" "<<Y1<<endl;
            fflush(stdout);
            if (X1==n/2 && Y1==m/2) return 0;
            cin>>X2>>Y2;
            if(X2==-1 && Y2==-1) return 0;
        }
    }
    if(dist2[X2][Y2]+1<dist2[X1][Y1] && dist2[X2][Y2]<dist1[X1][Y1])
    {
        cout<<"BLACK"<<endl;
        fflush(stdout);
        cin>>X1>>Y1;
        if(X1==-1 && Y1==-1) return 0;
        while(1)
        {
            pii uj=dad2[X2][Y2];
            X2=uj.F;
            Y2=uj.S;
            cout<<X2<<" "<<Y2<<endl;
            fflush(stdout);
            if (X2==n/2+1 && Y2==m/2) return 0;
            cin>>X1>>Y1;
            if(X1==-1 && Y1==-1) return 0;
        }
    }
    if((X1+Y1)%2!=(X2+Y2)%2)
    {
        cout<<"WHITE"<<endl;
        fflush(stdout);
        bool reached=false;
        if(X1==n/2+1 && Y1==m/2)
        {
            reached=true;
        }
        while(1)
        {
            if(reached) break;
            pii uj=dad2[X1][Y1];
            X1=uj.F;
            Y1=uj.S;
            cout<<X1<<" "<<Y1<<endl;
            fflush(stdout);
            if(X1==X2 && Y1==Y2) return 0;
            if (X1==n/2+1 && Y1==m/2) break;
            cin>>X2>>Y2;
            if(X2==-1 && Y2==-1) return 0;
        }
        if(!reached) cin>>X2>>Y2;
        int ddx=abs(X1-X2);
        int ddy=abs(Y1-Y2);
        if((ddx==1 && ddy==2) || (ddx==2 && ddy==1))
        {
            cout<<X2<<" "<<Y2<<endl;
            fflush(stdout);
            return 0;
        }
        cout<<(n/2)<<" "<<(m/2)+2<<endl;
        fflush(stdout);
        if(n/2==X2 && m/2+2==Y2) return 0;
        cin>>X2>>Y2;
        cout<<(n/2)+2<<" "<<(m/2)+1<<endl;
        fflush(stdout);
        if(n/2+2==X2 && m/2+1==Y2) return 0;
        cin>>X2>>Y2;
        cout<<(n/2)<<" "<<(m/2)<<endl;
        fflush(stdout);
        return 0;
    }
    else
    {
        cout<<"BLACK"<<endl;
        fflush(stdout);
        cin>>X1>>Y1;
        if(X1==-1 && Y1==-1) return 0;
        int dx=abs(X2-(n/2+1));
        int dy=abs(Y2-m/2);
        if((dx==1 && dy==2) || (dx==2 && dy==1))
        {
            cout<<n/2+1<<" "<<m/2<<endl;
            fflush(stdout);
            return 0;
        }
        bool reached=false;
        if(X2==n/2 && Y2==m/2)
        {
            reached=true;
        }
        while(1)
        {
            if(reached) break;
            pii uj=dad1[X2][Y2];
            X2=uj.F;
            Y2=uj.S;
            cout<<X2<<" "<<Y2<<endl;
            fflush(stdout);
            if(X1==X2 && Y1==Y2) return 0;
            if (X2==n/2 && Y2==m/2) break;
            cin>>X1>>Y1;
            if(X1==-1 && Y1==-1) return 0;
        }
        if(!reached) cin>>X1>>Y1;
        int ddx=abs(X1-X2);
        int ddy=abs(Y1-Y2);
        if((ddx==1 && ddy==2) || (ddx==2 && ddy==1))
        {
            cout<<X1<<" "<<Y1<<endl;
            fflush(stdout);
            return 0;
        }
        cout<<(n/2)+2<<" "<<(m/2)+1<<endl;
        fflush(stdout);
        if(n/2+2==X1 && m/2+1==Y1) return 0;
        cin>>X1>>Y1;
        cout<<(n/2)<<" "<<(m/2)+2<<endl;
        fflush(stdout);
        if(n/2==X1 && m/2+2==Y1) return 0;
        cin>>X1>>Y1;
        cout<<(n/2)+1<<" "<<(m/2)<<endl;
        fflush(stdout);
        return 0;
    }



    return 0;
}