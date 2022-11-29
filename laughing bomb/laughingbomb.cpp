#include <iostream>
using namespace std;
int q[100000],X[100000],Y[100000];
int enqueue(int &reer, int s[100000],int x)
{
	reer++;
	if(reer<100000)
	{
		s[reer]=x;
	}
	return 0;
}

int dequeue(int &front,int s[100000])
{
	if(front>=-1) 
	{
		front++;
		return s[front];
	}
	return 0;
}
int main ()
{
	//freopen("input.txt","r",stdin);
	int  T;
	cin>>T;
	for(int tc=1;tc<=T;tc++)
	{
		int n,m,x,y,dem;
		cin>>m>>n;
		int a[101][101];
		for (int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				a[i][j]=-1;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		cin>>y>>x;
		//
		int dx[]={1,-1,0,0};
		int dy[]={0,0,1,-1};
		int front=-1,reer=-1;
		int front1=-1,reer1=-1;
		int front2=-1,reer2=-1;
		enqueue(reer,q,a[x][y]);
		enqueue(reer1,X,x);
		enqueue(reer2,Y,y);


		a[x][y]=-1;
		
			while (reer>front)
			{
				dem=dequeue(front,q);
				x=dequeue(front1,X);
				y=dequeue(front2,Y);
				dem++;
				for(int i=0;i<4;i++)
				{
					if(a[x+dx[i]][y+dy[i]]==1)
					{
						a[x+dx[i]][y+dy[i]]=-1;
						//x=x+dx[i];y=y+dy[i];
						enqueue(reer,q,dem);
						enqueue(reer1,X,x+dx[i]);
						enqueue(reer2,Y,y+dy[i]);
					}
				}
			}
		
		cout<<(dem-1)<<endl;
	}
	return 0;
}