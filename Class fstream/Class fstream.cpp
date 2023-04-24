// Class fstream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

//Задание
bool print_file(std::string file_path) {
    static std::ifstream in;
    in.open(file_path);

    if (in.is_open()) {
        char sym;
        while (in.get(sym))
            std::cout << sym;
        std::cout<< std::endl;
        in.close();
        return true;
    }

    in.close();
    return false;
}

bool insert_file(std::string file_path, std::string str, int position);



int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    std::string path = "file.txt";

    /*std::fstream file;//Объект класса fstream, позволяющий одновременно записывать и считывать данные из файла
    file.open(path, std::ios::in | std::ios::app);//| - битовое или (не логическое||)//Открытие файла с режимами in и app

    if (file.is_open()) {
        std::cout << "Файл открыт.\n";
        //Добавление записи в файл
       std::cout << "Запись в файл.\nВведите строку: ";
        std::string str;
        std::getline(std::cin, str);
        file << str << "\n";
        std::cout << "Запись добавлена в файл\n";

        file.seekg(0, std::ios::beg);// Перемещие курсора для счиытывания данных в начало файла

        //Чтение из файла
        std::cout << "Содержимое файла:\n";
        char sym;
        while (file.get(sym))
            std::cout << sym;

        //seekg - seek get pointer
        //seekp - seek put pointer
        //ios::beg - обращение в начало файла
        //ios::end - обращение в конец файла
        //ios::cur - показывает текущее положение курсора
        //tellg и tellp - возвращают 

    }
    else
        std::cout << "Ошибка открытия файла.\n";

    file.close();*/

    //Задача. Ввод в позицию файла
   /* std::cout << "Содержимое файла:\n";
    print_file(path);

    std::cout << "Введите строку: ";
    std::string substr;
    std::getline(std::cin, substr);

    std::cout << "Введите позицию: ";
    std::cin >> n;
    std::cin.ignore();

    if (insert_file(path, substr, n)) {
        std::cout << "Вставка выполнена успешно\n";
        std::cout << "Итоговое содержимое файла: \n";
        print_file(path);
        std::cout << std::endl;
    }
    else
        std::cout << "Ошибка выполнения функции\n";*/

    //Задача. В файле записана дата в формате ЬЬ.ЬЬ.БББ. Чтение даты из файла
    std::string data_path = "data.txt";
    print_file(data_path);
    std::fstream file;
    file.open(data_path, std::ios::app);
    char sym = '.';
    


    unsigned int day = ;
    unsigned int month = ;
    unsigned int year = ;

    std::cout << "День: " << day << std::endl;
    std::cout << "Месяц: " << month << std::endl;
    std::cout << "Год: " << year << std::endl;


    return 0;
}

bool insert_file(std::string file_path, std::string str, int position) {
    std::string file_text;
    
    std::fstream file;
    file.open(file_path, std::ios::in);

    if (file.is_open()) {
        char sym;
        while (file.get(sym))
            file_text += sym;
    }
    else {
        file.close();
        return false;
    }
    file.close();

    file_text.insert(position, str);

    file.open(file_path, std::ios::out);
    if (file.is_open()) {
        file << file_text;
        file.close();
        return false;
    }
    file.close();
        return false;
}


