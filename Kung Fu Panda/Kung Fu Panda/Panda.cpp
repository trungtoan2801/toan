#include<iostream>
using namespace std;
int n,result;
int data[20],vis[20];
int x,y,kq;

void BT(int index,int sum){
	if(index==n){
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				sum+=data[i];
			}
		}
		if(result<sum){
			result=sum;
		}
	}
	else
	{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				for(int j=i;j>=0;j--){
					if(vis[j]==0){
						x=data[j];
						break;
					}
				}
				for(int j=i;j<=n+1;j++){
					if(vis[j]==0){
						y=data[j];
						break;
					}
				}
				kq=x*y;
				BT(index+1,sum+kq);
				vis[i]=0;
			}
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++){
		cout<<"Case #"<<t<<endl;
		cin>>n;
		result=0;
		for(int i=1;i<=n;i++){
			cin>>data[i];
			vis[i]=0;
		}
		data[0]=1;
		data[n+1]=1;
		BT(1,0);
		cout<<result<<endl;

	}

	return 0;
}