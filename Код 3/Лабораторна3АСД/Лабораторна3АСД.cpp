#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int array[], int arrayQuantity)	// Функція сортування алгоритмом "бульбашкою" за зростанням
{
	for (int i = 0; i <= arrayQuantity - 2; i++)	// Цикл для визначення межі між відсортованими та невідсортованими елементами
	{
		int swapCount = 0;	// Змінна для підрахунку кількості обмінів за одну ітерацію
		for (int j = 0; j <= arrayQuantity - i - 2; j++)	// Цикл перевірки сусідніх елементів
		{
			if (array[j] > array[j + 1])	// Якщо даний елемент більший за наступний, то вони міняються місцями
			{
				swap(array[j], array[j + 1]);
				swapCount++;
			}
		}
		if (swapCount = 0)	// Якщо за ітерацію обмінів не відбулося, то це означає, що елементи, які залишились, стоять на потрібних місцях, тобто продовжувати роботу циклу немає сенсу
		{
			break;
		}
	}
}

int linearSearch(int key, int array[], int arrayQuantity)	// Функція лінійного алгоритму пошуку
{
	for (int i = 0; i < arrayQuantity; i++)
	{
		if (array[i] == key)	// Якщо даний елемент дорівнює шуканому, то функція повертає його індекс
		{
			return i;
		}
	}
	return -1;	// Якщо елемент не знайдено, повертається значення -1
}

int binarySearch(int key, int array[], int arrayQuantity)	// Функція бінарного алгоритму пошуку
{
	int lowBorder = 0, highBorder = arrayQuantity - 1, mid;	// Створення змінних лівого та правого кордону пошуку і центрального елементу
	while (lowBorder <= highBorder)
	{
		mid = (lowBorder + highBorder) / 2;	// Визначення центрального елементу
		if (array[mid] > key)	// Якщо значення шуканого елементу менше за значення центрального
		{
			highBorder = mid - 1;	// Зміна значення правого кордону пошуку
		}
		else if (array[mid] < key)	// Якщо більше
		{
			lowBorder = mid + 1;	// Зміна значення лівого кордону пошуку
		}
		else	// Якщо значення шуканого елементу дорівнює центральному
		{
			while (array[mid] == array[mid - 1])	// Якщо значення даного та попереднього елементів співпадають, береться індекс першого елементу, значення якого дорівнює шуканому
			{
				mid--;
			}
			return mid;
		}
	}
	return -1;	// Якщо елемент не знайдено
}

bool test(int testNum, int array[], int arrayQuantity)	// Тестування правильності та швидкодії алгоритмів пошуку
{
	int randomKey;
	for (int i = 0; i <= testNum; i++)	// Тестування правильності роботи функцій пошуку
	{
		randomKey = rand() % 4001 - 2000;	// Генерування випадкового числа для пошуку
		if (linearSearch(randomKey, array, arrayQuantity) != binarySearch(randomKey, array, arrayQuantity))	// Якщо результати алгоритмів пошуку не співпадають
		{
			cout << endl << "Functions for searching work incorrectly!" << endl;
			cout << "On " << i << " try linear search function got value " << linearSearch(randomKey, array, arrayQuantity) << " and binary seacrh function got " << binarySearch(randomKey, array, arrayQuantity) << "." << endl;
			return false;
		}
	}
	cout << "Both functions work correctly." << endl;	// Якщо алгоритми пошуку пройшли перевірку, функція виведе дане повідомлення
	cout << "Now these functions will be used for " << testNum << " times in purpose to test the time they need to execute the task." << endl;

	clock_t startTime = clock();	// Початок заміру часу

	for (int i = 0; i <= testNum; i++)	// Застосування алгоритму лінійного пошуку стільки разів, скільки вказано у змінній testNum
	{
		randomKey = rand() % 4001 - 2000;
		linearSearch(randomKey, array, arrayQuantity);
	}

	clock_t endTime = clock();	// Кінець заміру часу
	double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;

	cout << "Result of linear search function: " << seconds << " seconds;" << endl;

	startTime = clock();	// Початок заміру часу

	for (int i = 0; i <= testNum; i++)	// Застосування алгоритму бінарного пошуку стільки разів, скільки вказано у змінній testNum
	{
		randomKey = rand() % 4001 - 2000;
		binarySearch(randomKey, array, arrayQuantity);
	}

	endTime = clock();	// Кінець заміру часу
	seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;

	cout << "Result of binary search function: " << seconds << " seconds." << endl;

	return true;
}

void shuffle(int array[], int arrayQuantity)	// Функція перетасовки масиву алгоритмом Фішера - Йєтса
{
	for (int i = arrayQuantity - 1; i > 0; i--)
	{
		int j = rand() % i;	// Випадкове визначення індексу наступного елементу для обміну
		swap(array[i], array[j]);
	}
}

