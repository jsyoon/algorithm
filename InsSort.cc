#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>

using namespace std;
#define N 30000

void isort(vector<int>::iterator begin, vector<int>::iterator end)
{
	vector<int>::iterator it = begin;
	int size = end - begin;
	
	int i = size - 1;
	while(--i >= 0)
	{
		int temp = *(it + i);
		int j = i;
		while(*(it + ++j) < temp && j <= size-1);
		if(i == --j)continue;
		memcpy(&*(it + i), &*(it + i + 1), sizeof(*it) * (j - i));
		*(it + j ) = temp;
	}
}

int main()
{
	clock_t begin;
	clock_t end;

	vector<int> vec;
	
	for(int i = 0 ; i < N ;i++)
		vec.push_back(N - i);

	begin = clock();
	isort(vec.begin(), vec.end());
	end = clock();

	for(int i = 0 ; i < N ; i++)
		cout<<vec[i]<<endl;

	cout<<endl;
	cout<<(double)(end - begin)/CLOCKS_PER_SEC<<endl;
	return 0;
}
