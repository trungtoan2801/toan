#include <iostream>

using namespace std;
struct goi
{
	int gia, sl, sp[21];
};
int N, M;
int gia[21];
goi Goi[31];
int Can[21];
int TraTien;
int Ch[31];
int MINN;
int Tinh (int k);
void backtrack(int k);
void F();
int main()
{
	freopen ("input.txt","r", stdin);
	int T; cin>>T;
	for (int tc = 0; tc < T; tc++)
	{
		cout<<"#"<<tc+1<<" ";
		F();
	}
	return 0;
}
void F()
{
	cin>>N;
	TraTien = 0;
	for (int i = 01; i <= N; i++)
	{	
		Can[i] = 0;
		cin>>gia[i];
	}
	cin>>M;
	for (int i = 01; i <= M; i++)
	{
		Ch[i] = 0;
		cin>>Goi[i].gia;
		cin>>Goi[i].sl;
		for (int j = 01; j <= Goi[i].sl; j++)
		{
			cin>>Goi[i].sp[j];
		}
	}
	int a;
	cin>>a;
	for (int i = 01; i <= a; i++)
	{
		int b; cin>>b;
		Can[b] = 1;
		TraTien += gia[b];
	}
	MINN = TraTien;
	/*Ch[4] = 1;
	int c = Tinh(4);
	cout<<c<<endl;*/
	backtrack (1);
	cout<<MINN<<endl;

}
void backtrack (int k)
{
	if (k > M)
	{
		int tien = Tinh(k-1);
		if (tien < MINN) MINN = tien;
		return;
	}
	else
	{
		int tt = Tinh(k);
		if (tt <= TraTien)
		{
			Ch[k] = 1;
			backtrack(k+1);
		}
		Ch[k] = 0;
		backtrack(k+1);
	}
}
int Tinh (int k)
{
	int co[21] = {0};
	int Val = 0;
	for (int i = 01; i <= k; i++)
	{
		if (Ch[i] == 1)
		{
			Val += Goi[i].gia;
			for (int j = 01; j <= Goi[i].sl; j++)
			{
				co [ Goi[i].sp[j] ]++;
			}
		}
	}
	for (int i = 01; i <= N; i++)
	{
		if ( Can[i] == 1 && co[i] == 0)
		{
			Val += gia[i];
		}
	}
	return Val;
	
}