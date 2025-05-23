// Ввести  два целых числа, вывести сумму квадратов всех чисел в промежутке

#include <stdio.h> // подключаю библиотеку ввода\вывода (клавиатура\монитор)

// создаю ф-цию типа int с именем main не принимающую аргументов
int main(void) // точка начала выполнения программы
{
	char n1 = 0, n2 = 0; // создаю целые перем типа char
	
	scanf("%hhd%hhd", &n1, &n2); // считываю в нее число типа char
	
	// ставлю первым меньшее
	(n1<n2)?(n1 = n1, n2 = n2):(n1=n1+n2, n2=n1-n2, n1 = n1-n2);

	// создаю локальную перем
	unsigned long int sum=0; // т.к. 2^16 < 2*(5050^2 ) < 2^32 => long  (5050 = сумма первых 100 чиселы)
		
	// создаю цикл со счетчиком i=n1
	for (int i = n1; i <= n2; i++) // вып пока i<=n2, после каждой итер увел i на 1
	{
		sum += i*i; // считаем сумму квадратов
	}
	
	printf("%lu ", sum); // вывожу значения соотв типа

	
	return 0; // выхожу из ф-ции main и возвр в точку ее вызова 0
	// если получу 0 => прог выполнилась правильно, нет - нет
}
