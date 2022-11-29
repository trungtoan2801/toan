#include<iostream>
using namespace std;

int t,n,m,oidoioi;
char a;
int xtaoday,ytaoday;
int xdick,ydick;
int data[1000][1000];									int qx[500000];         int dx[4]={-1,0,0,1};
int visit[1000][1000];									int qy[500000];			int dy[4]={0,-1,1,0};

void bfs(){
	int rear=-1; int front = -1;
	qx[++rear]= xtaoday;
	qy[rear]=ytaoday;
		while(rear!=front){
			int xne = qx[++front];
			int yne = qy[front];
			for(int i=0;i<4;i++){
				int dixx = xne + dx[i];
				int diyy = yne + dy[i];
				if(dixx >= 0 && dixx < n && diyy >= 0 && diyy < m ){
					if(data[dixx][diyy]== -5) {
						if(visit[dixx][diyy]==0 || (visit[xne][yne]+2 < visit[dixx][diyy] )){
							visit[dixx][diyy]= visit[xne][yne]+2;
							qx[++rear]=dixx;
							qy[rear]=diyy;
						}
					}
					if(data[dixx][diyy]==0){
						if(visit[dixx][diyy]==0 || (visit[xne][yne]+1 < visit[dixx][diyy]) ){
							visit[dixx][diyy]= visit[xne][yne]+1;
							qx[++rear]=dixx;
							qy[rear]=diyy;
						}
					}
					if(dixx==xdick && diyy==ydick){
						if(visit[dixx][diyy]==0 || (visit[xne][yne]+1 < visit[dixx][diyy]) ){
							visit[dixx][diyy]= visit[xne][yne]+1;
						}
					}
				}
			}
		}
}

int main(){
	//freopen("input.txt","r", stdin);
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>m;
		oidoioi=0;
		//'Y'== 1(bạn), 'T'=-100 (mục tiêu) , 'S'= -6 (tường thép), 'B'= -5 (tường gạch), 'R'= -6 (sông) và 'E' ==0(không gian trống)
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a;
				if(a=='Y') {
					data[i][j]=1;
					xtaoday=i;
					ytaoday=j;
				}
				if(a=='T') {
					data[i][j]=-100;
					xdick=i;
					ydick=j;
				}
				if(a=='S')	data[i][j]=-6;
				if(a=='B')	data[i][j]=-5;
				if(a=='R')	data[i][j]=-6;
				if(a=='E')	data[i][j]=0;
				visit[i][j]=0;
			}
		}
		visit[xtaoday][ytaoday]=1;
		bfs();
		oidoioi = visit[xdick][ydick];
		if(oidoioi==0){
			cout<<"Case #"<<tc<<endl;
                cout<<"-1"<<endl;
		}
		else{
			cout<<"Case #"<<tc<<endl;
            cout<<oidoioi-1<<endl;
		}
        for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
                visit[i][j]=0;
            }
        }
	}
	return 0;
}