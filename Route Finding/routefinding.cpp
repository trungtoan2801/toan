#include<iostream>
using namespace std;
int map[1000][1000];
int visit[10000];
int t,n;
void getInput()
{
	cin >> t >> n;
	for(int i=0;i<=99;i++)
	{
		visit[i]=0;
		for(int j=0;j<=99;j++)
		{
			map[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int xx,yy;
		cin >> xx >> yy;
		map[xx][yy]=1;
	}
}
void DFS(int x)
{
	visit[x]=1;
	for(int i=0;i<=99;i++)
	{
		if(map[x][i]==1&& visit[i]==0)
		{
			visit[i]=1;
			DFS(i);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		getInput();
		DFS(0);
		if(visit[99]==1)
		{
			cout << "#" << t << " "<< "1" << endl;
		}
		else
		{
			cout << "#" << t << " " << "0" << endl;
		}
	}
	return 0;
}
