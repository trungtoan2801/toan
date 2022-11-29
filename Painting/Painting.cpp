#include<iostream>
using namespace std;
int a[50][50];
int dem;
int n;
int M[100];

//Check all
bool check(){
	return true;
}

//Kiểm tra ok từ đỉnh 1 đến i hay không
bool check(int k){
	//Tìm tất cả các đỉnh có liên kết với nhau mà cùng màu là sai
	for(int i=1;i<=k-1;i++){
		if(a[i][k] && M[i]==M[k])
			return false;
	}
	return true;
}

void backtrack(int m){
	if(m==n+1) dem++;
	else {
		//Tại i có thể nhận những màu nào
		for(int mau=1;mau<=4;mau++){
			M[m]=mau;
			//nếu màu này thỏa mãn
			if(check(m)) 
				backtrack(m+1); //thì chuyển sang đỉnh tiếp theo
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		dem=0;
		backtrack(1);
		cout<<"Case #"<<t<<endl;
		cout<<dem<<endl;
		
	}

	return 0;
}