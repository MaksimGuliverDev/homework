#include <iostream>
#include <string>
#include <fstream>
//Работа с файлами. Задание 4. Считывание двумерного массива из файла, автор Максим Гуливер

int main()
{
    setlocale(LC_ALL, "Russian");
   
    std::ifstream ifile("twodimarr.txt");
    if (ifile.is_open()) 
    {
        std::string r{};
        std::string c{};

        ifile >> r;
        ifile >> c;

        int rows = std::stoi(r);
        int columns = std::stoi(c);
        

        int** integers{ new int* [rows] {} };

        for (int row{}; row < rows; ++row)
        {
            integers[row] = new int[columns];
        }

        while (!ifile.eof())
        {
            
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    std::string data{};
                    ifile >> data;
                    integers[i][j] = std::stoi(data);
                }
            }
        }
        ifile.close();
        //Разворот строки в двумерном массиве
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns / 2; j++)
            {
                int temp = integers[i][j];
                integers[i][j] = integers[i][columns - 1 - j];
                integers[i][columns - 1 - j] = temp;
            }
        }
        //Вывод в консоль
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                std::cout << integers[i][j] << " "; //Ошибка С6001: Использование неинициализированной памяти, не знаю в чем проблема, и как ее решить
            }
            std::cout << std::endl;
        }
        //удаление массива
        for (int i = 0; i < rows; i++)
        {
            delete[]integers[i];
        }

        delete[]integers;

    }
    

}

