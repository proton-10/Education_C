// Цифры числа в прямом порядке

#include <stdio.h> // подкл библ ввода/вывода

void get_digit(); // прототип ф-ции

int main(void) // осн ф-ция, т начала вып прог
{
	get_digit(); // вызываю ф-цию
	return 0; // выхожу из ф-ции и возвращаю в место ее вызова 0
}

void get_digit() // заголовок ф-ции
{
	char d; // создаю целочисл перем символьного типа
	if ((d = getchar()) != '\n') // считываем отдельные символы, пока не получу Enter
	{		
		if (d<='9' && d >= '0')
		{
			printf("%u ", d - 0x30); //вывожу число соотв данному символу
		}
		
		get_digit(); // углубляюсь, чтобы считать следующий символ
	}
	return;
}
