#include<iostream>

using namespace std;
int n;
struct matrix{
	int mang[105][105];
	void init(){
		for(int i =0;i<100;i++){
			for(int j =0;j<100;j++){
				mang[i][j] = 0;
			}
		}
	}
matrix product(matrix a){
		matrix temp;
		temp.init();
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				for(int k=0;k<n;++k)
					temp.mang[i][j]=(long long)((long long)temp.mang[i][j]+((long long)mang[i][k]*(long long)a.mang[k][j]))%100000007;                      
			}            
		}
		return temp;
	}
};
matrix check[100];
matrix pow(matrix a,int n){
		if(n == 1){
			return a; 
		}
		matrix temp = pow(a,n/2);
		if(n%2 == 0){
			
			return temp.product(temp);
		}
		else return a.product(temp.product(temp));
	}
int main(){
	//freopen("input.txt","r",stdin);
	int TC;
	cin >> TC;
	for(int tc = 1;tc<=TC;tc++){
		int m;
		cin >> n >> m;
		matrix a;
		a.init();
		for(int i =0;i<n;i++){
			for(int j =0;j<n;j++){
				cin >> a.mang[i][j];
			}
		}
		matrix b = pow(a,m);
		cout << "Case #" << tc << endl;
		for(int i =0;i<n;i++){
			for(int j =0;j<n;j++){
				cout <<  b.mang[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
