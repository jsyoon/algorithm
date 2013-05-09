#include <iostream>
#include <vector>

using namespace std;

void qsort(vector<int>::iterator begin, vector<int>::iterator end)
{
	if(begin != end)
	{
	int pivot = *begin;
	vector<int>::iterator right = end-1;
	vector<int>::iterator left = begin;

		bool is_right = true;
		while(true)
		{
			if(left == right)
			{
				*left = pivot;
				break;
			}
	
			if(is_right)
			{
				if(*right < pivot)
				{
					*left = *right;
					left++;
					is_right = false;
				}
				else right--;
			}
			else
			{
				if(*left > pivot)
				{
					*right = *left;
					right--;
					is_right = true;
				}
				else left++;
			}
		}
	
		qsort(begin, left);
		qsort(left+1, end);
	
	}
};

int main()
{
	vector<int> vec;

	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(0);

	qsort(vec.begin(),vec.end());

	for(int i = 0; i < 10 ; i++)
		cout<<vec[i]<<endl;

	return 0;
}
