#pragma once
#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define APPLICATION_TEMPLATE "61"
#define PRIORITY_TEMPLATE "87"
#define APPLICATIONS "4F"
#define LENHEXBYTE 3
#define SIZERID 32
#define SIZEPIX 10
#define SUPPCARDLEN 5
void printRIDxPIXsort(char* card_answer);
typedef struct {
    int id;
    char RID[SIZERID];
    char PIX[SIZEPIX];
    int priority;
    bool isCorrect;
}appCard_t;
#endif // PARSE_H_INCLUDED