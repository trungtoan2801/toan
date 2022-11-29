#include <iostream>

using namespace std;

int map[300][300];
int visit[300][300];
int N,M; //N - col; M - row
int queue[100000][3];
int head, tail;
int x, y, x2,y2;
int moveX[] = {0,-1,0,1};
int moveY[] = {-1,0,1,0};
void enqueue(int x, int y, int step)
{
	tail++;
	queue[tail][0] = x;
	queue[tail][1] = y;
	queue[tail][2] = step;
}
void dequeue()
{
	head++;
}
int isEmpty()
{
	if(head == tail)
		return 0;
	return 1;
}
void rsQueue()
{
	head = -1; tail = -1;
	for(int i = 0; i< 300; i++)
	{
		for(int j= 0; j< 300; j++)
		{
			visit[i][j] = 0;
		}
	}
}
void getInput()
{
	N = 0;
	M = 0;
	cin >> N >> M;
	x = 0; y = 0; x2 = 0; y2 = 0;
	cin >> y >> x >> y2 >> x2;
	for(int i = 0; i< 300; i++)
	{
		for(int j= 0; j< 300; j++)
		{
			map[i][j] = 0;
		}
	}
	for(int i = 0; i< M; i++)
	{
		for(int j = 0; j< N; j++)
		{
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}
	map[x2-1][y2-1] = 0;

}
int bfs(int bx, int by)
{
	enqueue(bx,by,0);
	visit[bx][by] = 1;
	int done = 0;
	int step = 0;
	while(isEmpty() == 1 && done != 1)
	{
		dequeue();
		int tx = queue[head][0];
		int ty = queue[head][1];
		step = queue[head][2] + 1;
		for(int i = 0; i < 4; i++)
		{
			int x = tx + moveX[i];
			int y = ty + moveY[i];
			if(x >= 0 && x < M && y >= 0 && y < N && visit[x][y] == 0 && map[x][y] != 1)
			{
				if(x == x2-1 && y == y2 - 1)
				{
					bx = x;
					by = y;
					done = 1;
				}
				else
				{
					while(x >= 0 && x < M && y >= 0 && y < N && visit[x][y] == 0 && map[x][y] == 0)
					{
						enqueue(x,y,step);
						visit[x][y] = 1;
						x = x + moveX[i];
						y = y + moveY[i];
						if(x == x2 -1 && y == y2-1)
						{
							done = 1;
						}
					}
				}
			}
		}
	}
	if(done == 0) return -1;
	else return step-1;
}
int main()
{
	//freopen("input.txt","r", stdin);
	int T;
	cin>> T;
	for(int tc = 1; tc <= T; tc++)
	{
		int ans = 0;
		getInput();
		ans = bfs(x-1,y-1);
		rsQueue();
		cout << ans <<endl;
	}
	return 0;
}
