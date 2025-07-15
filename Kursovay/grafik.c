// Ф-ции реализации графика

#include "temp_function.h" 

// график среднегодовых температур
void GrapYear(t_sensor info[], uint32_t size)
{
	SortDateUpArr(info, size);
	uint16_t max_y =info[size-1].year, min_y = info[0].year;
	uint16_t dx = (max_y - min_y)/X;
	int8_t line = 0;
	int8_t max_t = MaxTemp(info, size);
	
	clear();
	printf("График средних температур (если в файле 1 год, то покажет среднюю температуру за весь год)\n");
	
	for (uint32_t y = 0; y <= Y; y++)
	{
		(y==(Y/2)) ? printf("0") : printf("|");
		
		for (uint32_t x = 0; x < X; x++)
		{
			uint16_t year = min_y + x*dx;
			line = (Mid_Y(info, size, year)*(Y/2))/max_t;
			
			(y==(Y/2)) ? ((y == ((Y/2) - line)) ? printf("*") : printf("-")) : ((y == ((Y/2) - line)) ? printf("*") : printf(" ")); // чтобы отрисовалось хорошо
			(y==(Y/2)) ? (printf("-"), printf("-")): (printf(" "), printf(" "));
		}
		printf("\n");
		
		if(y == Y)
		{
			for (uint32_t x = 0; x < X; x++)
			{
				if(x == 0)
					printf("|");
				
				printf("|--");
			}
			printf(">\n");
		}
	}
	printf("\nмасштаб: \t|  -  %"PRId8"*\n\t\t|--|  -  %"PRIu16"год (если год один, то вся горизонталь - один год)\n*График приблизительный, служит только для визуализации\n", max_t/(Y/2), dx);
}

// график среднемесячных температур
void GrapMonth(t_sensor info[], uint32_t size, int *flag)
{
	SortDateUpArr(info, size);
	int8_t line = 0;
	int8_t max_t = MaxTemp(info, size);
	uint16_t year = 0;
	
	clear();
	printf("График средних месячных температур\n"); 
	
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
			return;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = info[size-1].year; // возвращает текущий год
	}
	
	
	for (uint32_t y = 0; y <= Y; y++)
	{
		(y==(Y/2)) ? printf("0") : printf("|");
		
		for (uint32_t x = 0; x < X; x++)
		{
			line = (Mid_M(info, size, year, x+1)*(Y/2))/max_t;
			
			(y==(Y/2)) ? ((y == ((Y/2) - line)) ? printf("*") : printf("-")) : ((y == ((Y/2) - line)) ? printf("*") : printf(" ")); // чтобы отрисовалось хорошо
			(y==(Y/2)) ? (printf("-"), printf("-")): (printf(" "), printf(" "));
		}
		printf("\n");
		
		if(y == Y)
		{
			for (uint32_t x = 0; x < X; x++)
			{
				if(x == 0)
					printf("|");
				
				printf("|--");
			}
			printf(">\n");
		}
	}
	printf("\nмасштаб: \t|  -  %"PRId8"гр\n\t\t|--|  -  %"PRIu16"мес\n*График приблизительный, служит только для визуализации\n", max_t/(Y/2), 1);
}

// график предельных температур всех годов
void GrapYearLim(t_sensor info[], uint32_t size)
{
	SortDateUpArr(info, size);
	uint16_t max_y = info[size-1].year, min_y = info[0].year;
	uint16_t dx = (max_y - min_y)/X;
	int8_t line_max = 0, line_min = 0;
	int8_t max_t = MaxTemp(info, size);
	
	clear();
	 printf("График предельных температур (если в файле 1 год, то покажет максимум и минимум)\n");
	
	for (uint32_t y = 0; y <= Y; y++)
	{
		(y==(Y/2)) ? printf("0") : printf("|");
		
		for (uint32_t x = 0; x < X; x++)
		{
			uint16_t year = min_y + x*dx;
			line_max = (MaxYear(info, size, year)*(Y/2))/max_t;
			line_min = (MinYear(info, size, year)*(Y/2))/max_t;
			
			if(y==(Y/2))
			{
				(y == ((Y/2) - line_max)) ? printf("*") : ((y == ((Y/2) - line_min)) ? printf("*") : printf("-"));
			}
			else
			{
				(y == ((Y/2) - line_max)) ? printf("*") : ((y == ((Y/2) - line_min)) ? printf("*") : printf(" "));
			}
			
			(y==(Y/2)) ? (printf("-"), printf("-")): (printf(" "), printf(" "));
		}
		printf("\n");
		
		if(y == Y)
		{
			for (uint32_t x = 0; x < X; x++)
			{
				if(x == 0)
					printf("|");
				
				printf("|--");
			}
			printf(">\n");
		}
	}
	printf("\nмасштаб: \t|  -  %"PRId8"*\n\t\t|--|  -  %"PRIu16" (если год один, то вся горизонталь - один год)\n*График приблизительный, служит только для визуализации\n", max_t/(Y/2), dx);
}

