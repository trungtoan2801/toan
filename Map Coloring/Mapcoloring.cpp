#include <iostream>
using namespace std;
int N,B, res=0;
int data[1001][1001], Color[1000];

void Tinh(int x,int index){
	if(index==N){
		return;
	}
	int i;
	for( i=1; i<=N; i++){
		if(data[x][i]==1 && Color[i]==Color[x]){
			res=-1;
			return ;
		}
		else if(data[x][i]==1 && Color[i]==-1){
			Color[i]=1-Color[x];
			Tinh(i,index+1);
			//Color[i]=1-Color[x];
		}
		
	}
	
}

int main(){
//	freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		cin>>N>>B;
		res=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
			{
				data[i][j]=0;
			}
		}
		for(int i=0; i<B; i++){
			int a, b;
			cin>>a>>b;
			data[a][b]=1;
			data[b][a]=1;
		}
		for(int i=0; i<=N; i++){
			Color[i]=-1;
		}
		Color[1]=0;
		Tinh(1,0);
		cout<<"#"<<tc<<" ";
		if(res!=-1){
			for(int i=1; i<=N; i++){
				cout<<Color[i];
			}
			cout<<endl;
		}
		else
			cout<<"-1"<<endl;
	}


	return 0;
}
