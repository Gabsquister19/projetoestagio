#include <iostream>
#include <map>
#include <string>
#include <cstdlib> // Para usar atoi
#include <vector>

// Função para converter um número romano em decimal
int romanToDecimal(const std::string& roman) {
    // Mapa de conversão de símbolos romanos para valores decimais
    std::map<char, int> romanMap;
    romanMap.insert(std::make_pair('I', 1));
    romanMap.insert(std::make_pair('V', 5));
    romanMap.insert(std::make_pair('X', 10));
    romanMap.insert(std::make_pair('G', 50));
    romanMap.insert(std::make_pair('C', 100));
    romanMap.insert(std::make_pair('D', 500));
    romanMap.insert(std::make_pair('M', 1000));

    // Variável para armazenar o valor decimal
    int decimal = 0;

    // Loop através dos símbolos romanos
    for (size_t i = 0; i < roman.size(); ++i) {
        // Verifica se o símbolo atual é menor que o próximo símbolo
        if (i + 1 < roman.size() && romanMap[roman[i]] < romanMap[roman[i + 1]]) {
            decimal -= romanMap[roman[i]]; // Se sim, subtrai o valor
        } else {
            decimal += romanMap[roman[i]]; // Caso contrário, adiciona o valor
        }
    }

    return decimal;
}

// Função para converter um número decimal em romano
std::string decimalToRoman(int decimal) {
    // Mapa de conversão de valores decimais para símbolos romanos
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
    // Vetor para armazenar os símbolos romanos
    std::vector<std::string> romanSymbols;

    // Adiciona os valores decimais e símbolos romanos ao vetor
    for (auto it = decimalMap.rbegin(); it != decimalMap.rend(); ++it) {
        while (decimal >= it->first) {
            decimals.push_back(it->first);
            romanSymbols.push_back(it->second);
            decimal -= it->first;
        }
    }

    // Constrói a representação romana
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
        std::cout << "Digite um número romano ou decimal (q para sair): ";
        std::cin >> input;

        // Verifica se o usuário deseja sair
        if (input == "q") {
            break;
        }

        // Verifica se o usuário inseriu um número romano ou decimal
        bool isRoman = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isRoman = false;
                break;
            }
        }

        // Converte e exibe o resultado
        if (isRoman) {
            // Converte o número romano para decimal
            int decimal = romanToDecimal(input);
            std::cout << "Valor decimal: " << decimal << std::endl;
        } else {
            // Converte o número decimal para romano
            int decimal = atoi(input.c_str()); // Converte a string para int
            std::string roman = decimalToRoman(decimal);
            std::
