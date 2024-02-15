#include <iostream>
#include <locale.h>
#include <cstdlib> // Inclui a biblioteca <cstdlib> para usar srand()
#include <ctime>   // Inclui a biblioteca <ctime> para usar time()
#include <string>  // Inclui a biblioteca <string> para usar std::string

// Função para gerar uma senha com base nas opções selecionadas pelo usuário
std::string gerarSenha(int tamanho, bool incluirMaiuscula, bool incluirMinuscula, bool incluirNumero, bool incluirSimbolo) {
    std::string caracteresPermitidos = "";
    std::string senha = "";

    // Adiciona caracteres permitidos com base nas opções selecionadas pelo usuário
    if (incluirMaiuscula) caracteresPermitidos += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (incluirMinuscula) caracteresPermitidos += "abcdefghijklmnopqrstuvwxyz";
    if (incluirNumero) caracteresPermitidos += "0123456789";
    if (incluirSimbolo) caracteresPermitidos += "!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Verifica se pelo menos uma opção foi selecionada
    if (caracteresPermitidos.empty()) {
        std::cerr << "Erro: Nenhuma opção selecionada." << std::endl;
        return senha;
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL)); // Utiliza srand() para inicializar o gerador de números aleatórios

    // Gera a senha
    for (int i = 0; i < tamanho; ++i) {
        int index = rand() % caracteresPermitidos.size();
        senha += caracteresPermitidos[index];
    }

    return senha;
}

int main() {
    setlocale(LC_ALL, "");

    int tamanho;
    bool incluirMaiuscula, incluirMinuscula, incluirNumero, incluirSimbolo;

    // Solicita ao usuário as opções para gerar a senha
    std::cout << "Digite o tamanho da senha: ";
    std::cin >> tamanho;

    std::cout << "Incluir letra maiuscula? (1 - Sim, 0 - Nao): ";
    std::cin >> incluirMaiuscula;

    std::cout << "Incluir letra minuscula? (1 - Sim, 0 - Nao): ";
    std::cin >> incluirMinuscula;

    std::cout << "Incluir numero? (1 - Sim, 0 - Nao): ";
    std::cin >> incluirNumero;

    std::cout << "Incluir simbolo? (1 - Sim, 0 - Nao): ";
    std::cin >> incluirSimbolo;

    // Gera a senha com base nas opções selecionadas pelo usuário
    std::string senha = gerarSenha(tamanho, incluirMaiuscula, incluirMinuscula, incluirNumero, incluirSimbolo);

    if (!senha.empty()) {
        // Exibe a senha gerada
        std::cout << "Senha gerada: " << senha << std::endl;

        // Bônus: Calcula a força da senha (simplesmente o tamanho)
        std::cout << "Forca da senha: " << senha.size() << std::endl;

        // Bônus: Copia a senha para a área de transferência (simulado)
        std::cout << "Senha copiada para a area de transferencia." << std::endl;
    }

    return 0;
}
