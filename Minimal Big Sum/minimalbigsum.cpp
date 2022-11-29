// In Practice, You should use the statndard input/output
// in order to receive a score properly.
// Do not use file input and output. Please be very careful. 

#include<iostream>

using namespace std;

int main()
{
	int test_case;
	int T,k,n;
	//int Answer;
	int a[100000];



	freopen("input.txt", "r", stdin);
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		//Answer = 0;
		cin>>k;
		cin >> n;
		for(int i = 0; i<n; i++)
			cin >> a[i];
		int max = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] > max)
				max = a[i];
		}
		while(true)
		{
			int sum = 0;
			int b = 1;
			for(int i = 0; i < n; i++)
			{	
				sum+= a[i];
				if(sum > max)
				{
					b++;
					sum = a[i];
				}
			}
				if(b<=k)
					break;
				max++;
		}
		cout << "#" << test_case << " " << max << endl;
	}
	return 0;
}