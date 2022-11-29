#include<iostream>
using namespace std;
int n;
int data[20][6];
int sum;
int dir[3][2]={{-1,-1},{-1,0},{-1,1}};
int check;

void BT(int x, int y, int safe, int coin, bool bomb)
{
	if( x == 0)
	{
		if(coin>sum)
		{
			sum = coin;
		}
	}
	for(int i=0;i<3;i++)
	{
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];
		if(x1>=0 && y1>=0 && x1<n && y1<5)
		{
			if(bomb)
			{
				if(data[x1][y1]==0){
					BT(x1,y1,safe,coin,1);
				}
				if(data[x1][y1]==1){
					BT(x1,y1,safe,coin+1,1);
				}
				if(data[x1][y1]==2)
				{
					BT(x1,y1,4,coin,0);		
					//BT(x1,y1,0,coin-1,1);		
				}
			}
			else{

				if(data[x1][y1]==0)
				{
					BT(x1,y1,safe-1,coin,0);

				}
				if(data[x1][y1]==1)
				{
					BT(x1,y1,safe-1,coin+1,0);
				}
				if(data[x1][y1]==2)
				{
					if( safe > 0)
					{
						BT(x1,y1,safe-1,coin,0);
					}

					else if(coin>0)
					{
						BT(x1,y1,0,coin-1,0);
					}
					else
					{
						return ;
					}

				}
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++){
		cout<<"Case #"<<t<<endl;
		cin>>n;
		sum = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin>>data[i][j];
			}
		}
		check=0;
		BT(n,2,0,0,1);
		cout<<sum<<endl;
	}
	return 0;
}