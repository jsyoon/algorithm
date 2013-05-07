#include <vector>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec1(10);
	
	vec1[0] = 0;
	vec1[1] = 2;
	vec1[2] = 54;
	vec1[3] = 24;
	vec1[4] = 22;
	vec1[5] = 7;
	vec1[6] = 9;
	vec1[7] = 33;
	vec1[8] = 30;
	vec1[9] = 21;
	
	for(int i = 1 ; i < 10 ; i++)
	{
		int current = i;
		while(current > 0)
		{
			if(vec1[current] > vec1[current/2] && current != 1)
			{
				int temp;
				temp = vec1[current];
				vec1[current] = vec1[current/2];
				vec1[current/2] = temp;
				current = current/2;
			}
			else break;
		}
	}

	for(int i = 1 ; i <10 ; i++)
		cout<<vec1[i]<<endl;

	cout<<endl;

	for(int i = 1 ; i < 10; i++)
	{
		int temp = vec1[1];
		vec1[1] = vec1[10-i];
		vec1[10-i] = temp;

		int current = 1;
		while(2*current < 9 - i)
		{
			if(vec1[2*current] >= vec1[2*current+1] && vec1[current] < vec1[2*current])
			{
				temp = vec1[current];
				vec1[current] = vec1[2*current];
				vec1[2*current] = temp;
				current = current*2;
			}
			else if(vec1[2*current] < vec1[2*current+1] && vec1[current] < vec1[2*current+1])
			{
				temp = vec1[current];
				vec1[current] = vec1[2*current+1];
				vec1[2*current+1] = temp;
				current = current*2+1;
			}
			else break;
			
		}
	}



	for(int i = 1 ; i < 10 ; i++)
		cout<<vec1[i]<<endl;

	return 0;
}

