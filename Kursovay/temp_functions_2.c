// Реализация ф-ций

#include "temp_function.h" 

// прототипы вспомогательных ф-ций
static void change_ij(t_sensor info[], int i, int j);
static uint64_t DateInNum(t_sensor info[], int i);
static void MyQsortDate(t_sensor info[], uint32_t L, uint32_t R);
static void MyQsortTemp(t_sensor info[], uint32_t L, uint32_t R);


// ф-ция поиска макс темп за год
int64_t MaxYearT(t_sensor info[], uint32_t size, int *flag)
{
	uint32_t max_t = 0; // индекс макс температуры
	uint32_t i = 0;
	uint16_t year = 0;
	
	// если хочу выбрать год
	if(*flag == 1)
	{
		printf("Укажите год >> ");
		if (scanf("%4"SCNu16, &year) != 1)
		{
			for (; getchar() != '\n';) // очищаю буфер
			{}
			printf("Необходим формат -  _ _ _ _ г.\n");
			*flag = 0;
			return 0;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = SortDateDownArr(info, size); // возвращает текущий год
	}
	
	if(year >= SortDateUpArr(info, size) && year <= SortDateDownArr(info, size)) // проверяю есть ли такой год
	{
		for (; i < size; i++)
		{
			// если год нужный, а температура больше максимума
			if((info[i].year == year) && (info[i].temp > info[max_t].temp))
			{
				max_t = i; // меняю макс индекс
			}
		}
	}
	else
	{
		printf("Данные за выбраный год в файле не обнаружены!\n");
		*flag = 0;
		return 0;
	}
	
	return max_t; // возвращаю индекс элемента с максимальной температурой
}

// ф-ция поиска мин темп за год
int64_t MinYearT(t_sensor info[], uint32_t size, int *flag)
{
	int32_t min_t = 0; // индекс макс температуры
	uint32_t i = 0;
	uint16_t year = 0;
	
	// если хочу выбрать год
	if(*flag == 1)
	{
		printf("Укажите год >> ");
		if (scanf("%4"SCNu16, &year) != 1)
		{
			for (; getchar() != '\n';) // очищаю буфер
			{}
			printf("Необходим формат -  _ _ _ _ г.\n");
			*flag = 0;
			return 0;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = SortDateDownArr(info, size); // возвращает текущий год
	}
	
	if(year >= SortDateUpArr(info, size) && year <= SortDateDownArr(info, size)) // проверяю есть ли такой год
	{
		for (; i < size; i++)
		{
			// если год нужный, а температура меньше минимальной
			if((info[i].year == year) && (info[i].temp < info[min_t].temp))
			{
				min_t = i; // меняю мин индекс
			}
		}
	}
	else
	{
		printf("Данные за выбраный год в файле не обнаружены!\n");
		*flag = 0;
		return 0;
	}
	
	return min_t; // возвращаю индекс элемента с максимальной температурой
}

// ф-ция поиска средней темп за год
float MidYearT(t_sensor info[], uint32_t size, int *flag)
{
	float mid_t = 0; // средняя температуры
	uint32_t j = 0; // счетчик цикла
	uint16_t year = 0;
	
	// если хочу выбрать год
	if(*flag == 1)
	{
		printf("Укажите год >> ");
		if (scanf("%4"SCNu16, &year) != 1)
		{
			for (; getchar() != '\n';) // очищаю буфер
			{}
			
			printf("Необходим формат -  _ _ _ _ г.\n");
			*flag = 0;
			return 0;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = SortDateDownArr(info, size); // возвращает текущий год
	}
	
	if(year >= SortDateUpArr(info, size) && year <= SortDateDownArr(info, size)) // проверяю есть ли такой год
	{
		for (uint32_t i = 0; i < size; i++)
		{
			// если год нужный
			if(info[i].year == year)
			{
				mid_t += info[i].temp; // сумирую температуры как вещ числа
				j++;
			}
		}
		mid_t = (float) mid_t/j;
	}
	else
	{
		printf("Данные за выбраный год в файле не обнаружены!\n");
		*flag = 0;
	}
	
	return mid_t; // возвращаю среднюю темп как целое число
}


// ф-ция поиска макс темп за месяц
int64_t MaxMonthT(t_sensor info[], uint32_t size, int *flag)
{
	uint32_t max_t = 0; // индекс макс температуры
	uint32_t i = 0;
	uint16_t year = 0;
	uint8_t month = 0;
	
	// если хочу выбрать год
	if(*flag == 1)
	{
		printf("Введите месяц и год!\nФормат: мм.гггг.\n>> ");
		if (scanf("%2"SCNu8".%4"SCNu16".", &month, &year) != 2)
		{
			for (; getchar() != '\n';) // очищаю буфер
			{}
			printf("Необходим формат -  _ _ м. _ _ _ _ г.\n");
			*flag = 0;
			return 0;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = SortDateDownArr(info, size); // возвращает текущий год
		month = info[0].month; // после сортировки в 0-ом элемент имеет максимальную дату
	}
	
	if(year >= SortDateUpArr(info, size) && year <= SortDateDownArr(info, size) && month > 0 && month <= 12) // проверяю корректность даты
	{
		for (; i < size; i++)
		{
			// если год и месяц нужные,а температура больше максимума
			if((info[i].year == year) && (info[i].month == month) && (info[i].temp > info[max_t].temp))
			{
				max_t = i; // меняю макс индекс
			}
		}
	}
	else
	{
		printf("Данные за выбраный период в файле не обнаружены!\n");
		*flag = 0;
		return 0;
	}
	
	return max_t; // возвращаю индекс элемента с максимальной температурой
}

// ф-ция поиска мин темп за месяц
int64_t MinMonthT(t_sensor info[], uint32_t size, int *flag)
{
	int32_t min_t = 0; // индекс макс температуры
	uint32_t i = 0;
	uint16_t year = 0;
	uint8_t month = 0;
	
	// если хочу выбрать год
	if(*flag == 1)
	{
		printf("Введите месяц и год!\nФормат: мм.гггг.\n>> ");
		if (scanf("%2"SCNu8 "%4"SCNu16, &month, &year) != 2)
		{
			for (; getchar() != '\n';) // очищаю буфер
			{}
			printf("Необходим формат -  _ _ м. _ _ _ _ г.\n");
			*flag = 0;
			return 0;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = SortDateDownArr(info, size); // возвращает текущий год
		month = info[0].month; // после сортировки в 0-ом элемент имеет максимальную дату
	}
	
	if(year >= SortDateUpArr(info, size) && year <= SortDateDownArr(info, size) && month > 0 && month <= 12) // проверяю корректность даты
	{
		for (; i < size; i++)
		{
			// если год и месяц нужные, а температура меньше минимальной
			if((info[i].year == year) && (info[i].month == month) && (info[i].temp < info[min_t].temp))
			{
				min_t = i; // меняю мин индекс
			}
		}
	}
	else
	{
		printf("Данные за выбраный период в файле не обнаружены!\n");
		*flag = 0;
		return 0;
	}
	
	return min_t; // возвращаю индекс элемента с максимальной температурой
}

// ф-ция поиска средней темп за месяц
float MidMonthT(t_sensor info[], uint32_t size, int *flag, uint8_t *month)
{
	float mid_t = 0; // средняя температуры
	uint32_t j = 0; // счетчик цикла
	uint16_t year = 0;
	
	// если хочу выбрать год
	if(*flag == 1)
	{
		printf("Введите месяц и год!\nФормат: мм.гггг.\n>> ");
		if (scanf("%2"SCNu8 "%4"SCNu16, month, &year) != 2)
		{
			for (; getchar() != '\n';) // очищаю буфер
			{}
			printf("Необходим формат -  _ _ м. _ _ _ _ г.\n");
			*flag = 0;
			return 0;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = SortDateDownArr(info, size); // возвращает текущий год
		*month = info[0].month; // после сортировки в 0-ом элемент имеет максимальную дату
	}
	
	if(year >= SortDateUpArr(info, size) && year <= SortDateDownArr(info, size) && *month > 0 && *month <= 12) // проверяю корректность даты
	{
		for (uint32_t i = 0; i < size; i++)
		{
			// если год и месяц нужные
			if((info[i].year == year) && (info[i].month == *month))
			{
				mid_t += info[i].temp; // сумирую температуры как вещ числа
				j++;
			}
		}
		mid_t = (float) mid_t/j;
	}
	else
	{
		printf("Данные за выбраный период в файле не обнаружены!\n");
		*flag = 0;
	}
	
	return mid_t; // возвращаю среднюю темп как целое число
}



// ф-ция вывода массива в консоль // добавить в файл
void OutDataCons(t_sensor info[], uint32_t size)
{
	// флаг чтобы понять куда выводить в файл или в консоль
	
	char q = 0, s =0;
	uint8_t m = info[0].month;
	
	for (uint32_t i = 0; i < size; i++)
	{
		if((q != 'N' && q != 'n') && m != info[i].month) //если не просили "больше не спрашивать" и уже вывели инфу за месяц
		{
			printf("\nПродолжить вывод данных? (Y - да, N - нет)\n\nДанных выведено %"PRIu32"/%"PRIu32"\n>> ", i, size);
			s = getch(); // ввожу первый выбор
			
			switch (s)
			{
				// продолжаем вывод
				case 'y':
				case 'Y':
				{
					m = info[i].month;
					if((q != 'N' && q != 'n') && (q != 'Y' && q != 'y')) // если уже отвечал на вопрос снизу не вхожу
					{
						printf("\nБольше не спрашивать? (Y - спрашивать, N - не спрашивать)\n>> ");
						q = getch(); // отвечаю на вопрос
					}
				}break;
				
				// завершаем вывод
				case 'n':
				case 'N':
				{
					return;
				}break;
			
				default:
				{
					printf("Символ не распознан!\n");
					i--; // переспрошу на следующем шаге
				}break;
			}
		}
		
		// вывожу
		printf("%02"PRIu8"/%02"PRIu8"/%04"PRIu16"  %02"PRIu8":%02"PRIu8 " -> t=%3"PRId8";\n", info[i].day, info[i].month, info[i].year, info[i].hour, info[i].minutes, info[i].temp);
	}
	
}

// ф-ция вывода общей статистики
void OutAllStatCons(t_sensor info[], uint32_t size)
{
	SortDateDownArr(info, size);
	uint16_t year_max = info[0].year;
	uint16_t year_min = info[size-1].year;
	uint16_t year = year_min;
	uint8_t y_num = (year_max - year_min)+1;
	
	clear();
	
	for (uint32_t i = 0; i < y_num; i++)
	{
		year = year_min+i;
		printf("%04"PRIu32" год:\n", year);
		printf("Tмакс = %+03"PRId8"*C;  Tмин = %+03"PRId8"*C; Tср = %+03"PRId64"*C;\n\n", MaxYear(info, size, year), MinYear(info, size, year), Mid_Y(info, size, year));
		
		printf("  Дата  | Tмакс | Tмин  | Tср \n");

		for (uint8_t j = 1; j <= 12; j++)
		{
			printf("________|_______|_______|_______\n");
			printf("%02"PRIu8"/%04"PRIu32" | ", j, year);
			printf("%+03"PRId8"*C | %+03"PRId8"*C | %+03"PRId64"*C;\n", MaxMonth(info, size, year, j), MinMonth(info, size, year, j), Mid_M(info, size, year, j));
		}
	}
}



// ф-ция сортировки данных в массиве по возрастанию даты
uint16_t SortDateUpArr(t_sensor info[], uint32_t size)
{
	MyQsortDate(info, 0, (size-1)); // сортирую
	return info[0].year; // возвращаю минимальный год
}

// ф-ция сортировки данных в массиве по убыванию даты
uint16_t SortDateDownArr(t_sensor info[], uint32_t size)
{
	MyQsortDate(info, 0, (size-1)); // сортирую на возрастание
	
	// переворачиваю данные с ног на голову
	for (uint32_t i = 0; i < size/2; i++)
	{
		change_ij(info, i, ((size-1)-i)); 
	}
	
	return info[0].year; // возвращаю максимальный год
}

// ф-ция сортировки данных в массиве по возрастанию температуры
uint16_t SortTempUpArr(t_sensor info[], uint32_t size)
{
	MyQsortTemp(info, 0, (size-1)); // сортирую
	return info[0].temp; // возвращаю минимальную температу
}

// ф-ция сортировки данных в массиве по убыванию температуры
uint16_t SortTempDownArr(t_sensor info[], uint32_t size)
{
	MyQsortTemp(info, 0, (size-1)); // сортирую на возрастание
	
	// переворачиваю данные с ног на голову
	for (uint32_t i = 0; i < size/2; i++)
	{
		change_ij(info, i, ((size-1)-i)); 
	}
	
	return info[0].temp; // возвращаю максимальную температуру
}



// ф-ция добавлени записей в исходный файл вручную
void DellEntry()
{
	FILE *f = NULL, *ft = NULL; // создаю указатель на тип данных "файл"
	
	char filename[200] = {0}; // строка для имени файла // temperature_small.csv
	
	printf("Введите имя файла из которо удаляем: ");
		
	scanf("%s", filename); // считываю имя файла
	getchar(); // считываю символ ввода
	
	// открываю считаные файлы и запоминаю их адреса	
	f = fopen(filename, "r"); 
	ft = fopen("d.csv", "a+");
	
	// проверка открытия файла
	if (f != NULL && ft != NULL) // если файл открылся
	{
		fseek(f, 0, SEEK_END); // перевожу курсор в конец файла
		long int end = ftell(f);
		fseek(f, 0, SEEK_SET); // перевожу курсор в начало файла
		long int z = ftell(f); 
		
		uint32_t num = 0, j = 0;
		printf("Укажите номер строки, c которого нужно начать удаление: ");
		scanf("%"SCNu32, &j);
		printf("Укажите сколько удалить строк, начиная с %"PRIu32" стр: ", j);
		scanf("%"SCNu32, &num);
		
		for (uint32_t i = 1; z < end; i++)
		{
				// куда считываю
				uint16_t year = 0;
				uint8_t month = 0, day = 0, hour = 0, minutes = 0;
				int8_t temp = 0;
				
				int s = fscanf(f,"%4"SCNu16"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %3"SCNd8, &year, &month, &day, &hour, &minutes, &temp);
				
				if(s<pack) // если считали меньше 6 
				{
					fseek(f, 1, SEEK_CUR); // перемещаю курсов вперед на один символ
				}
				else if(i > ((j)+(num-1)) || i < (j))
				{
					fprintf(ft,"%04"PRIu16";%02"PRIu8";%02"PRIu8";%02"PRIu8";%02"PRIu8 ";%2"PRId8"\n", year, month, day, hour, minutes, temp); // заношу в файл
				}
				z = ftell(f); // смотрю текущую позицию
		}
		fclose(f);
		
		f = fopen(filename, "w");
		
		if(f == NULL)
		{
			printf("Удаление не удалось\n");
			return;
		}
		
		fseek(ft, 0, SEEK_END); // перевожу курсор в конец файла
		end = ftell(ft);
		fseek(ft, 0, SEEK_SET); // перевожу курсор в начало файла
		z = ftell(ft); 
		
		while(z < end) // пока не дойдем до конца
		{
			// куда считываю
			uint16_t year = 0;
			uint8_t month = 0, day = 0, hour = 0, minutes = 0;
			int8_t temp = 0;
			
			int s = fscanf(ft,"%4"SCNu16"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %3"SCNd8, &year, &month, &day, &hour, &minutes, &temp);
			
			if(s<pack) // если считали меньше 6 
			{
				fseek(f, 1, SEEK_CUR); // перемещаю курсов вперед на один символ
			}
			else
			{
				fprintf(f,"%04"PRIu16";%02"PRIu8";%02"PRIu8";%02"PRIu8";%02"PRIu8 ";%2"PRId8"\n", year, month, day, hour, minutes, temp); // заношу в файл
			}
			
			z = ftell(ft); // смотрю текущую позицию
		}
		
		// закрываю файлы
		fclose(f);
		fclose(ft);
		remove("d.csv"); // удаляю промежуточный файл
		
		printf("Запрошенные данные были стерты\n");
	}
	else
	{
		printf("\n!Невозможно открыть файл!\n\n");
		return;
	}
}

// ф-ция добавлени записей в исходный файл вручную
void AddEntryHand()
{
	FILE *f = NULL;// создаю указатель на тип данных "файл"
	char filename[200] = {0}; // строка для имени файла // temperature_small.csv
	
	printf("Введите имя файла: ");
		
	scanf("%s", filename); // считываю имя файла
	getchar(); // считываю символ ввода
	
	f = fopen(filename, "a+"); // открываю считаный файл и запоминаю его адрес
	
	// проверка открытия файла
	if (f != NULL) // если файл открылся
	{
		fseek(f, 0, SEEK_END); // перевожу курсор в конец файла
		
		uint8_t num = 0;
		printf("Укажите количество записей: ");
		scanf("%"SCNu8, &num);
		uint8_t i = 0;
		for(; i < num; i++)
		{
			uint16_t year = 0;
			uint8_t month = 0, day = 0, hour = 0, minutes = 0;
			int8_t temp = 0;
			
			printf("Введите строку в формате гггг; мм; дд; чч: мм; тт\n\n>> ");
		
			// ввожу
			int s = scanf("%4"SCNu16"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %3"SCNd8, &year, &month, &day, &hour, &minutes, &temp);
			
			if(s == 6)
			{ 
				// заношу в файл
				fprintf(f,"%04"PRIu16";%02"PRIu8";%02"PRIu8";%02"PRIu8";%02"PRIu8 ";%2"PRId8"\n", year, month, day, hour, minutes, temp);
				printf("\n");
			}
			else
			{
				printf("\nУказан неверный формат\n");
				printf("\nНажмите любую кнопку чтобы продолжить >>"); 
				getch();
				printf("\n");
				i--;
			}
		}
		printf("Успешно записано: %"PRIu8"/%"PRIu32" строк\n", i, num);
		fclose(f);
	}
	else
	{
		printf("\n!Невозможно открыть файл!\n\n");
		return;
	}
}

// ф-ция добавления записей в исходный файл из другого файла
void AddEntryAuto()
{
	FILE *f = NULL, *ft = NULL; // создаю указатель на тип данных "файл"
	
	char filename1[200] = {0}; // строка для имени файла // temperature_small.csv
	char filename2[200] = {0};
	
	printf("Введите имя файла, в который записываем: ");
		
	scanf("%s", filename1); // считываю имя файла
	getchar(); // считываю символ ввода
	
	printf("\n(Формат данных в файле должен быть: гггг; мм; дд; чч; мм; тт)\nВведите имя файла, из которого записываем: ");
	scanf("%s", filename2); // считываю имя файла
	getchar(); // считываю символ ввода
	
	// открываю считаные файлы и запоминаю их адреса	
	f = fopen(filename1, "a+"); 
	ft = fopen(filename2, "r+");
	
	// проверка открытия файла
	if (f != NULL && ft != NULL) // если файл открылся
	{
		uint32_t num = 0;
		printf("Укажите количество записей, которые нужно перенести: ");
		scanf("%"SCNu32, &num);
		
		fseek(f, 0, SEEK_SET); // перевожу курсор в начало файла f
		fseek(ft, 0, SEEK_END); // перевожу курсор в конец файла
		long int end = ftell(ft);
		fseek(ft, 0, SEEK_SET); // перевожу курсор в начало файла
		long int z = ftell(ft); 
		uint32_t i = 0;
		
		for (; z < end && i < num; i++)
		{
			// куда считываю
			uint16_t year = 0;
			uint8_t month = 0, day = 0, hour = 0, minutes = 0;
			int8_t temp = 0;
			
			int s = fscanf(ft,"%4"SCNu16"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %2"SCNu8"; %3"SCNd8, &year, &month, &day, &hour, &minutes, &temp);
			
			if(s<pack) // если считали меньше 6 
			{
				printf("1");
				fseek(ft, 1, SEEK_CUR); // перемещаю курсов вперед на один символ
				i--;
			}
			else
			{
				printf("2");
				// заношу в файл
				fprintf(f,"%04"PRIu16";%02"PRIu8";%02"PRIu8";%02"PRIu8";%02"PRIu8 ";%2"PRId8"\n", year, month, day, hour, minutes, temp);
			}
			z = ftell(ft); // смотрю текущую позицию
		}
		printf("Успешно записано: %"PRIu8"/%"PRIu32" строк\n", i, num);
		fclose(ft);
		fclose(f);
	}
	else
	{
		printf("\n!Невозможно открыть файлы!\n\n");
		return;
	}
}

// ф-ция создания копии массива в отдельный файл
void FillFile(t_sensor info[], uint32_t size)
{
	char filename[200] = {0};
	filename[0] = '*';
	FILE *new_f = AddFile(&size, '2', filename); // открываю новый файл
	if(new_f == NULL)
	{
		printf("Не удалось создать файл!\n");
		return;
	}
	else
	{
		for (uint32_t i = 0; i < size; i++)
		{
			fprintf(new_f,"%02"PRIu8"/%02"PRIu8"/%04"PRIu16"  %02"PRIu8":%02"PRIu8 " -> t=%3"PRId8";\n", info[i].day,  info[i].month,  info[i].year,  info[i].hour,  info[i].minutes,  info[i].temp);
		}
		fclose(new_f);
		printf("Файл был успешно создан!\n");
	}
	return;
}



// ф-ция изменения порядка
static void change_ij(t_sensor info[], int i, int j)
{
	// меняю местами i-й и j-й элементы, больший идет вниз
	t_sensor remember = info[i];
	info[i] = info[j];
	info[j] =remember;
}

// ф-ция перевода даты в число
static uint64_t DateInNum(t_sensor info[], int i)
{
	uint64_t date = ~1; // обнуляю все биты
	
	// через битовые операции записываю битовые поля в перем data
	date = (date | info[i].year) << 16;
	date = (date | info[i].month) << 8;
	date = (date | info[i].day) << 8;
	date = (date | info[i].hour) << 8;
	date = (date | info[i].minutes) << 8;
	
	return date; // возвращаю результат
}

// ф-ция реализующая алгоритм быстрой сортировки для полей даты
static void MyQsortDate(t_sensor info[], uint32_t L, uint32_t R)
{
	if(L<R) // если левый край массива и правый край не равны
	{
		uint64_t pivot = DateInNum(info, (L+R)/2); // в качестве опорного берем медианное значение
		uint32_t i = L, j = R; // счетчики
	
		while(i<j) // пока левый счетчик слева, а правый справа (от центра)
		{
			// чтобы вызвать эти ф-ции только раз за итерацию создаем им переменные
			uint64_t date_i = DateInNum(info, i), date_j = DateInNum(info, j); 
			
			// если дата слева меньше опорного
			if(date_i<pivot)
				i++; // идем к следующему значению
			
			// если дата справа больше опорного
			if(date_j > pivot)
				j--; // идем к следующему элементу
			
			
			// если левый больше, а правый меньше, то меняю их местами
			if((date_i >= pivot) && (date_j <= pivot) && i<=j) // i<=j - убеждаемся что не зашли на чужую територию
			{
				change_ij(info, i, j); // меняю
			}
		} // тут i <= j // от L до j значения меньше pivot, от i до R - больше
		
		if(j>L)
		{
			// вызываю опять, но правая граница - j - конец области где даты больше опорного
			MyQsortDate(info, L, j);
		}
		else return;
		
		if(i<R)
		{
			// вызываю опять, но левая граница - i - конец области где даты меньше опорного
			MyQsortDate(info, i, R);
		}else return;
	}
}

// ф-ция реализующая алгоритм быстрой сортировки для полей температуры
static void MyQsortTemp(t_sensor info[], uint32_t L, uint32_t R)
{
	if(L<R) // если левый край массива и правый край не равны
	{
		int8_t pivot = info[(L+R)/2].temp; // в качестве опорного берем медианное значение
		uint32_t i = L, j = R; // счетчики
	
		while(i<j) // пока левый счетчик слева, а правый справа (от центра)
		{
			// чтобы вызвать эти ф-ции только раз за итерацию создаем им переменные
			int8_t date_i = info[i].temp, date_j = info[j].temp;
			
			// если темп слева меньше опорного
			if(date_i < pivot)
				i++; // идем к следующему значению
			
			// если темп справа больше опорного
			if(date_j > pivot)
				j--; // идем к следующему элементу
			
			
			// если левый больше, а правый меньше, то меняю их местами
			if((date_i >= pivot) && (date_j <= pivot) && i<=j) // i<=j - убеждаемся, что не зашли на чужую територию
			{
				change_ij(info, i, j); // меняю
			}
		} // тут i <= j // от L до j значения меньше pivot, от i до R - больше
		
		if(j>L)
		{
			// вызываю опять, но правая граница - j - конец области где даты больше опорного
			MyQsortTemp(info, L, j);
		}
		else return;
		
		if(i<R)
		{
			// вызываю опять, но левая граница - i - конец области где даты меньше опорного
			MyQsortTemp(info, i, R);
		}else return;
	}
}
