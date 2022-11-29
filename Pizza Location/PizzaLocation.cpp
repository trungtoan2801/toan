#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)

struct Point{int x;int y;};
int K,R,M,s[101],N,visk[101],vish[21],rear,front,result,arr[21],lon,map[21][101];
Point hang[21],khach[101];

using namespace std;
int kc(int a,int b)
{return ((khach[a].x-hang[b].x)*(khach[a].x-hang[b].x)+(khach[a].y-hang[b].y)*(khach[a].y-hang[b].y));
}
int dis()
{
	FOR(i,0,N-1) visk[i]=0;
	int sum=0;
	FOR(i,0,N-1) //khach
	{
		FOR(j,0,M-1)  //hang
		{
			if(!visk[i]&&(kc(i,j)<=R*R)&&arr[j])
			{
				visk[i]=1;
				sum+=s[i];
				if(sum==lon) return sum;
			}
		}
	}
	return sum;
}
//void show()
//{
//	FOR(i,0,M-1) cout<<arr[i]<<" ";
//	cout<<endl;
//}
void dfs(int index,int count)
{
	if (count>K)return;
	else if(index==M)
	{
		if(count==K){
	//		show();
		int kq=dis();
		if(kq>result) result=kq;
		}
		return ;
	}
	arr[index]=0;
	dfs(index+1,count);
	arr[index]=1;
	dfs(index+1,count+1);
}

int main()
{
	freopen("ip.txt","r",stdin);
		int TC;cin>>TC;
		FOR(t,1,TC){
		cin>>K>>R>>M;result=0;lon=0;
		FOR(i,0,M-1) {cin>>hang[i].x>>hang[i].y;vish[i]=0;}
		cin>>N;
		FOR(i,0,N-1) {cin>>khach[i].x>>khach[i].y>>s[i];lon+=s[i];}
		dfs(0,0);
		cout<<"#"<<t<<" "<<result<<endl;}
	return 0;
}