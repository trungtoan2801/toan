//Output all of subsets of array with sum of all elements is 10

#include<iostream>
using namespace std;
int a[11]={0,1,2,3,4,5,6,7,8,9,10};
int x[100];

void tinhToan(){
	int sum=0;
	for(int i=0;i<=10;i++){
		if(x[i]==1){
			sum+=a[i];
		}
	}
	if(sum==10){
		for(int i=0;i<=10;i++){
			if(x[i]==1){
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}

}
void deQuy(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==11)
			tinhToan();
		else 
			deQuy(i+1);
	}
}


int main(){
	deQuy(0);

	return 0;
}