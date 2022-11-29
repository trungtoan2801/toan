#include <iostream>

using namespace std;

int arr[205][205], N;
int visit[205][205];
int moveX[] = {1,-1,0,0};
int moveY[] = {0,0,-1,1};
int head, tail;
int s1,s2;
int xh, yh;
int queue[100000][3];
void rsQueue()
{
	head = -1; tail = -1;
	for(int i = 0; i< 1000; i++)
	{
		for(int j = 0; j< 3; j++)
		{
			queue[i][j] = 0;
		}
	}
	for(int i = 0; i< 200; i++)
	{
		for(int j = 0; j< 200; j++)
		{
			visit[i][j] = 0;
		}
	}
}
void getInput()
{
	cin >> N;
	rsQueue();
	for(int i = 0; i< 200; i++)
	{
		for(int j = 0; j< 200; j++)
		{
			arr[i][j] = 0;
		}
	}
	for(int i = 0; i <N; i++)
	{
		for(int j = 0; j< N; j++)
		{
			cin >> arr[i][j];
		}
	}
}
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
	if(head==tail)
	{
		return 0;
	}
	return 1;
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
		for(int i =0; i< 4; i++)
		{
			int x = tx + moveX[i];
			int y = ty + moveY[i];
			if(x >= 0 && x< N && y >= 0 && y < N && visit[x][y] == 0 && arr[x][y] != 0)
			{
				if(arr[x][y] ==  2)
				{
					bx = x;
					by = y;
					done = 1;
				}
				if(arr[x][y] == 1)
				{
					visit[x][y] = 1;
					enqueue(x,y,step);
				}
			}
		}
	}
	if(done == 0) return -1;
	else
		return step;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; tc++)
	{
		int ans = 0;
		N = 0;
		s1 = 0;
		s2 = 0;
		xh = 0;
		yh = 0;
		getInput();
		s1 = bfs(0,0);
		rsQueue();
		s2 = bfs(N-1,N-1);
		rsQueue();
		if(s1 != -1 && s2 != -1)
		{
			ans = s1 + s2;
		}
		else ans = -1;
		cout<< ans<<endl;
	}
	return 0;
}


