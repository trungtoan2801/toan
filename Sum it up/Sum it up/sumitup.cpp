#include<iostream>
using namespace std;
long long t, n, a[101], cnt, cur[101], arr[101];

void BT(int index, int sum){
	if(sum>t) return;
	if(index>n){
		if(sum==t){
			cnt++;
		cur[cnt]=0;
		for(int i=1;i<=n;i++){
			if(arr[i])
			cur[cnt]=cur[cnt]*10 + a[i];
			}
		for(int i=1;i<=cnt-1;i++){
			if(cur[cnt]==cur[i])
				cnt--;
			}
		}
		return;
	}
	arr[index]=0;
	BT(index+1,sum);
	arr[index]=1;
	BT(index+1,sum+a[index]);
	
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int m=1; m<=tc; m++){
		cout<<"#"<<m<<" ";
		cin>>t>>n;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		BT(1,0);
			if(cnt!=0) cout<<cnt<<endl;
			else cout<<-1<<endl;
	}
	return 0;
}