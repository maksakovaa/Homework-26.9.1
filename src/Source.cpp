#include "SumRandArray.h"
using namespace std;


int main()
{
#if defined(_WIN32) || defined (_WIN64)
	system("chcp 65001");
	system("cls");
#endif
	cout << "«Подсчёт суммы элементов массива»" << endl;
	cout << "Число элементов | число потоков | сумма\t\t       | время" << endl;
	SumRandArray* object1 = new SumRandArray(100000);
	printf("%-*s | %-*i | ", 15, "100 000", 13, 1);
	object1->multiSum(1);
	printf("%-*s | %-*i | ", 15, "100 000", 13, 4);
	object1->multiSum(4);
	printf("%-*s | %-*i | ", 15, "100 000", 13, 8);
	object1->multiSum(8);
	printf("%-*s | %-*i | ", 15, "100 000", 13, 10);
	object1->multiSum(10);
	delete object1;

	cout << endl;

	SumRandArray* object2 = new SumRandArray(1000000);
	printf("%-*s | %-*i | ", 15, "1 000 000", 13, 1);
	object2->multiSum(1);
	printf("%-*s | %-*i | ", 15, "1 000 000", 13, 4);
	object2->multiSum(4);
	printf("%-*s | %-*i | ", 15, "1 000 000", 13, 8);
	object2->multiSum(8);
	printf("%-*s | %-*i | ", 15, "1 000 000", 13, 10);
	object2->multiSum(10);
	delete object2;
	cout << endl;

	SumRandArray* object3 = new SumRandArray(10000000);
	printf("%-*s | %-*i | ", 15, "10 000 000", 13, 1);
	object3->multiSum(1);
	printf("%-*s | %-*i | ", 15, "10 000 000", 13, 4);
	object3->multiSum(4);
	printf("%-*s | %-*i | ", 15, "10 000 000", 13, 8);
	object3->multiSum(8);
	printf("%-*s | %-*i | ", 15, "10 000 000", 13, 10);
	object3->multiSum(10);
	delete object3;


	int n, m;

	cout << "Введите размер массива:" << endl;
	cin >> n;
	cout << "Введите количество частей на которые будет разбит массив:" << endl;
	cin >> m;
	printf("%-*i | %-*i | ", 15, n, 13, m);
	SumRandArray object(n, m);

	object.printArray();
	cout << endl;

	return 0;
}