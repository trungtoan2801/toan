#include<iostream>
using namespace std;
int n,m,xStart,yStart,xEnd,yEnd;
int data[101][101],vis[101][101],result[101][101];
int rear,front,que[20000];
int rearE, frontE;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int maxx,temp,ans;
int const vc= 99999999;
struct elem{
	int tmpH;
	int mMax;
	elem(){
		tmpH = mMax = 0;
	}
};
elem queElem[20000];
int Push(int x){
	return que[++rear]=x;
}
void pushElem(elem tmp) {
	queElem[++rearE] = tmp;
}
elem popElem(){
	return queElem[frontE++];
}
int Pop(){
	return que[front++];
}
int dem = 0;
void BFS(){
	rear=-1,front=0;
	rearE = -1, frontE = 0;
	Push(xStart);
	Push(yStart);
	elem tmp;
	pushElem(tmp);
	while (rear>=front)
	{
		dem++;
		//cout<<dem;
		int x1 = Pop();
		int x2 = Pop();
		elem tmpElem = popElem();
		for(int i=0;i<4;i++){
			int r = x1 + dir[i][0];
			int c = x2 + dir[i][1];
			if ( r == 0 && c == 0) {
				int d = 0;
			}
			if(r>=0 && c>=0 && r<n && c<m){
				//if(r==x1 && data[x1][x2+1]==0 || data[x1][x2-1]==0) continue;
				elem tmpElem2 = tmpElem;
				if(data[r][c]==0){
					if(r==x1) continue;
					tmpElem2.tmpH++;
					if ( tmpElem2.tmpH > tmpElem2.mMax ) tmpElem2.mMax = tmpElem2.tmpH;
					if(vis[r][c]== vc || tmpElem2.mMax < vis[r][c]){
						vis[r][c] = tmpElem2.mMax;
						//elem tmpElem = tmpElem;
						//tmp.tmpH++;
						pushElem(tmpElem2);
						Push(r);
						Push(c);
					}
				}
				if(data[r][c]==1){
					elem tmpElem3 = tmpElem;
					if(data[x1][x2]==0){
						tmpElem3.tmpH++;
						if ( tmpElem3.tmpH > tmpElem3.mMax ) tmpElem3.mMax = tmpElem3.tmpH;
						if(tmpElem3.mMax < vis[r][c]){
							tmpElem3.tmpH = 0;
							pushElem(tmpElem3);
							vis[r][c]= tmpElem3.mMax;
							Push(r);
							Push(c);
						} 
					}
					else {
						if(tmpElem3.mMax < vis[r][c]){
							vis[r][c] = tmpElem3.mMax;
							pushElem(tmpElem3);
							Push(r);
							Push(c);
						}
					}
				}
			}
			if(r==xEnd && c==yEnd){
				elem tmpElem4 = tmpElem;
				tmpElem4.tmpH++;
				if ( tmpElem4.tmpH > tmpElem4.mMax ) tmpElem4.mMax = tmpElem4.tmpH;
				if (tmpElem4.mMax < vis[r][c] ) vis[r][c] = tmpElem4.mMax;
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1; t<=tc;t++){
		cin>>n>>m;
		maxx=0;
		temp=0;
		ans=1000000;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>data[i][j];
				vis[i][j]=vc;
				if(data[i][j]==2){
					xStart=i;
					yStart=j;
					vis[i][j] = 0;
				}
				if(data[i][j]==3){
					xEnd=i;
					yEnd=j;
				}
			}
		}
		BFS();
		ans = vis[xEnd][yEnd];
		if(ans==1000000)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;

	}
	return 0;
}