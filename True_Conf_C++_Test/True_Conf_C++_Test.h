/*
Задание:
    1.заполнить случайными числами от 1 до 9 значения контейнеров vector[i] и map[i];
    2.удалить случайное число элементов (не более 15) в каждом контейнере;
    3.после этого провести синхронизацию, чтобы в vector и map остались только имеющиеся
    в обоих контейнерах элементы (дубликаты не удалять).
*/
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const short int SIZE_CONTAINER = 20;

void fillContainers		        (vector <int>&, map<int, int>&);      //Функция заполняет контейнеры случайными значениями
void showContainers		        (vector <int>&, map<int, int>&);      //Функция показывает содержимое контейнеров
void eraseRandomNumbers	        (vector <int>&, map<int, int>&);	   //Функция удаляет случайное число элементов в контейнерах
void containersSynchronization  (vector <int>&, map<int, int>&);      //Функция синхронизирует контейнеры
void mapToVector                (vector <int>&, map<int, int>&);      //Функция конвертирует  map в vector
void vectorToMap                (map<int, int>&, vector <int>&);      //Функция конвертирует  vector в map