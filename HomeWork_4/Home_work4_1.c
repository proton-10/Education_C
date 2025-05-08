// Ввести два числа и вывести их в порядке возрастания

#include <stdio.h> // подкл библиотеку ввода/вывода
#include <inttypes.h> // подключаю библиотеку с платформонезависимыми типами данных

int main () // осн ф-ция, точка начала вып прог
{
	char first_num = 0, second_num = 0; // создаю две знаковые переменные перем
	
	scanf("%hhd%hhd", &first_num, &second_num); // ввожу два числа типа char в соотв объекты памяти
	
	// вывожу два числа через терн операции в порядке возрастания
	printf("%d %d", (first_num<=second_num)?first_num:second_num, (first_num<=second_num)?second_num:first_num); 
	
	return 0; // выхожу из ф-ции и возвращаю 0 в место вызова ф-ции
}

