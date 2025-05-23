// Сумма цифр = произведению

// подключаю библиотеки
#include <stdio.h> // ввод/вывод
#include <inttypes.h> // типы фикс длинны

int main(void) // осн ф-ция, т. начала вып. прогр
{
	// создаю и иниц. необходимые перем
	uint32_t n = 0;
	scanf("%"SCNu32, &n); // считываю в объект памяти с соотв адресом
	
	// цикл перебора всех чисел от 10 до n с шагом 1 
	for (uint32_t i = 10; i <= n; i++)
	{
		uint32_t sum = 0, comp = 1; // создаю перем хранящие результаты
		
		// цикл получения суммы и произведения цифр числа i
		for (uint32_t j = i; j > 0; j /= 10)
		{
			sum += j%10; // сумма цифр
			comp *=j%10; // произведение цифр
		}
		
		// выводим если сумма = произведению
		if(sum == comp)
		{
			printf ("%"PRIu32" ", i); // вывожу число
		}
	}
	
	return 0; // выхожу из ф-ции и возвр в место ее вызова 0
}
