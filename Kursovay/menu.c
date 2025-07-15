// Реализация ф-ции меню

#include "temp_function.h"

// прототипы вспомогательных ф-ций
static void select(uint16_t *choice);

// ф-ция пользовательского меню
void menu(t_sensor info[], uint32_t size)
{
	uint16_t choice=0;
		
	printf("\nВаш файл был успешно обработан!\n\n");
	printf("\t\tПродолжим?\n\n");
	printf("Чтобы показать серьезность намерений нажмите Пробел!\n>>");
	
	if(getch() == ' ')
	{
		while(1)
		{
			switch (choice)
			{
				// стартовое меню
				case 0: { clear(); printf("\n1. Вывод данных\n2. Сортировка данных\n3. Изменение файла\n4. Закрыть программу\n\n"); select(&choice); } break;
				
				// вывод
				case 1: { clear(); printf("\n1. Данные по годам\n2. Данные по месяцам\n3. Графики\n4. Вывести все\n5. Вернуться\n\n"); select(&choice); } break;
				
				// вывод по годам
				case 11: { clear(); printf("\n1. Максимальная температура за год\n2. Минимальная температура за год\n3. Средняя температура за год\n4. Вернуться\n\n"); select(&choice); } break;
				
				case 111: 
				case 112: 
				case 113: { clear(); printf("\n1. Текущий год\n2. Ввести вручную\n3. Вернуться\n\n*Текущий - наибольшая дата в файле\n\n"); select(&choice); } break;
				
				// вывод макс темп за год
				case 1111: { clear(); int flag = 0; int64_t i = MaxYearT(info, size, &flag); printf("В %04"PRIu16" году: Tмакс = %"PRId8"*C\n", info[i].year, info[i].temp); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				case 1112: { clear(); int flag = 1; int64_t i = MaxYearT(info, size, &flag); if(flag!=0) { printf("В %04"PRIu16" году: Tмакс = %"PRId8"*C\n", info[i].year, info[i].temp); } printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				
				// вывод мин темп за год
				case 1121: { clear(); int flag = 0; int64_t i = MinYearT(info, size, &flag); printf("В %04"PRIu16" году: Tмин = %"PRId8"*C\n", info[i].year, info[i].temp); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				case 1122: { clear(); int flag = 1; int64_t i = MinYearT(info, size, &flag); if(flag!=0) { printf("В %04"PRIu16" году: Tмин = %"PRId8"*C\n", info[i].year, info[i].temp); } printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				
				// вывод средней темп за год
				case 1131: { clear(); int flag = 0; float t = MidYearT(info, size, &flag); printf("В %04"PRIu16" году: Tср = %.1lf*C\n", info[0].year, t); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				case 1132: { clear(); int flag = 1; float t = MidYearT(info, size, &flag); if(flag!=0) { printf("В %04"PRIu16" году: Tср = %.1lf*C\n", info[0].year, t); } printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				
				// вывод по месяцам
				case 12: { clear(); printf("\n1. Максимальная температура за месяц\n2. Минимальная температура за месяц\n3. Средняя температура за месяц\n4. Вернуться\n\n"); select(&choice); } break;
				
				case 121:
				case 122:
				case 123: { clear(); printf("\n1. Текущий месяц\n2. Ввести вручную\n3. Вернуться\n\n*Текущий - наибольшая дата в файле\n\n"); select(&choice); } break;
				
				// вывод макс темп за месяц
				case 1211: { clear(); int flag = 0; int64_t i = MaxMonthT(info, size, &flag); printf("В %02"PRIu8"/%04"PRIu16"г.: Tмакс = %"PRId8"*C\n", info[i].month, info[i].year, info[i].temp); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				case 1212: { clear(); int flag = 1; int64_t i = MaxMonthT(info, size, &flag); if(flag!=0) { printf("В %02"PRIu8"/%04"PRIu16"г.: Tмакс = %"PRId8"*C\n", info[i].month, info[i].year, info[i].temp); } printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				
				// вывод мин темп за месяц
				case 1221: { clear(); int flag = 0; int64_t i = MinMonthT(info, size, &flag); printf("В %02"PRIu8"/%04"PRIu16"г.: Tмин = %"PRId8"*C\n", info[i].month, info[i].year, info[i].temp); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				case 1222: { clear(); int flag = 1; int64_t i = MinMonthT(info, size, &flag); if(flag!=0) { printf("В %02"PRIu8"/%04"PRIu16"г.: Tмин = %"PRId8"*C\n", info[i].month, info[i].year, info[i].temp); } printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				
				// вывод средней темп за месяц
				case 1231: { clear(); uint8_t month = 0; int flag = 0; float t = MidMonthT(info, size, &flag, &month); printf("В %02"PRIu8"/%04"PRIu16"г.: Tср = %.1lf*C\n", month, info[0].year, t); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				case 1232: { clear(); uint8_t month = 0; int flag = 1; float t = MidMonthT(info, size, &flag, &month); if(flag!=0) { printf("В %02"PRIu8"/%04"PRIu16"г.: Tср = %.1lf*C\n", month, info[0].year, t); } printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break;
				
				case 13:  { clear(); printf("\n1. График средних годовых температур\n2. График средних месячных температур года\n3. График предельных температур года\n4. График предельных месячных температур года\n5. Вернуться\n\n"); select(&choice); } break;
				
				case 131: { clear(); GrapYear(info, size); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break; // График средних годовых температур
				case 133: { clear(); GrapYearLim(info, size); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break; // График годовых предельных температур
				
				case 132: 
				case 134: { clear(); printf("\n1. Текущий год\n2. Ввести вручную\n3. Вернуться\n\n*Текущий - наибольшая дата в файле\n\n"); select(&choice); } break;
				
				case 1321: { clear(); int flag = 0; GrapMonth(info, size, &flag); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break; // график средних месячных температур года
				case 1322: { clear(); int flag = 1; GrapMonth(info, size, &flag); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break; // График средних месячных температур года
				case 1341: { clear(); int flag = 0; GrapMonthLim(info, size, &flag); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break; // График предельных месячных температур года
				case 1342: { clear(); int flag = 1; GrapMonthLim(info, size, &flag); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0; } break; // График предельных месячных температур года
				
				case 14: { clear(); printf("\n1. Вывод всей статистики\n2. Ввод всех данных\n3. Вернуться\n\n*Текущий - наибольшая дата в файле\n\n"); select(&choice); } break; // вывод всего // как файл и как массив
				
				// вывод в консоль
				case 141: { clear(); OutAllStatCons(info, size); printf("\nВывод данных завершен!\n"); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0;} break; // вывод всего
				case 142: { clear(); OutDataCons(info, size); printf("\nВывод данных завершен!\n"); printf("\nНажмите любую кнопку чтобы продолжить >> "); getch(); choice = 0;} break; // вывод всего
				
				// сортировка
				case 2: { clear(); printf("\n1. Сортировать по температуре\n2. Сортировать по дате\n3. Вернуться\n\n"); select(&choice); } break;
				
				// сорт по темп
				case 21: { clear(); printf("\n1. По возрастанию температуры\n2. По убыванию температуры\n3. Вернуться\n\n"); select(&choice); } break;
				
				case 211:{ clear(); SortTempUpArr(info, size); printf("Сортировка массива выполнена!\n");  printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; // сорт по возр температуры
				case 212:{ clear(); SortTempDownArr(info, size); printf("Сортировка массива выполнена!\n");  printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; // сорт по убыванию температуры
				
				// сорт по дате
				case 22: { clear(); printf("\n1. По возрастанию\n2. По убыванию\n3. Вернуться\n\n"); select(&choice); } break;
				
				case 221: { clear(); SortDateUpArr(info, size); printf("Сортировка массива выполнена!\n"); printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; // сорт по возр даты
				case 222: { clear(); SortDateDownArr(info, size); printf("Сортировка массива выполнена!\n"); printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; //  сорт по уб даты
				
				// изм файла
				case 3: { clear(); printf("\n1. Добавить запись\n2. Удалить запись\n3. Создать новый файл из текущего массива\n4. Вернуться\n\n"); select(&choice); } break;
				
				
				case 31: { clear(); printf("\n1. Добавить из другого файла\n2. Ввести вручную\n3. Вернуться\n\n"); select(&choice); } break;
				
				case 311: { clear(); AddEntryAuto(); printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; // добавить запись в файл вручную
				case 312: { clear(); AddEntryHand(); printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; // добавить запись в файл из файла
				case 32: { clear(); DellEntry(); printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break;// удалить запись из файла
				case 33: { clear(); FillFile(info, size); printf("\nНажмите любую кнопку чтобы продолжить >>"); getch(); choice = 0;} break; // создаем новый файл
				
				// закрыть прог
				case 4: { choice = 0; } return;
				
				// вернуться к 0.
				case 15:
				case 23:
				case 34: { choice = 0; } break;
				
				// вернуть к 1.
				case 114:  
				case 124: 
				case 135: 
				case 143: { choice = 1; } break;
				
				// вернуться к 2.
				case 213: 
				case 223: {choice = 2; } break;
				
				// вернуться к 3
				case 313: {choice = 3; } break;
				
				// вернуться к 1.1.
				case 1113:
				case 1123:
				case 1133:
				case 1143: { choice = 11; } break;
				
				// вернуться к 1.2.
				case 1213: 
				case 1223:
				case 1233:
				case 1243: { choice = 12; } break;
				
				// вернуться к 1.3.
				case 1323:
				case 1343: { choice = 13; } break;
				
				// сказать что ввод неправильный, нажмите, чтобы попробовать еще раз
				default: { choice = 0; } break;
			}
		}
	}
	else
	{
		printf("Вы не настроены серьезно!");
		return;
		// закрыть программу
	}
}



// ф-ция очистки консоли
void clear()
{
	system("cls"); // очищаю экран
	return;
}

// ф-ция выбора параметров меню
static void select(uint16_t *choice)
{
	uint8_t i = 0;
	
	printf(">> ");
	i = getch();
	
	if(i >= 0x30 && i <= 0x39)
	{
		i = i - 0x30;
		(*choice) = (*choice)*10 + i; // общий код
	}
	else
	{
		(*choice) = 9;// если считали не то
	}
	printf("\n");
	return;
}
