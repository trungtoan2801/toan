#include<iostream>
using namespace std;
int n,vis[101];
int cnt;

int check(int x){
	for(int i=0;i<=x;i++){
		int ass=i*i*i;
		if(ass>x)
			return i-1;
	}
}

void BT(int index, int sum){
	if(sum>n) return;
	if(index==6){
		if(sum==n){
			cnt++;
		}
		return;
	}
	for(int k=check(n);k>=0;k--){
		int dick=k*k*k;
		if(dick<=vis[index-1]){
			vis[index]=dick;
			BT(index+1,sum+vis[index]);
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++){
		cout<<"#"<<t<<" ";
		cnt=0;
		cin>>n;
		for(int i=0;i<=6;i++){
			vis[i]=0;
		}
		vis[0]=999999;
		BT(1,0);
		cout<<cnt<<endl;
	}
	return 0;
}