// график предельных температур в году
void GrapMonthLim(t_sensor info[], uint32_t size, int *flag)
{
	SortDateUpArr(info, size);
	int8_t line_max = 0, line_min = 0;
	int8_t max_t = MaxTemp(info, size);
	uint16_t year = 0; 
	
	clear();
	printf("График предельных месячных температур года\n");
	
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
			return;
		}
		printf("\n");
	}
	else
	{
		// "текущий"  определяю, как максимальное переданое значение (год, месяц, день и т.д.)
		year = info[size-1].year; // возвращает текущий год
	}
	
	for (uint32_t y = 0; y <= Y; y++)
	{
		(y==(Y/2)) ? printf("0") : printf("|");
		
		for (uint32_t x = 0; x < X; x++)
		{
			line_max = (MaxMonth(info, size, year, x+1)*(Y/2))/max_t;
			line_min = (MinMonth(info, size, year, x+1)*(Y/2))/max_t;
			
			if(y==(Y/2))
			{
				(y == ((Y/2) - line_max)) ? printf("*") : ((y == ((Y/2) - line_min)) ? printf("*") : printf("-"));
			}
			else
			{
				(y == ((Y/2) - line_max)) ? printf("*") : ((y == ((Y/2) - line_min)) ? printf("*") : printf(" "));
			}
			
			(y==(Y/2)) ? (printf("-"), printf("-")): (printf(" "), printf(" "));
		}
		printf("\n");
		
		if(y == Y)
		{
			for (uint32_t x = 0; x < X; x++)
			{
				if(x == 0)
					printf("|");
				
				printf("|--");
			}
			printf(">\n");
		}
	}
	printf("\nмасштаб: \t|  -  %"PRId8"гр\n\t\t|--|  -  %"PRIu16"мес\n*График приблизительный, служит только для визуализации\n", max_t/(Y/2), 1);
}


// ф-ция расчета среднего за год
int64_t Mid_Y(t_sensor info[], uint32_t size, uint16_t year)
{
	uint32_t j = 0;
	int64_t mid_t = 0;
	for (uint32_t i = 0; i < size; i++)
	{
		// если год нужный
		if(info[i].year == year)
		{
			mid_t += info[i].temp;
			j++;
		}
	}
	mid_t = mid_t/j;
	return mid_t;
}

// ф-ция поиска максимума
 int8_t MaxTemp(t_sensor info[], uint32_t size)
{
	int8_t max_t=0;
	int8_t min_t=127;
	
	for(uint32_t i = 0; i < size; i++)
	{
		if(info[i].temp > max_t)
		{
			max_t = info[i].temp;
			//~ max_i = i;
		}
		
		if(info[i].temp < min_t)
		{
			min_t = info[i].temp;
		}
	}
	min_t = min_t > 0 ? min_t : -min_t;
	max_t = max_t > min_t ? max_t : min_t;
	
	return max_t;
}

// ф-ция поиска среднего за месяц года
int64_t Mid_M(t_sensor info[], uint32_t size, uint16_t year, uint16_t month)
{
	uint32_t j = 0;
	int64_t mid_t = 0;
	for (uint32_t i = 0; i < size; i++)
	{
		// если год нужный
		if((info[i].year == year) && (info[i].month == month))
		{
			mid_t += info[i].temp;
			j++;
		}
	}
	mid_t = mid_t/j;
	return mid_t;
}

// ф-ция поиска максимума года
int8_t MaxYear(t_sensor info[], uint32_t size, uint16_t year)
{
	int8_t max_t = 0;
	for (uint32_t i = 0; i < size; i++)
	{
		// если год нужный, а температура больше максимума
		if((info[i].year == year) && (info[i].temp > max_t))
		{
			max_t = info[i].temp; 
		}
	}
	
	return max_t;
}

// ф-ция поиска минимума года
int8_t MinYear(t_sensor info[], uint32_t size, uint16_t year)
{
	int8_t min_t = 127;
	for (uint32_t i = 0; i < size; i++)
	{
		// если год нужный, а температура больше максимума
		if((info[i].year == year) && (info[i].temp < min_t))
		{
			min_t = info[i].temp; // меняю макс индекс
		}
	}
	
	return min_t;
}

// ф-ция поиска максимума месяца
int8_t MaxMonth(t_sensor info[], uint32_t size, uint16_t year, uint16_t month)
{
	int8_t max_t = -128;
	for (uint32_t i = 0; i < size; i++)
	{
		// если год нужный, а температура больше максимума
		if((info[i].year == year) && (info[i].month == month) && (info[i].temp > max_t))
		{
			max_t = info[i].temp; 
		}
	}
	
	return max_t;
}

// ф-ция поиска минимума месяца
int8_t MinMonth(t_sensor info[], uint32_t size, uint16_t year, uint16_t month)
{
	int8_t min_t = 127;
	for (uint32_t i = 0; i < size; i++)
	{
		// если год и месяц нужные, а температура больше максимума
		if((info[i].year == year) && (info[i].month == month) && (info[i].temp < min_t))
		{
			min_t = info[i].temp; 
		}
	}
	
	return min_t;
}
