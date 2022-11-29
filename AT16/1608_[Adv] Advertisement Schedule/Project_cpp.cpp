//#include <stdio.h>
//
//typedef struct mx{
//	int L;	//length
//	int P;	//point
//} mx;
//
//int ad[60];
//int cus[52][52];
//mx adInput[3];
//
//void generate(int i){
//
//	for(int k=0; k<50; ++k){
//		a[k] = 
//	
//	}
//
//}
//
//int main(){
//
//	int T;
//	int maxPoint;
//	int N;
//	int atN, longN;
//	int in, ilongN;
//
//	freopen("sample_input.txt", "r", stdin);
//	scanf("%d", &T);
//	for(int icase=1;icase<=T;++icase){
//
//		/*input*/
//		scanf("%d %d %d", &N, 
//			adInput[0].L, 
//			adInput[1].L, 
//			adInput[2].L,  
//			adInput[0].P, 
//			adInput[1].P, 
//			adInput[2].P			
//			);
//
//		for(in=1;in<N;++in){
//			scanf("%d %d", &atN, &longN);
//			for(ilongN = atN; ilongN<N; ++ilongN){
//				cus[in][ilongN] = 1;	//has time
//			}
//		}
//
//		/*reset*/
//		generate(1);
//
//		/*start*/
//
//		/*final*/
//		printf("#%d %d\n",icase ,maxPoint);
//	}
//
//	return 0;
//}


#include <stdio.h>

typedef struct mx{
	int value;	//length
	int checked;	//point
} mx;

typedef struct mx1{	
	int value;		
	int checked;	
	int L;			//length
	int P;			//point
} mx1;

//mx a[60];
int ad[60];
int cus[50][50];
mx1 adInput[3];
int m[3];
int maxPoint;
int tempPoint;

int getSum(int N, int at, int L){
	for(int in=0;in<N;in++){
		if(cus[in][at] >= L){
			maxPoint += L;		
		}
	}
	return maxPoint;
}

int generate(int i){
	for(int k=0; k<3; ++k){
		if(adInput[k].checked == 0){
			adInput[k].checked = 1;
			m[i] = k;
			tempPoint = getSum(50,k,adInput[k].L);
			if(maxPoint <= tempPoint){
				maxPoint = tempPoint;
			}
			if(i==2){
				return maxPoint;				
			}else{
				generate(i);
			}
			adInput[k].checked = 0;
		}	
	}
}

int main(){

	int T;
	//int maxPoint;
	int N;
	int atN, longN;
	int in, ilongN;

	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for(int icase=1;icase<=T;++icase){

		/*input*/
		scanf("%d %d %d", &N, 
			adInput[0].L, 
			adInput[1].L, 
			adInput[2].L,  
			adInput[0].P, 
			adInput[1].P, 
			adInput[2].P			
			);

		for(in=1;in<N;++in){
			scanf("%d %d", &atN, &longN);
			for(ilongN = atN; ilongN<N; ++ilongN){
				cus[in][ilongN] = longN;	//has a LONG time
			}
		}

		for(int k=0;k<3;++k){
			adInput[k].checked = 0;
		}

		/*reset*/
		tempPoint = 0;
		maxPoint = 0;
		int finalPoint = generate(1);

		/*start*/

		/*final*/
		printf("#%d %d\n",icase ,finalPoint);
	}

	return 0;
}