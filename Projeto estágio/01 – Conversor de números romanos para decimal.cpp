#include <iostream>
#include <map>
#include <string>
#include <cstdlib> // Para usar atoi
#include <vector>

// Fun��o para converter um n�mero romano em decimal
int romanToDecimal(const std::string& roman) {
    // Mapa de convers�o de s�mbolos romanos para valores decimais
    std::map<char, int> romanMap;
    romanMap.insert(std::make_pair('I', 1));
    romanMap.insert(std::make_pair('V', 5));
    romanMap.insert(std::make_pair('X', 10));
    romanMap.insert(std::make_pair('G', 50));
    romanMap.insert(std::make_pair('C', 100));
    romanMap.insert(std::make_pair('D', 500));
    romanMap.insert(std::make_pair('M', 1000));

    // Vari�vel para armazenar o valor decimal
    int decimal = 0;

    // Loop atrav�s dos s�mbolos romanos
    for (size_t i = 0; i < roman.size(); ++i) {
        // Verifica se o s�mbolo atual � menor que o pr�ximo s�mbolo
        if (i + 1 < roman.size() && romanMap[roman[i]] < romanMap[roman[i + 1]]) {
            decimal -= romanMap[roman[i]]; // Se sim, subtrai o valor
        } else {
            decimal += romanMap[roman[i]]; // Caso contr�rio, adiciona o valor
        }
    }

    return decimal;
}

// Fun��o para converter um n�mero decimal em romano
std::string decimalToRoman(int decimal) {
    // Mapa de convers�o de valores decimais para s�mbolos romanos
    std::map<int, std::string> decimalMap;
    decimalMap.insert(std::make_pair(1, "I"));
    decimalMap.insert(std::make_pair(4, "IV"));
    decimalMap.insert(std::make_pair(5, "V"));
    decimalMap.insert(std::make_pair(9, "IX"));
    decimalMap.insert(std::make_pair(10, "X"));
    decimalMap.insert(std::make_pair(40, "XL"));
    decimalMap.insert(std::make_pair(50, "L"));
    decimalMap.insert(std::make_pair(90, "XC"));
    decimalMap.insert(std::make_pair(100, "C"));
    decimalMap.insert(std::make_pair(400, "CD"));
    decimalMap.insert(std::make_pair(500, "D"));
    decimalMap.insert(std::make_pair(900, "CM"));
    decimalMap.insert(std::make_pair(1000, "M"));

    // Vetor para armazenar os valores decimais
    std::vector<int> decimals;
    // Vetor para armazenar os s�mbolos romanos
    std::vector<std::string> romanSymbols;

    // Adiciona os valores decimais e s�mbolos romanos ao vetor
    for (auto it = decimalMap.rbegin(); it != decimalMap.rend(); ++it) {
        while (decimal >= it->first) {
            decimals.push_back(it->first);
            romanSymbols.push_back(it->second);
            decimal -= it->first;
        }
    }

    // Constr�i a representa��o romana
    std::string roman;
    for (size_t i = 0; i < decimals.size(); ++i) {
        roman += romanSymbols[i];
    }

    return roman;
}

int main() {
    std::string input;

    // Loop principal do programa
    while (true) {
        std::cout << "Digite um n�mero romano ou decimal (q para sair): ";
        std::cin >> input;

        // Verifica se o usu�rio deseja sair
        if (input == "q") {
            break;
        }

        // Verifica se o usu�rio inseriu um n�mero romano ou decimal
        bool isRoman = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isRoman = false;
                break;
            }
        }

        // Converte e exibe o resultado
        if (isRoman) {
            // Converte o n�mero romano para decimal
            int decimal = romanToDecimal(input);
            std::cout << "Valor decimal: " << decimal << std::endl;
        } else {
            // Converte o n�mero decimal para romano
            int decimal = atoi(input.c_str()); // Converte a string para int
            std::string roman = decimalToRoman(decimal);
            std::
