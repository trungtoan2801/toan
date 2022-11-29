#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)

int kt,mt[200][200],lon,nho,rear,front,que[100000],vis[200][200],kq;
int dx[4]={-1,0,0,1};int dy[4]={0,-1,1,0};
using namespace std;
void Push(int a) {que[++rear]=a;}
int Pop(){return que[front++];}
bool isE(){return (front>rear);}
bool diduoc(int x)
{
    FOR(gt,nho,lon-x)
{
	if(mt[1][1]<gt||mt[1][1]>gt+x) continue;
	FOR(i,1,kt) FOR(j,1,kt) vis[i][j]=0;
	rear=-1;front=0;
	Push(1);Push(1);
	vis[1][1]=1;
	while(!isE())
	{
		int a=Pop();
		int b=Pop();
		if(a==kt&&b==kt) return true;
		FOR(i,0,3)
		{
			int ha=a+dx[i];int co=b+dy[i];
			if(ha<1||co<1||ha>kt||co>kt||mt[ha][co]<gt||mt[ha][co]>gt+x||vis[ha][co]==1) continue;
			Push(ha);Push(co);vis[ha][co]=1;
		}
	}
}
	return false;
}
int main()
{
	int TC;
	freopen("inp.txt","r",stdin);
	cin>>TC;
	FOR(t,1,TC)
	{

		cin>>kt;lon=-1;nho=100000;
		FOR(i,1,kt)
		FOR(j,1,kt)
		{cin>>mt[i][j];
		if(lon<mt[i][j]) lon=mt[i][j];
		if(nho>mt[i][j]) nho=mt[i][j];
		}
		int l=0,r=lon-nho,mid;
		while(r>=l)
		{
			mid=(r+l)/2;
			if (!diduoc(mid)) l=mid+1;
			else {r=mid-1;kq=mid;}
		}
		cout<<"#"<<t<<" "<<kq<<endl;
	}
	return 0;
}