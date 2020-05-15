#include <iomanip>
#include <iostream>

using namespace std;

void write_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "\n";
}

void randomize(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		//рандом чисел от -2 до 2 с точностью 0.01
		//(4 - двойной интервал, вычитаем 2 чтобы сместить из интервала 0..4 в -2..2)
		mas[i] = rand() % (4 * 100) / 100. - 2;
	}
}

double sred(double* mas, int size)
{
	double sred = 0;
	for (int i = 0; i < size; i++)
	{
		sred += mas[i];
	}
	sred /= size;
	return sred;
}

double* remove_over_one_diff(double* mas, int orig_size, int &remove_size)
{
	double* m = new double[orig_size];
	int k = 0; //количество уже найденных чётных
	double s = sred(mas, orig_size);
	for (int i = 0; i < orig_size; i++)
	{
		m[i - k] = mas[i];
		if (abs(mas[i] - s) > 1)//отличается больше чем на 1
		{
			k++;
		}
	}
	remove_size = orig_size - k;//размер нового
	double* mt = new double[remove_size];
	for (int i = 0; i < remove_size; i++)
	{
		mt[i] = m[i];//копируем нужное количество
	}	
	
	return mt;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	cout << "Автор: Никитина Дарья Сергеевна\n";
	cout << "Программа для работы с массивом\n";

	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	double* mas = new double[size];

	randomize(mas, size);

	cout << "Массив: \n";
	write_mas(mas, size);

	double s = sred(mas, size);
	cout << "Среднее арифметическое массива: \n" << s << "\n";

	int remove_size = 0;
	double* removed_mas = remove_over_one_diff(mas, size, remove_size);
	cout << "Массив после удаления отклонений: \n";
	write_mas(removed_mas, remove_size);

	system("pause");

	return 0;
}
