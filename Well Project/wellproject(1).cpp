#include<iostream>
using namespace std;
int n;
int a[105][105];
int P[100000];
int u[100000];
int v[100000];
int w[100000];
int d,sizecay;
int socanh;

void Make_Set(){
	for(int i=0;i<n;i++){
		P[i]=i;
	}
}

int Find_Set(int x){
	if(x!=P[x]) return Find_Set(P[x]);
	return x;
}
void swap(int &a, int &b){
	int tam=a;
	a=b;
	b=tam;
}

bool Union(int a,int b){
	int A = Find_Set(a);
	int B = Find_Set(b);
	if(A==B) return false; 
	P[B]=A;
	return true;
}
void sapxep(){
	for(int i=1;i<=socanh;i++){
		for(int j=i+1;j<=socanh;j++){
			if(w[i]>w[j]){
				swap(w[i],w[j]);
				swap(u[i],u[j]);
				swap(v[i],v[j]);
			}
		}
	}
}
void Kruskal(){
	Make_Set();
	sapxep();
	for (int i = 1; i <= socanh; i++)
	{
		if (Union(u[i], v[i]))
		{
			sizecay++;
			d += w[i];
		}
		if (sizecay == n-1) return;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	
	for(int t=1;t<=tc;t++){
		socanh=d=sizecay=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ( j>i )
				{
					socanh++;
					u[socanh] = i;
					v[socanh] = j;
					w[socanh] = a[i][j];
				}
			}
		}
		Kruskal();
		cout<<"Case #"<<t<<endl;
		cout<<d<<endl;

	}
	return 0;
}