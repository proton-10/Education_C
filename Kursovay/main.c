// Стастистика температуры

#include "temp_function.h" 

// основная ф-ция
int main(int argc, char **argv)
{
	// Приветствие
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("----------------------------------------------------------------\n");
	printf("Программа обработки данных от датчика температуры из файла!\n");
	char filename[200] = {0};
	uint16_t year = 0;
	uint8_t month = 0;
	filename[0] = '*'; // чтобы знать ввели ли мы через командную строку
	
	for (int i = 1; i < argc; i++)
	{
		char *str = argv[i];
		if(str[0] == '-')
		{
			switch (str[1])
			{
				case 'H':
				case 'h':
				{
					printf("\nОписание:\nПрограмма обрабатывает данные с датчика температуры из файла csv.\nМожет построить графики, вывести статистику по отдельному месяцу или году!\n\n");
					printf("Атрибуты:\n");
					printf("-h Вывод описания функционала приложения и атрибутов командной строки.\n");
					printf("-f <filename.csv> Входной файл csv для обработки данных.\n");
					printf("-y <гггг> Вывести всю статистику только за указанный год.\n\t*В файле должены быть данные по всем месяцам года!\n");
					printf("-m <гггг/мм> Вывести всю статистику только за указанный год/месяц.\n");
					return 0;
				}break;
				
				case 'F':
				case 'f':
				{
					char *name = argv[i+1];
					if(name[0] != '-')
					{
						sscanf(argv[i+1], "%s", filename);
						printf("%s\n", filename);
					}
				}break;
				
				case 'Y':
				case 'y':
				{
					sscanf(argv[i+1], "%"SCNu16, &year);
				}break;
				
				case 'M':
				case 'm':
				{
					sscanf(argv[i+1], "%"SCNu16" / %"SCNu8, &year, &month);
				}break;
			
			}
		}
	}
	
	uint32_t size = 0;
	FILE *f = AddFile(&size, '1', filename); // открываю файл, получаю его адрес и размер массива под него
	
	if(f == NULL) // если файл не открылся
	{
		return 1; // завершаем с ошибкой
	}
	
	t_sensor *s_info = malloc(size*sizeof(t_sensor)); // создаю массив структур, ровно под количество данных
	
	if (s_info != NULL) // получилось выделить память
	{
		FillArr(f, s_info, size); // заполняю массив
	}
	else
	{
		printf("Не удалось выделить память для массива структур");
		return 1;
	}
	
	if(year != 0 && month == 0)
	{
		OutAllStatCons(s_info, size); printf("\nВывод данных за %"SCNu8"/%"SCNu16" завершен!\n", month, year); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch();
		return 0;
	}
	else if(year != 0 && month != 0)
	{
		printf("!!!!!!!!!!!!!!!!!!!!!!\n\nДанные за %"SCNu8"/%"SCNu16":\n\n", month, year);
		printf("Tмакс = %"PRId8"; ", MaxMonth(s_info, size, year, month));
		printf("Tмин = %"PRId8"; ", MinMonth(s_info, size, year, month));
		printf("Tср = %"PRId64";\n\n", Mid_M(s_info, size, year, month));
		return 0;
	}
	
	// вызов основного меню
	menu(s_info, size);
	
	
	// завершение работы
	printf("\nВсего доброго! \n\n");
	printf("Нажмите любую клавишу для завершения программы >>");
	getch();
	
	return 0;
}
