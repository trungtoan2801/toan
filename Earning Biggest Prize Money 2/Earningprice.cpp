#include<iostream>
using namespace std;

int N, K, leng;
int Answer;
char data[7];

void lengData(char *p){
	while(*p){
		leng++;
		p = p + 1;
	}
}

int convertArrayToNumber(char *t){
	int result = 0;
	for(int i = 0; i < leng; i++){
		result = result* 10 + t[i] - 48;
	} 
	return result;
}

void swap(char &a, char &b){
	int t = a;
	a = b;
	b = t;
}

void play(int index, int k){
	if(index == leng - 1){
		char b[7];
		for(int i = 0; i < leng; i++) 
			b[i] =data[i];
		if(k % 2 != 0) {
			
			swap(b[leng-1], b[leng-2]);
		}
		int temp = convertArrayToNumber(b);
		if(Answer < temp)
			Answer = temp;
		return;
	}
	for(int i = index + 1; i < leng; i++){
		if(k > 0){ //co the swap
			swap(data[index], data[i]);
			play(index + 1, k-1);
			swap(data[index], data[i]);
		}
		play(index+1,k); //or k swap
	} 
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; tc++){
		leng = 0;
		cin>>data;
		cin>>K;
		lengData(data);
		Answer = 0;
		play(0, K);
		cout<<"Case #"<<tc<<endl;
		cout<<Answer<<endl;
	}
	return 0;

}