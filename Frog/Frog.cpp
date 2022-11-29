#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
//Trong mt ke, 99999999 la 0 voi toi,1000 nhay xa, 9 nhay gan
int kt,arr[201][3],dis[201],ke[201][201],vis[201],cnt,que[40000];

using namespace std;
int main()
{
	//freopen("ip.txt","r",stdin);
	int TC;
	cin>>TC;
	FOR(t,1,TC)
	{
		cin>>kt;cnt=0;
		FOR(i,0,kt-1) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		FOR(i,0,kt-1)
			{dis[i]=100000000;
		FOR(j,0,kt-1)
		{
			int kc=(arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0])+(arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]);
			int gan=(arr[i][2]+arr[j][2]+40)*(arr[i][2]+arr[j][2]+40);
			int xa=(arr[i][2]+arr[j][2]+90)*(arr[i][2]+arr[j][2]+90);
			if (kc==0) ke[i][j]=0;
			else if(kc<=gan) ke[i][j]=1;
			else if (kc<=xa) ke[i][j]=1000;
			else ke[i][j]=1000000;
		}}
		//BFS
       int rear=-1;int front=0;cnt=0;
    	que[++rear]=0;
		dis[0]=0;
    	while(rear>=front)
	{
		int v=que[front++];
		FOR(i,1,kt-1)
	{
		if(dis[i]>dis[v]+ke[v][i])
		{
		dis[i]=dis[v]+ke[v][i];
		que[++rear]=i;
		}
		
	}
	}
		if (dis[kt-1]>=1000000) cout<<"-1"<<endl;
		else cout<<dis[kt-1]/1000<<" "<<dis[kt-1]%1000<<endl;
	}
	return 0;
}