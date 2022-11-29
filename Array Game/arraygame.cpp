#include<iostream>
using namespace std;
int a[20005];
typedef long long LL;
LL SUM_LR[20005];
LL SUM_RL[20005];
int maxCount=0;
int n;
void backtrack(int start, int end, int cnt){
	if(start<end){
		for(int i=1;i<=n-1;i++){
			LL L = SUM_LR[i] - SUM_LR[start-1];
			LL R = SUM_RL[i+1] - SUM_RL[end+1];
			if(L==R){
				cnt++;
				if(cnt>maxCount)
				maxCount=cnt;
				backtrack(start,i,cnt);
				backtrack(i+1,end,cnt);
				break;
				//cnt--;
			}
			if(L>R) break;
		}
	}
}

void F(){
	SUM_LR[0]=0;
	for(int i=1;i<=n;i++){
		SUM_LR[i]= SUM_LR[i-1]+a[i];
	}
	SUM_RL[n+1]=0;
	for(int j=n;j>0;j--){
		SUM_RL[j]=SUM_RL[j+1]+a[j];
	}
	if(SUM_LR[n]==0){
		cout<<n-1<<endl;
	}
	else {
		//minCount=0;
		backtrack(1,n,0);
		cout<<maxCount<<endl;
	}
}




int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		F();
		maxCount=0;
	}

	return 0;
}