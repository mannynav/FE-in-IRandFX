//Exercise 1.2 - Write a sorting algorithm, putting a list of numbers into increasing order,by
//successively comparing adjacent numbers and interchanging them.


//The bubble sort(insertion sort algo) is obviously not the most efficient

void interchange(double& x, double& y)
{
	double temp = x;
	x = y;
	y = temp;
}


void BubbleSort(double a[], int N)
{
	for(int i = 1; i <N; ++i)
	{

		for(int j = 1; j <=N-i;++j)
		{
			if(a[j-1]>a[j])
			{
				interchange(a[j - i], a[j]);
			}
		}
	}
}
