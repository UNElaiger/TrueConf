// True_Conf_C++_Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "True_Conf_C++_Test.h"

int main()
{
    srand((unsigned int)time(0));
    
    vector <int> vector(SIZE_CONTAINER);
    map <int, int> map;

    cout << "Fill Container" << endl;
    fillContainers(vector, map);
    showContainers(vector, map);

    cout<< endl << "Vector affter erase" << endl;
    eraseRandomNumbers(vector,map);
    showContainers(vector,map);

    cout << "Synch complete" << endl;
    containersSynchronization(vector, map);
    showContainers(vector, map);

    return 0;
}

void fillContainers(vector <int> & containerVector, 
                   map<int, int> & containerMap)
{
    for (int i = 0; i < SIZE_CONTAINER; i++) 
        {
            containerVector[i] = rand() % 9 + 1;
            containerMap   [i] = rand() % 9 + 1;

        }
}

void showContainers(vector<int> & containerVector, 
                    map<int, int> & containerMap)
{
    int vectorSize = (int)containerVector.size();
    int mapSize    = (int)containerMap.size();
    cout << "Vector Lenght: " << vectorSize <<endl;
    cout << "Vector: ";

    for (int i = 0; i < vectorSize; i++)
        {
            cout << containerVector[i] << ' ';
        }

    cout <<endl << "-----------------------------------------------" << endl;

    cout << "Map Lenght: " << mapSize << endl;

    for (auto iter = containerMap.begin(); 
        iter != containerMap.end(); iter++)
    {
        cout << iter->first << ") " << iter->second << endl;
    }

    cout <<endl << "-----------------------------------------------" << endl;
    
}

void eraseRandomNumbers(vector<int> & containerVector, 
                        map<int, int> & containerMap) 
{
    int randomNumber = rand() % 15 + 1;
    cout << "Random number: " << randomNumber << endl;

    containerVector.erase(containerVector.begin(), 
        containerVector.begin() + randomNumber);

    map <int, int> :: iterator iterStart = containerMap.begin();            // итератор ссылающийся на начало контйнера map
    map <int, int> :: iterator iterEnd = containerMap.find(randomNumber);   // итератор ссылающийся на конец контйнера map

    containerMap.erase(iterStart, iterEnd);

}

void containersSynchronization (vector<int>& containerVector,
                                 map<int, int>& containerMap)
{
    vector <int> fromMap;
    vector <int> temp;

    mapToVector(fromMap, containerMap);
    sort(containerVector.begin(), containerVector.end());               
    sort(fromMap.begin(), fromMap.end());

    set_intersection(containerVector.begin(), containerVector.end(),        //Во временный вектор заисываются элементы, 
                    fromMap.begin(), fromMap.end(), back_inserter(temp));   //которые есть в обоих контейнерах

    containerVector.assign(temp.begin(), temp.end());                     
    vectorToMap(containerMap, temp);
}

void mapToVector(vector<int>& containerVector,
                    map<int, int>& containerMap)
{
    auto startIter = containerMap.begin();                                   // создаются два итератора ссылающиеся на начало и конец контейнера map 
    auto endIter   = containerMap.end();
    containerVector.clear();                                                 // очишаем вектор 
    containerVector.reserve(containerMap.size());                            // резервируем память для нового вектора

    while (startIter != endIter) 
        {
            containerVector.push_back(startIter->second);                    // поробегаемся по всему контейнеру и добавляем элементы в вектор
            ++startIter;
        }

}

void vectorToMap (map<int, int>& containerMap,
                  vector<int>& containerVector)
{
    containerMap.clear();
    for (unsigned int i = 0; i < containerVector.size(); i++)
        {
            containerMap[i] = containerVector[i];
        }

}