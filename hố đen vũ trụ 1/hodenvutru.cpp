#include<iostream>
using namespace std;

int hole[5][5], visit[5] = {0};
int n, xStart, yStart, xEnd, yEnd, minp; 

int Abs(int a, int b){
	if(a-b<0){
        return (b-a);
    }
    else return (a-b);
}

int over(int x, int y){
	if(x==xEnd && y == yEnd) return 1;
	else return 0;
}

void BT(int x, int y, int t){
	if(over(x, y)){
		if(minp > t)
			minp = t;
		return;
	}

	for(int i = -1; i < n; i++){
		if(i == -1){
			int p;
			p = Abs(x,xEnd) + Abs(y,yEnd);
			BT(xEnd, yEnd, t + p);
		}
		else{
			if(visit[i] == 0){
				visit[i] = 1;

				int p1, p2;
				p1 = Abs(x,hole[i][0]) + Abs(y,hole[i][1]);
				p2 = Abs(x,hole[i][2]) + Abs(y,hole[i][3]);

				BT(hole[i][0], hole[i][1], t + p2 + hole[i][4]);
				BT(hole[i][2], hole[i][3], t + p1 + hole[i][4]);

				visit[i] = 0;
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int t, tc;
	cin>>t;
	for(tc = 1; tc <= t; tc++){
		cin>>n;
		cout<<n<<endl;
		cin>>xStart>>yStart>>xEnd>>yEnd;
		cout<<xStart<<yStart<<xEnd<<yEnd<<endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++){
				cin>>hole[i][j];
				cout<<hole[i][j];
			}
			cout<<endl;
		}
		minp = 999999;
		BT(xStart, yStart, 0);
		cout<<"#"<<tc<<" "<<minp<<endl;
	}
	return 0;
}