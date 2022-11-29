#include<iostream>
using namespace std;
int n;
double a[100],b[100];
double tinh (double left,double right)
{// int answer=0;
double mid=(right+left)/2;
 //cout<<left<<" "<<right;
	if((right-left)<1e-11)
	{
		//answer= (right+left)/2;
		return mid;}
	else
	{
		double mid=(right+left)/2;
	double trai=0,phai=0;
		for(int i=1;a[i]<mid;i++)
		{
			trai=trai+b[i]/((mid-a[i])*(mid-a[i]));
		}
		for(int i=n;a[i]>mid;i--)
		{
			phai=phai+b[i]/((mid-a[i])*(mid-a[i]));
		}
		if(trai==phai) return mid;
		if(trai>=phai)
		{
			left=mid;
		}
		else
		{
			right=mid;
		}
	}
	return tinh(left,right);
	
}
int main(){
	//freopen("input.txt","r",stdin);
	//int T;
	//cin >> T;
	for (int tc = 1; tc <=10; tc++){
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin >>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin >>b[i];
		}
		double answer[20]={0};
		for (int i=1;i<=n-1;i++)
		{
		answer[i]=tinh(a[i],a[i+1]);
		}
		cout.precision(10);
		cout<<"#"<<tc<<" ";
		for (int i=1;i<=n-1;i++)
		{
		cout<<fixed<<answer[i]<<" ";
		}
		cout<<endl;
		//cout<<1e-9;
	}
	return 0;
}