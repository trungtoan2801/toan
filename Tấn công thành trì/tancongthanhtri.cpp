#include <iostream>

using namespace std;

struct edge
{
	int u, v, w;
};

int parent[1001]; int sz[1001];
edge E[10001];
int socanh;
int M;
int MAXX;
edge Mst[10001];
int d;
int sizemst;

int matran[101][101] = {0};
void swap(edge& e1, edge& e2);
void sapxep();
void make_set()
{
	for (int i = 0; i < M; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}
int find (int v)
{
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}
bool Union (int a, int b)
{
	a = find (a);
	b = find (b);
	if (a == b) return false;
	if (sz[a] < sz[b])
	{
		int tam = a;
		a =b;
		b =tam;
	}
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}
void Kruskal ();
void F();
int main()
{
	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		F();
	}
	return 0;
}
void F()
{
	sizemst = 0;
	MAXX = 0;
	d=0;
	cin >> M;
	socanh = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matran[i][j]=0;
		}
		
	}
	for (int a = 1; a <= M; a++)
	{
		int i, ci, ui;
		cin >> i >> ui >> ci;
		int ke[100];
		for (int b = 1; b <= ci; b++)
		{
			cin >> ke[i];
			matran[i][ke[i]] += ui;
			matran[ke[i]][i] += ui;
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i > j && matran[i][j] != 0)
			{
				socanh++;
				E[socanh].u = i;
				E[socanh].v = j;
				E[socanh].w = matran[i][j];
				MAXX += matran[i][j];
			}
		}
	}
	Kruskal ();
	cout<<MAXX-d<<endl;

}
void swap(edge& e1, edge& e2)
{
	
	edge tam = e1;
	e1 = e2;
	e2 = tam;
	
}
void sapxep()
{
	for (int i = 1; i <= socanh; i++)
	{
		for (int j = i+1; j <= socanh; j++)
		{
			if (E[i].w < E[j].w) swap(E[i], E[j]);
		}
	}
}
void Kruskal ()
{
	make_set();
	sapxep();
	
	for (int i = 1; i <= socanh; i++)
	{
		if (sizemst  == M-1) break;
		edge e = E[i];
		if (Union (e.u, e.v))
		{
			sizemst++;
			Mst[sizemst] = e;
			d += e.w;
		}
	}
}