// Ввести два числа. Вывести Above, Less или Equal

#include <stdio.h> // подключаю библиотеку ввода/вывода
#include <inttypes.h> // подключаю библиотеку платформонезависимых типов

int main () // осн ф-ция программы - точка начала выполнения программы
{
	int16_t first_num = 0, second_num = 0; // создаю две целые знаковые переменные 
	
	scanf("%hd%hd", &first_num, &second_num); // ввожу два числа типа short в соотв объекты памяти
	
	printf ("%s", first_num>second_num ? "Above" : (second_num > first_num  ? "Less" : "Equal" )); // вывожу
	
	return 0; // выхожу из ф-ции и возвращаю в место ее вызова 0
}
