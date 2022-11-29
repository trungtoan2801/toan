#include <iostream>
using namespace std;
int data[8][8];
int N;
int cot[100], d1[100], d2[100], X[100];
int sum=0, max1=0, kq;

int inkq(){
	sum=0;
	for(int i=0; i<8; i++){
		sum+=data[i][X[i]];
		//cout<<i<<" "<<X[i]<<endl;
	}
	return sum;
}

void BT(int i){
	for(int j=0; j<8; j++){
		if(cot[j]==0 && d1[i-j]==0 && d2[i+j] ==0){
			X[i]=j;
			cot[j]= d1[i-j]=d2[i+j] =1;
			if(i==7) {
				inkq();
				kq=inkq();
				if(max1<kq) max1=kq;
			}
			else BT(i+1);		
			cot[j] = d1[i-j] = d2[i+j] = 0;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++)		{
		cin>>N;
		cout<<"Case #"<<tc<<endl;

		for(int k=0; k<N; k++){
			max1=0;
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					cin>>data[i][j];
				}
			}
			for(int i=0; i<=100; i++){
				X[i]=0;
				d1[i]=0;
				d2[i]=0;
				cot[i]=0;
			}
			BT(0);
			cout<<max1<<endl;
		}
	}


	return 0;
}
