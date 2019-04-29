#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의된 헤더 파일
#include <stdlib.h> //exit()를 사용하기 위한 헤더 파일

int calculateDayofStart(int year);
bool calculateFeb(int year);
int getTotalDaysOfMonth(int year, int month);
int getStartDayOfMonth(int year, int month);
void printType1(int year);
void printType2(int year, int month);
void printTitle();
void printCalender(int year, int month);

void main() {
	int inputType;
	int year;
	int month;

	printf("달력을 출력하는 프로그램 입니다.\n");
	printf("메뉴를 선택하세요.(1. -> 연도, 2 -> 연도와 월): ");
	scanf("%d", &inputType);

	if (inputType == 1) {
		printf("연를 입력하세요: ");
		scanf("%d", &year);
		printType1(year);
	}
	else if (inputType == 2) {
		printf("연과 월을 입력하세요: ");
		scanf("%d%d", &year, &month);
		printType2(year, month);
	}
	else {
		printf("(오류)메뉴에 없는 걸 선택해서 프로그램을 종료합니다.\n");
		exit(1); //에러시 강제 종료
	}
}

//그 해의 첫날의 요일 구하기
int calculateDayofStart(int year) {
	return ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
}

//윤년 계산 (2월)
bool calculateFeb(int year) {
	return (!(year % 4) && (year % 100)) || !(year % 400);
}

//해당 년도의 월의 마지막 날짜 구하기
int getTotalDaysOfMonth(int year, int month) {
	int totalDaysOfMonths = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		totalDaysOfMonths = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		totalDaysOfMonths = 30;
	else if (month == 2)
		if (calculateFeb(year))
			totalDaysOfMonths = 29;
		else
			totalDaysOfMonths = 28;

	return totalDaysOfMonths;
}

//해당 년도의 월의 시작 요일 구하기
//1:일요일 ~ 7:토요일 
int getStartDayOfMonth(int year, int month) {
	int startDayOfYear = calculateDayofStart(year);

	for (int i = 1; i < month; i++) {
		startDayOfYear = startDayOfYear + getTotalDaysOfMonth(year, i);
	}
	return startDayOfYear = (startDayOfYear % 7) + 1;
}

//년도만 받았을때
void printType1(int year) {
	for (int i = 1; i <= 12; i++) {
		printCalender(year, i);
		printf("\n");
	}
}

//년도와 월을 받을때
void printType2(int year, int month) {
	printCalender(year, month);
}

// 타이틀 그리기
void printTitle() {
	printf("-----------------------------\n");
	printf(" sun mon tue wed thu fri sat \n");
	printf("-----------------------------\n");
}

//XXXX년 X월 달력 출력
void printCalender(int year, int month) {
	printf("%d년 %d월\n", year, month);
	int totalDaysOfMonths = getTotalDaysOfMonth(year, month);
	int startDay = getStartDayOfMonth(year, month);
	printTitle();

	// 요일 공백
	if (startDay != 7) {
		for (int i = 0; i < startDay; i++) {
			printf("    ");
		}
	}

	for (int i = 1; i <= totalDaysOfMonths; i++) {
		printf("%4d", i);
		if ((startDay + i) % 7 == 0)
			printf("\n");
	}
	printf("\n");
}