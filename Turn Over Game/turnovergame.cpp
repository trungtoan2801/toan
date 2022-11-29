#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char map[4][4],map1[4][4];
int nhiphan[16],mi;
int dx[4]={-1,0,0,1};int dy[4]={0,-1,1,0};
void swap(int a,int b)
{
	if (map1[a][b]=='b') map1[a][b]='w';
	else map1[a][b]='b';
}
bool kt(){
	if (map1[0][0]=='w')
	{
		FOR(i,0,3) FOR(j,0,3) if(map1[i][j]=='b') return false;
	}
	else {FOR(i,0,3) FOR(j,0,3) if(map1[i][j]=='w') return false;}
	return true;
}
void check(){
	int dem=0;
	FOR(i,0,3) FOR(j,0,3) map1[i][j]=map[i][j];
	FOR(i,0,15)
	{
		if (nhiphan[i])
		{
			dem++;
            if (dem>=mi) return;
			int ha=i/4;
			int co=i%4;
			swap(ha,co);
			FOR(j,0,3)
			{
				int x=ha+dx[j];int y=co+dy[j];
				if(x>=0&&y>=0&&x<4&&y<4) swap(x,y);
			}
		}
	}
	if (kt()&&dem<mi) mi=dem; 
	
}
void sinh(int u) {
    if (u == 16) {
        check();
        return;
    }
    nhiphan[u] = 0;
    sinh(u + 1);
    nhiphan[u] = 1;
    sinh(u + 1);
}
int main()
{
	freopen("input.txt","r",stdin);
	int TC;cin>>TC;
	FOR(t,1,TC)
	{
		mi=100000;int nhi=0;
		FOR(i,0,3)
		FOR(j,0,3)
		{cin>>map[i][j];nhiphan[nhi]=0;nhi++;}
		sinh(0);
		cout<<"Case #"<<t<<endl;
		if (mi==100000) cout<<"impossible"<<endl;
		else cout<<mi<<endl;
	}
	return 0;
}