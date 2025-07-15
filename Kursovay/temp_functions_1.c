// Реализация ф-ций

#include "temp_function.h" 

// прототипы вспомогательных ф-ций
static long int EndFile(FILE *f);
static void SizeFile(FILE *f,  uint32_t *size);


// ф-ция открытия файла
FILE *AddFile(uint32_t *size, uint8_t opt, char filename[200])
{
	
	FILE *f = NULL; // создаю указатель на тип данных "файл"
	
	if (filename[0] == '*') // если ввели имя файла через командную строку
	{
		if(opt == '1')
			printf("Введите имя файла: ");
		else if (opt == '2')
			printf("Придумайте имя файлу: ");
			
		scanf("%s", filename); // считываю имя файла
		getchar(); // считываю символ ввода
	}
	
	if(opt == '1')
	{
		f = fopen(filename, "r"); // открываю считаный файл и запоминаю его адрес
		
		// проверка открытия файла
		if (f != NULL) // если файл открылся
		{
			SizeFile(f, &(*size)); // считаю размер файла
		}
		else
		{
			printf("\n!Невозможно открыть файл!\n\n");
			return NULL;
		}
	}
	else if(opt == '2')
	{
		f = fopen(filename, "a+");
		// проверка открытия файла
		if (f == NULL) // если файл открылся
		{
			printf("\n!Невозможно создать файл!\n\n");
			return NULL;
		}
	}
	
	return f; // возвращаю указатель (адрес) на открытый файл
}

// ф-ция расчета размера файла
static long int EndFile(FILE *f)
{
	fseek(f, 0, SEEK_END); // перевожу курсор в конец файла
	const long int end_file = ftell(f); // переменная конца_файла
	fseek(f, 0, SEEK_SET); // перевожу курсор в начало
	
	return end_file;
}

// ф-ция вычисления размера массива под файл
static void SizeFile(FILE *f,  uint32_t *size)
{
	long int z = 0, end_file = EndFile(f); // позиция и конец файла
	
	for (uint32_t i = 0; z < end_file; i++)
	{
		// куда считываю
		uint16_t year = 0;
		uint8_t month = 0, day = 0, hour = 0, minutes = 0;
		int8_t temp = 0;
		
		// считываю для знакомства с файлом
		int s = fscanf(f,"%4"SCNu16"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %3"SCNd8, &year, &month, &day, &hour, &minutes, &temp);
		z = ftell(f); // смотрю текущую позицию
		
		if(s<pack) // если считали меньше 6 
		{
			fseek(f, 1, SEEK_CUR); // перемещаю курсов вперед на один символ
			i--; // не учитываем ошибочный шаг
		}
		else
		{
			(*size) += s; // увеличиваю при правильном чтении на 6
		}
	}
	
	*size = (*size)/pack; // сколько раз правильно считал 6 блоков
	return;
}

// ф-ция заполнения массива
void FillArr(FILE *f, t_sensor info[], uint32_t size)
{
	uint32_t er = 0; // для подсчета ошибок чтения
	long int z = 0, end_file = EndFile(f); // позиция и конец файла
	
	printf("\n\n!Ошибки найдены в строке №: ");
	for (uint32_t i = 0, k = 0; z < end_file; i++)
	{
		// заполняю поля массива структур и смотрю сколько считал данных
		int s = fscanf(f,"%4"SCNu16"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %3"SCNd8, &info[i].year, &info[i].month, &info[i].day, &info[i].hour, &info[i].minutes, &info[i].temp);
		z = ftell(f); // смотрю текущую позицию
		
		if(s<pack) // если считали меньше 6 
		{
			fseek(f, 1, SEEK_CUR); // перемещаю курсов вперед на один символ
			
			if(k == 0 && z != end_file)
			{
				printf("%"PRIu32" ", i+1);
				er++; // нашли ошибку
			}
			
			k++;
			i--; // не учитываем ошибочный шаг
		}
		else
			k=0;
	}
	
	printf ("\n\nСчитано: %ld байт\nОшибок чтения: %"PRIu32"\nКоличество элементов: %"PRIu32"\n\n", z, er, size);
	fclose(f); // закрываю файл
	return;
}
