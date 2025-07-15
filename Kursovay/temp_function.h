// Все необходимые заголовки

// библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <inttypes.h>
#include <locale.h>

// подстановки
#define pack 6 // кол-во данных передаваемых за раз
#define err -1 // для ошибок

// график
#define X 12
#define Y 20



// тип данных для хранения данных с датчика температуры
#pragma pack(push, 1) // это чтобы выровнять структуру
struct sensor
{
	uint16_t year; // гггг
	uint8_t month; // мм
	uint8_t day; // дд
	uint8_t hour; // чч
	uint8_t minutes; // мм
	int8_t temp; // тт
};
#pragma pack(pop)

// для краткости даем псевдоним
typedef struct sensor t_sensor;

// прототипы
FILE *AddFile(uint32_t *size, uint8_t opt, char filename[200]);
void FillArr(FILE *f, t_sensor info[], uint32_t size);
void FillFile(t_sensor info[], uint32_t size);
void menu(t_sensor info[], uint32_t size);
void clear();


void AddEntryHand();
void AddEntryAuto();
void DellEntry();

int64_t MaxYearT(t_sensor info[], uint32_t size, int *flag);
int64_t MinYearT(t_sensor info[], uint32_t size, int *flag);
float MidYearT(t_sensor info[], uint32_t size, int *flag);

int64_t MaxMonthT(t_sensor info[], uint32_t size, int *flag);
int64_t MinMonthT(t_sensor info[], uint32_t size, int *flag);
float MidMonthT(t_sensor info[], uint32_t size, int *flag, uint8_t *month);

void OutDataCons(t_sensor info[], uint32_t size);
void OutAllStatCons(t_sensor info[], uint32_t size);

uint16_t SortTempUpArr(t_sensor info[], uint32_t size);
uint16_t SortTempDownArr(t_sensor info[], uint32_t size);
uint16_t SortDateUpArr(t_sensor info[], uint32_t size);
uint16_t SortDateDownArr(t_sensor info[], uint32_t size);

void GrapYear(t_sensor info[], uint32_t size);
void GrapMonth(t_sensor info[], uint32_t size, int *flag);
void GrapYearLim(t_sensor info[], uint32_t size);
void GrapMonthLim(t_sensor info[], uint32_t size, int *flag);

int64_t Mid_Y(t_sensor info[], uint32_t size, uint16_t year);
int64_t Mid_M(t_sensor info[], uint32_t size, uint16_t year, uint16_t month);
int8_t MaxTemp(t_sensor info[], uint32_t size);
int8_t MinYear(t_sensor info[], uint32_t size, uint16_t year);
int8_t MaxYear(t_sensor info[], uint32_t size, uint16_t year);
int8_t MinMonth(t_sensor info[], uint32_t size, uint16_t year, uint16_t month);
int8_t MaxMonth(t_sensor info[], uint32_t size, uint16_t year, uint16_t month);
