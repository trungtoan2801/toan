#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int arr[31];
int n;
int check[40][40]={0};
int max(int a, int b) {
	if (a>b) return a;
	else return b;
}

int min(int a, int b) {
	if (a>b) return b;
	else return a;
}

int score_max(int left, int right, int turn) {
	// nguoi di truoc
	int a=0,b=0;
	if (turn==1) {
		if (left == right) return 0;
		else {
			if(check[left][right]==0)
			{
			a=arr[left]	+score_max(left+1,right,0);
			b=arr[right]+score_max(left,right-1,0);
			check[left][right]=max(a,b);
			return max(a,b);
			}
			else return check[left][right];
		}
	}
	else {
		if (left == right) return 0;
		else {
			if(check[left][right]==0)
			{
			a=score_max(left+1, right,1);
			b=score_max(left, right-1,1);
			check[left][right]=max(a,b);
			return max(a,b);
			}
			else return check[left][right];
		}
	}

	//return max(a,b);
}

int score_min(int left, int right, int turn) {
	// nguoi di truoc
	int a=0,b=0;
	if (turn==1) {
		if (left == right) return 0;
		else {
			if(check[left][right]==0)
			{
			a=arr[left]	+score_min(left+1,right,0);
			b=arr[right]+score_min(left,right-1,0);
			check[left][right]=max(a,b);
			return max(a,b);
			}
			else return check[left][right];
		}
	}
	else {
		if (left == right) return 0;
		else {
			if(check[left][right]==0)
			{
			a=score_min(left+1, right,1);
			b=score_min(left, right-1,1);
			check[left][right]=min(a,b);
			return min(a,b);
			}
			else return check[left][right];
		}
	}

	//return max(a,b);
}

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	for (int tc=1;tc<=t;tc++) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>arr[i];
		int res1 = score_max(1,n,1);
		for(int i=0;i<39;i++)
		{
			for(int j=0;j<39;j++)
			{
				check[i][j]=0;
			}
		}
		int res2 = score_min(1,n,1);
		for(int i=0;i<39;i++)
		{
			for(int j=0;j<39;j++)
			{
				check[i][j]=0;
			}
		}
		cout<<"Case #"<<tc<< endl << res1 <<" "<< res2 <<endl;


	}
	return 0;
	
}
