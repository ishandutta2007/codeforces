#include <bits/stdc++.h>
using namespace std;

//unordered_map< int , unordered_map<int,int> > arr;

typedef pair<int,int> pii;

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
const int C = 6006;
int arr[6006][6006];
const int G = 3001;

void gao(int n)
{
    queue<pii> que;
    arr[0 +G][0 + G] = n;
    if (n >= 4) que.push(make_pair(0,0));
    while (!que.empty())
    {
        pii p=que.front();
        que.pop();
        int num = arr[p.first + G][p.second + G];
        int T = num/4;
        arr[p.first+G][p.second+G] = num%4;
        for (int i=0;4>i;i++)
        {
            int tx = p.first + dx[i];
            int ty = p.second + dy[i];
            int _ = arr[tx+G][ty+G];
            if (_ < 4 && _ + T >= 4) que.push(make_pair(tx,ty));
            _ += T;
            arr[tx+G][ty+G] = _;
        }
    }
}

int main ()
{
    int n,q;
    scanf("%d %d",&n,&q);
    gao(n);
    while (q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if (x+G < 0 || x+G >= C || y+G < 0 || y+G >= C) puts("0");
        else printf("%d\n",arr[x+G][y+G]);
    }
}