int digitsSum(int Num, int Sum = 0)	// Функція визначення суми цифр числа
{
	if (Num == 0)
		return Sum;
	Sum += Num % 10;
	digitsSum(Num / 10, Sum);
}

void selectSort(int array[], int sortStart, int sortEnd)	// Функція сортування вибором за зростанням. Введена як додаток до наступної функції для сортування чисел з рівними сумами цифр
{
	for (int i = sortStart; i <= sortEnd; i++)
	{
		int min = i;
		for (int j = i + 1; j <= sortEnd; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array[i], array[min]);
	}
}

void selectSortSpec(int array[], int arrayQuantity)	// Функція сортування вибором за критерієм суми цифр числа у порядку зростання
{
	for (int i = 0; i <= arrayQuantity - 2; i++)	// Цикл визначення межі перевірки
	{
		int min = i;
		for (int j = i + 1; j <= arrayQuantity - 1; j++)	// Цикл порівняння значеннь чисел
		{
			if (digitsSum(array[j]) < digitsSum(array[min]))
			{
				min = j;
			}
		}
		swap(array[i], array[min]);
	}
	for (int i = 1; i < arrayQuantity; i++)	// Цикл сортування чисел з рівними сумами цифр
	{
		if (digitsSum(array[i]) == digitsSum(array[i - 1]))	// Якщо значення даного та минулого елементів рівні
		{
			int sortStart = i - 1;	// Встановлення лівої межі сортування
			while (digitsSum(array[i]) == digitsSum(array[i + 1]))	// Цикл визначення індекса останнього елемента з однакоквою сумою цифр
			{
				i++;
			}
			int sortEnd = i;	// Встановлення правої межі сортування
			selectSort(array, sortStart, sortEnd);	// Застосування додаткової функції сортування
		}
	}
}

double terSearchMin(double a, double b, double left, double right, double eps)	// Функція тернарного алгоритму пошуку
{
	double A, B;
	while (right - left > eps)	// Цикл перевірки задовільності заданій точності
	{
		A = (left * 2 + right) / 3;	// Обчислення значення першої та другої точок
		B = (left + 2 * right) / 3;
		if (A * A + A * a + b < B * B + a * B + b)	// Якщо розв'язок функції за першою точкою менший за розв'язок за другою
		{
			right = B;	// Правому кордону присвоюється значення другої точки
		}
		else	// Якщо навпаки
			left = A;	// Лівому кордону присвоюється значення першої точки
	}
	return round((left + right) / 2 / eps) * eps;	// Застосування формули з ціллю позбутися ймовірної похибки. Виведення результату
}

int main()
{
	srand(time(NULL));

	int taskNum;

	while (true)
	{
		cout << "Enter the task number (0 to exit): ";	// Запит на введення номеру завдання
		cin >> taskNum;
		if (taskNum == 0)	// Завершення роботи програми
		{
			return 0;
		}
		else if (taskNum == 1)	// Завдання 1
		{
			int const N = 1000;
			int array[N];

			for (int i = 0; i < N; i++)	// Заповнення масиву випадковими елементами
			{
				array[i] = rand() % 4001 - 2000;
			}

			bubbleSort(array, N);	// Застосування функції сортування "бульбашкою"
			test(100000, array, N);	// Тестування функцій пошуку
		}
		else if (taskNum == 2)	// Завдання 2
		{
			int const N = 200;
			int array[N];

			for (int i = 0; i < N; i++)	// Заповнення масиву натуральними числами
			{
				array[i] = i + 1;
			}

			cout << "Shuffled: " << endl;

			shuffle(array, N);	// Застосування функції перетасовки масиву
			for (int i = 0; i < N; i++)
			{
				cout << array[i] << " ";
			}

			cout << endl << "Sorted: " << endl;

			selectSortSpec(array, N);	// Застосування функції сортування вибором за критерієм зростання суми цифр
			for (int i = 0; i < N; i++)
			{
				cout << array[i] << " ";
			}
			cout << endl;
		}
		else if (taskNum == 3)	// Завдання 3
		{
			int const N = 200;
			double f[N], left = -100, right = 100, a, b, eps;

			cout << "To calculate the minimum of the function f(x) = x^2 + a*x + b on the interval [" << left << "; " << right << "], " << endl;
			cout << "it is necessary to specify the values of the variables a, b, and epsilon." << endl;

			cout << "Enter the value of a: ";
			cin >> a;

			cout << "Enter the value of b: ";
			cin >> b;

			while (true)	// Цикл для введення правильного значення змінної, що відповідає за точність
			{
				cout << "Enter the value of epsilon: ";
				cin >> eps;

				if (eps > 1 || eps <= 0)
				{
					cout << "You have entered wrong value. Try again." << endl;
				}
				else
					break;
			}

			cout << terSearchMin(a, b, left, right, eps) << endl;	// Застосування функції тернарного пошуку
		}
		else	// Якщо введено номер завдання, якого не існує
			cout << "Task with such number doesn't exist.\n";
	}
}