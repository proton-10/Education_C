// НОД

// подключаю библиотеки
#include <stdio.h> // ввод/вывод
#include <inttypes.h> // типы фикс длинны


int main(void) // осн ф-ция, т. начала вып. прогр
{
	// создаю и иниц. необходимые перем
	uint32_t n1 = 0, n2 = 0;
	scanf("%"SCNu32"%"SCNu32, &n1, &n2); // считываю их в объекты памяти с соотв адресом
	
	// делаю первое большим
	n1>n2 ? (n1= n1, n2 = n2): (n1 += n2, n2 = n1 - n2, n1 -= n2);

	// ищу НОД
	for (uint32_t i = n1 % n2; i > 0; i = n1 % n2)// если остаток нулевой, т.е. n1 делится на n2 => выходим из цикла
	{
		n1 = n2; // делитель становится остатком
		n2 = i; // остаток становится делителем
	}
	
	printf("%"PRIu32, n2); // вывожу НОД
	
	return 0; // выхожу из ф-ции и возвр в место ее вызова 0
}
