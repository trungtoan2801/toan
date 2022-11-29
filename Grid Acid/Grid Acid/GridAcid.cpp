#include<iostream>
using namespace std;
int n,m,xlocation_acid,ylocation_acid,xempty,yempty;
int data[3030][3030],visit[3030][3030];
int rear,front,que[20000000];
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int var1,var2;

int Push(int x){
	return que[++rear]=x;
}
int Pop(){
	return que[front++];
}

void BFS(){
	rear=-1,front=0;
	Push(xlocation_acid);
	Push(ylocation_acid);
	while(rear>=front){
		int x1 = Pop();
		int y1 = Pop();
		for(int i=0;i<4;i++){
			int r = x1 + dir[i][0];
			int c = y1 + dir[i][1];
			if(r>0 && c>0 && r<=n && c<=m){
				if(data[r][c]==1 && visit[r][c]==0){
						visit[r][c] = visit[x1][y1]+1;
						Push(r);
						Push(c);
				}
			}
		}
	}
}

int check_Fill_Full_Around_Empty(){
	 int result1=0;
	for(int i=0;i<4;i++){
		int x_Around_Empty = xempty + dir[i][0];
		int y_Around_Empty = yempty + dir[i][1];
		if(x_Around_Empty<1 && y_Around_Empty<1 && x_Around_Empty>n && y_Around_Empty>m) return -1;
		if(visit[x_Around_Empty][y_Around_Empty]==0) return -1;
		if(visit[x_Around_Empty][y_Around_Empty] > result1) 
			result1 = visit[x_Around_Empty][y_Around_Empty];
		
	}
	return result1;
}

int check_Fill_Full_Array(){
	 int result2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(visit[i][j]==0) return -1;
			if(visit[i][j]>result2) 
				result2=visit[i][j];
		}
	}
	return result2;
}


int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++){
		cout<<"Case #"<<t<<endl;
		cin>>n>>m;
		cin>>xlocation_acid>>ylocation_acid;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>data[i][j];
				visit[i][j]=0;
				if(data[i][j]==2){
					xempty=i;
					yempty=j;
				}
				if(data[i][j]==0 || data[i][j]==2)
					visit[i][j]=-1;
			}
		}
		visit[xlocation_acid][ylocation_acid]=1;
		BFS();
		var1= check_Fill_Full_Around_Empty();
		var2= check_Fill_Full_Array();
		if(var1==-1)
			cout<<"-1"<<" "<<"-1"<<endl;
		else
		{
			cout<<var1<<" "<<var2<<endl;
		}

	}
	return 0;
}