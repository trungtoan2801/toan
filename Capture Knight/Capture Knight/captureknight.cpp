#include<iostream>
using namespace std;

int n,m;
int dr,dc,r,c;
int Qx[1000001],Qy[1000001];
int rStart,cStart;
int rEnd,cEnd;
int data[1001][1001];
int dir[8][2]={{1,2},{2,1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{2,-1}};



int BFS(){

	int rear=-1, front=-1;
	Qx[++rear]=rStart; //enQueue
	Qy[rear]= cStart; //enQueue

	while(rear!=front){ //check Empty
		int r=Qx[++front]; //deQueue
		int c=Qy[front]; //deQueue
		for(int t=0; t<8; t++){
			int dr=r+dir[t][0];
			int dc=c+dir[t][1];
			if(dr>0&&dr<=n&&dc>0&&dc<=m){ //check edge
				if(data[dr][dc]==0){ //check visit
					data[dr][dc]=data[r][c]+1;
					Qx[++rear]=dr; //enQueue
					Qy[rear]=dc; //enQueue
				}
			}
				if(dr==rEnd && dc==cEnd){
					return data[dr][dc]-1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1; t<=tc;t++){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0; j<m;j++){
				data[i][j]=0;
			}
		}
		
		cin>>rStart>>cStart>>rEnd>>cEnd;
		data[rStart][cStart]=1;

		cout<<"Case #"<<t<<endl;
      	cout<<BFS()<<endl;
	}


	return 0;
}