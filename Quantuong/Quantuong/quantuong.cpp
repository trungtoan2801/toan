#include<iostream>
using namespace std;

int n,m,p,q,s,t;
int data[201][201];
int Qx[40001],Qy[40001];
int dir[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};


int BFS(){

	int rear=-1, front=-1;
	Qx[++rear]=p; //enQueue
	Qy[rear]= q; //enQueue

	while(rear!=front){ //check Empty
		int r=Qx[++front]; //deQueue
		int c=Qy[front]; //deQueue
		for(int v=0; v<4; v++){
			int j=1;
			while(1){
				int dr=r+j*dir[v][0];
				int dc=c+j*dir[v][1];
				if(dr>0&&dr<=n&&dc>0&&dc<=n){ //check edge
					if(data[dr][dc]==-1)  //check wall
						break;
					if(data[dr][dc]==0){ //check visit
						data[dr][dc]=data[r][c]+1;
						Qx[++rear]=dr; //enQueue
						Qy[rear]=dc; //enQueue	
					}
					cout<<dr<<"|"<<dc<<endl;
					if(dr==s && dc==t){
						return data[dr][dc]-1;
					}
				}
				else
					break;
				j++;
			}
		}
	}
	return -1;
}



int main(){
	freopen("input.txt","r", stdin);
	int tc;
	cin>>tc;
	for(int b=1;b<=tc;b++){
		cin>>n>>m>>p>>q>>s>>t;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				data[i][j]=0;
			}
		}

		for(int i=0;i<m;i++){
			int x,y;
			cin>>x >>y;
			data[x][y]=-1;
		}
		data[p][q]=1;
		cout<<BFS()<<endl;
	}

	return 0;
}