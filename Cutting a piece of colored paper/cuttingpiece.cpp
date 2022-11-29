#include<iostream>
using namespace std;
int a[129][129] ={0};
int N,W,B;
int checkMau(int hang, int cot, int n)
{
	for(int i = 0; i< n; i++)
		for(int j = 0; j<n; j++)
			if(a[hang+i][cot+j] != a[hang][cot])
				return 2;
	return a[hang][cot];
}
void cat(int hang, int cot, int n)
{
	
	int st = checkMau(hang,cot,n);
	if(st==2)
	{
		cat(hang,cot,n/2);
		cat(hang,cot+n/2,n/2);
		cat(hang+n/2,cot,n/2);
		cat(hang+n/2,cot+n/2,n/2);
	}
	else
	{
		if(st==0) W++;
		else B++;
	}
}


int main()
{
	int T;
	freopen("input.txt","r",stdin);
	cin >> T;
	for(int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for(int i = 0; i< 129; i++)
			for(int j = 0; j< 129; j++)
				a[i][j] = 0;
		for(int i = 0; i< N; i++)
			for(int j = 0; j< N; j++)
				cin>>a[i][j] ;
		W=0;B=0;
		cat(0,0,N);
		cout <<"Case #"<< tc<< endl<<W<<" "<< B<<endl;
	}
	return 0;
}
