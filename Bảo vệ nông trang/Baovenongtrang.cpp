#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int map[701][701],hang,cot,vis[701][701],rear,front,que[100000],dem;
void Push(int x){que[++rear]=x;}
int Pop(){return que[front++];}
bool isE(){return (front>rear);}
void bfs(int x,int y)
{
	int check=1;
	rear=-1;front=0;
	vis[x][y]=1;
	Push(x);Push(y);
	while(!isE())
	{int a=Pop();int b=Pop();
	FOR(i,0,7)
	{
		int ha=a+dx[i];int co=b+dy[i];
		if(ha<0||co<0||ha>=hang||co>=cot) continue;
		if(map[ha][co]==map[a][b]&&!vis[ha][co]){Push(ha);Push(co);vis[ha][co]=1;}
		else if(map[ha][co]>map[a][b]) check=0;
	}
	}
 dem+=check;
}
int main()
{
	freopen("inp.txt","r",stdin);
	int TC;cin>>TC;
	FOR(t,1,TC)
	{
		cin>>hang>>cot;dem=0;
		FOR(i,0,hang-1) FOR(j,0,cot-1) {cin>>map[i][j];vis[i][j]=0;}
		FOR(i,0,hang-1) FOR(j,0,cot-1)
		{
			if(!vis[i][j]) bfs(i,j);
		}
		cout<<"#"<<t<<" "<<dem<<endl;
	}

	return 0;
}