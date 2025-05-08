// Ввести номер месяца и вывести название времени года

#include <stdio.h> // подключаю библиотеку ввода/вывода
#include <inttypes.h> // подключаю библиотеку платформонезависимых типов

int main () // осн ф-ция программы - точка начала выполнения программы
{
	uint8_t m = 0; // создаю перем
	
	scanf ("%hhu", &m); // ввожу значение типа char в перем m
	
	switch(m)
	{
		case 3:
		case 4:
		case 5:
		{
			printf("spring"); // вывожу весну
		}
		break;
		
		case 6:
		case 7:
		case 8:
		{
			printf("summer"); // вывожу лето
		}
		break;
		
		case 9:
		case 10:
		case 11:
		{
			printf("autumn"); // вывожу осень
		}
		break;
		
		case 12:
		case 1:
		case 2:
		{
			printf("winter"); // вывожу зиму
		}
		break;
	}
	
	return 0; // выхожу из ф-ции и возвращаю в место ее вызова 0
}
