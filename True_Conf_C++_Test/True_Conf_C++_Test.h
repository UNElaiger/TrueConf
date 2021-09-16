/*
�������:
    1.��������� ���������� ������� �� 1 �� 9 �������� ����������� vector[i] � map[i];
    2.������� ��������� ����� ��������� (�� ����� 15) � ������ ����������;
    3.����� ����� �������� �������������, ����� � vector � map �������� ������ ���������
    � ����� ����������� �������� (��������� �� �������).
*/
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
const short int SIZE_CONTAINER = 20;

void fillContainers		        (vector <int>&, map<int, int>&);      //������� ��������� ���������� ���������� ����������
void showContainers		        (vector <int>&, map<int, int>&);      //������� ���������� ���������� �����������
void eraseRandomNumbers	        (vector <int>&, map<int, int>&);	   //������� ������� ��������� ����� ��������� � �����������
void containersSynchronization  (vector <int>&, map<int, int>&);      //������� �������������� ����������
void mapToVector                (vector <int>&, map<int, int>&);      //������� ������������  map � vector
void vectorToMap                (map<int, int>&, vector <int>&);      //������� ������������  vector � map