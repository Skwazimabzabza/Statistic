// Статистика.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

void generateFileStatistics(const char* inputFile, const char* outputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << inputFile << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << outputFile << std::endl;
        return;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char ch;
    while (inFile.get(ch)) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }

        if (std::isdigit(static_cast<unsigned char>(ch))) {
            digitCount++;
        }
        else if (std::isalpha(static_cast<unsigned char>(ch))) {
            ch = std::tolower(static_cast<unsigned char>(ch));
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'а' || ch == 'е' || ch == 'ё' || ch == 'и' || ch == 'о' ||
                ch == 'у' || ch == 'ы' || ch == 'э' || ch == 'ю' || ch == 'я') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
    }


    if (charCount > 0 && inFile.peek() == EOF) {
        lineCount++;
    }

    
    outFile << "Количество символов: " << charCount << std::endl;
    outFile << "Количество строк: " << lineCount << std::endl;
    outFile << "Количество гласных букв: " << vowelCount << std::endl;
    outFile << "Количество согласных букв: " << consonantCount << std::endl;
    outFile << "Количество цифр: " << digitCount << std::endl;


    inFile.close();
    outFile.close();

    std::cout << "Статистика записана в файл " << outputFile << std::endl;
}

void writeToFile(const char* inputFile) {
    std::ofstream outFile(inputFile, std::ios::out | std::ios::trunc);
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << inputFile << std::endl;
        return;
    }

    std::string line;
    std::cout << "Введите строки текста для записи в файл (введите \"END\" с новой строки для завершения ввода):" << std::endl;
    while (true) {
        std::getline(std::cin, line);
        if (line == "END") break;
        outFile << line << '\n';
    }

    outFile.close();
    std::cout << "Данные успешно записаны в файл " << inputFile << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const char* inputFile = "input.txt";
    const char* outputFile = "statistics.txt";


    writeToFile(inputFile);


    generateFileStatistics(inputFile, outputFile);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
