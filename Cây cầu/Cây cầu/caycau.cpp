#include<iostream>
using namespace std;
int n, cnt,dem,maxx;
int data[1001][6];
int dir[3][2]={{-1,-1},{-1,0},{-1,1}};
int van;

void BT(int x,int y, int cnt){
	if(x==0){
		dem=1;
		if(cnt>maxx) maxx=cnt;
		return;
	}
	for(int i=0;i<3;i++){
		int r= x+dir[i][0];
		int c= y+dir[i][1];
		if(r>=0&&c>=0&&r<n&&c<5){
			if(data[r][c]==0)
				BT(r,c,cnt);
			else if(data[r][c]==1)
				BT(r,c,cnt+1);
			else if(data[r][c]==2){
				if(van==1){
					van=0;
					BT(r,c,cnt);
					van=1;
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
		cout<<"#"<<t<<" ";
		cin>>n;
		cnt=0;
		dem=0;
		van=1;
		maxx=0;
		for(int i=0; i<n;i++){
			for(int j=0; j<5;j++){
				cin>>data[i][j];
			}
		}
		BT(n,2,0);
		if(dem!=0) cout<<maxx<<endl;
		else cout<<-1<<endl;

	}

	return 0;
}