#include<iostream>

void Swap(int& x, int& y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	//while�� �������� ������ �ѹ� ����
	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
	{
		QuickSort(input, left, j);
	}

	if (i < right)
	{
		QuickSort(input, i, right);
	}

}

int main()
{
	int human;
	int useTime;
	int totalTime{0};
	std::cin >> human;

	int* time = new int[human] {};

	for (int i = 0; i < human; i++)
	{
		std::cin >> useTime;
		time[i] = useTime;
	}

	//������������ ����

	QuickSort(time, 0, human - 1);

	//���� ���
	for (int i = 0; i < human; ++i)
	{
		for (int j = 0; j <= i; j++)
		{
			totalTime = totalTime + time[j];
		}
	}

	std::cout << totalTime;

	delete[] time;
}