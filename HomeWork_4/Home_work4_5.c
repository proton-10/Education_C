// Ввести пять чисел и найти наибольшее из них

#include <stdio.h> // подкл библиотеку ввода/вывода
#include <inttypes.h> // подключаю библиотеку с платформонезависимыми типами данных

int main () // осн ф-ция, точка начала вып прог
{
	int8_t a = 0, b= 0, c = 0, d = 0, e = 0, min = 127, max = -128; // создаю семь знаковых перем
	
	scanf("%hhd%hhd%hhd%hhd%hhd", &a, &b, &c, &d, &e); // ввожу пять чисел типа char в соотв объекты памяти
	
	// ищу минимум
	min = (a<min)?a:min;
	min = (b<min)?b:min;
	min = (c<min)?c:min;
	min = (d<min)?d:min;
	min = (e<min)?e:min;
	
	// ищу максимум
	max = (a>max)?a:max;
	max = (b>max)?b:max;
	max = (c>max)?c:max;
	max = (d>max)?d:max;
	max = (e>max)?e:max;
	
	printf("%hd", min+max); // вывожу сумму
	
	return 0; // выхожу из ф-ции и возвращаю 0 в место вызова ф-ции
}
