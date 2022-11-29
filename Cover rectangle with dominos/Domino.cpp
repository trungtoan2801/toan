#include<iostream>
using namespace std;
int Goc[8][9];
int DDau[7][8];
int Domino[7][7];
int dem;

void Backtrack(int hang, int cot)
{
	if(hang==7)
	{
		dem++;
	}
	else
	{
		if(DDau[hang][cot]==1)
		{
			int row,col;
			if(cot==7)
			{
				row= hang+1;
				col= 0;
			}
			else
			{
				row = hang;
				col= cot+1;
			}
			Backtrack(row,col);
		}
		else
		{
			for(int i=0;i<=1;i++)
			{
				if(i==0)  // check hang
				{
					int x1= hang;
					int y1= cot+1;
					if(cot <7 && Domino[Goc[hang][cot]][Goc[x1][y1]]==0 && DDau[x1][y1] ==0)
					{
						Domino[Goc[hang][cot]][Goc[x1][y1]] =1;  // danh dau o dat dat
						Domino[Goc[x1][y1]][Goc[hang][cot]] =1;
						DDau[hang][cot]=1;
						DDau[x1][y1]=1;
						int row,col;
						if(cot==7)
						{
							row= hang+1;
							col= 0;
						}
						else
						{
							row = hang;
							col= cot+1;
						}
						Backtrack(row,col);
						Domino[Goc[hang][cot]][Goc[x1][y1]] =0;  // danh dau o dat dat
						Domino[Goc[x1][y1]][Goc[hang][cot]] =0;
						DDau[hang][cot]=0;
						DDau[x1][y1]=0;
					}
				}
				else  // chen cot
				{
					int x2= hang+1;
					int y2= cot;
					if(hang<6 && Domino[Goc[hang][cot]][Goc[x2][y2]]==0 && DDau[x2][y2] ==0)
					{
						Domino[Goc[hang][cot]][Goc[x2][y2]] =1;  // danh dau o dat dat
						Domino[Goc[x2][y2]][Goc[hang][cot]] =1;
						DDau[hang][cot]=1;
						DDau[x2][y2]=1;
						int row,col;
						if(cot==7)
						{
							row= hang+1;
							col= 0;
						}
						else
						{
							row = hang;
							col= cot+1;
						}
						Backtrack(row,col);
						Domino[Goc[hang][cot]][Goc[x2][y2]] =0;  // danh dau o dat dat
						Domino[Goc[x2][y2]][Goc[hang][cot]] =0;
						DDau[hang][cot]=0;
						DDau[x2][y2]=0;
					}
				}
			}
		}
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	for(int tc=1;tc<=T;tc++)
	{
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<8;j++)
			{
				cin>>Goc[i][j];
				DDau[i][j]=0;
			}
		}
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<7;j++)
			{
				Domino[i][j]=0;
			}
		}

		Backtrack(0,0);
		cout<<"#"<<tc<<" ";
		cout<<dem<<endl;
		dem=0;
	}

	return 0;
}
