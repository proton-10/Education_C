// Сумма цифр в числе

// подкл библиотеки
#include <stdio.h>
#include <inttypes.h>

int main(void) // осн ф-ция, точка начала вып прог
{
	// создаю перем и ввожу в нее знач
	uint32_t num = 0;
	scanf("%"SCNu32, &num);
	
	uint16_t sum = 0;
	// цикл вып столько раз сколько цифр в числе
	for (int i = num; i > 0; i/=10)
	{
		sum += i%10; // складываем остатки, т.е. цифры числа
	}
	
	printf("%"PRIu16, sum); // вывожу сумму
	
	return 0; // выхожу из ф-ции и возвр в место вызова 0
}
