// StateMachine3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <fstream>
#include <regex>

using namespace std;

void initInferenceRules(map<char, string> &inferenceRules);
bool checkSequence(char initNonTerminal, const string& sourceSequence,
    const string& currentSequence, map<char, string>& inferenceRules);

int main()
{
    map<char, string> inferenceRules;

    char initNonTerminal = ' ';

    cout << "Enter initial non-terminal: "; cin >> initNonTerminal;

    string currentSequence;
    currentSequence += initNonTerminal;

    initInferenceRules(inferenceRules);

    string str = "abc";

    cout << (str.substr(3)) << endl;
}

void initInferenceRules(map<char, string> &inferenceRules)
{
    ifstream fin("input.txt");

    char leftPart = ' ';
    string rightPart = "";

    while (fin >> leftPart && fin >> rightPart) {
        cout << leftPart << " " << rightPart << endl;
        inferenceRules[leftPart] = rightPart;
    }
}

bool checkSequence(char initNonTerminal, const string &sourceSequence, 
     string &currentSequence,  map<char, string>& inferenceRules)
{
    for (auto it = inferenceRules.cbegin(); it != inferenceRules.cend(); ++it) {
        auto leftPartPos = currentSequence.find_first_of(it->first);

        if (leftPartPos != string::npos) {
            currentSequence = currentSequence.substr(0, leftPartPos) + it->second + currentSequence.substr(leftPartPos + 1);


        }
    }

    return true;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
