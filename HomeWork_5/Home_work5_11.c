// Перевернуть число

// подключаю библиотеки
#include <stdio.h> // ввод/вывод
#include <inttypes.h> // типы фикс длинны


int main(void) // осн ф-ция, т. начала вып. прогр
{
	// создаю и иниц. необходимые перем
	uint32_t num = 0, i = 0;
	scanf("%"SCNu32, &i); // считываю в объкт с адресом перем i зн
	
	// цикл получения цифр
	for ( ; i > 0; i /= 10)
	{
		num = num*10 + (i%10); // записываю числа в обр. порядке
	}
	
	printf("%"PRIu32, num); // вывод результата
	
	return 0; // выхожу из ф-ции и возвр в место ее вызова 0
}
