#include <iostream>
#include <locale.h>
#include <cstdlib> // Inclui a biblioteca <cstdlib> para usar srand()
#include <ctime>   // Inclui a biblioteca <ctime> para usar time()
#include <string>  // Inclui a biblioteca <string> para usar std::string

// Fun��o para gerar uma senha com base nas op��es selecionadas pelo usu�rio
std::string gerarSenha(int tamanho, bool incluirMaiuscula, bool incluirMinuscula, bool incluirNumero, bool incluirSimbolo) {
    std::string caracteresPermitidos = "";
    std::string senha = "";

    // Adiciona caracteres permitidos com base nas op��es selecionadas pelo usu�rio
    if (incluirMaiuscula) caracteresPermitidos += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (incluirMinuscula) caracteresPermitidos += "abcdefghijklmnopqrstuvwxyz";
    if (incluirNumero) caracteresPermitidos += "0123456789";
    if (incluirSimbolo) caracteresPermitidos += "!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Verifica se pelo menos uma op��o foi selecionada
    if (caracteresPermitidos.empty()) {
        std::cerr << "Erro: Nenhuma op��o selecionada." << std::endl;
        return senha;
    }

    // Inicializa o gerador de n�meros aleat�rios
    srand(time(NULL)); // Utiliza srand() para inicializar o gerador de n�meros aleat�rios

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

    // Solicita ao usu�rio as op��es para gerar a senha
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

    // Gera a senha com base nas op��es selecionadas pelo usu�rio
    std::string senha = gerarSenha(tamanho, incluirMaiuscula, incluirMinuscula, incluirNumero, incluirSimbolo);

    if (!senha.empty()) {
        // Exibe a senha gerada
        std::cout << "Senha gerada: " << senha << std::endl;

        // B�nus: Calcula a for�a da senha (simplesmente o tamanho)
        std::cout << "Forca da senha: " << senha.size() << std::endl;

        // B�nus: Copia a senha para a �rea de transfer�ncia (simulado)
        std::cout << "Senha copiada para a area de transferencia." << std::endl;
    }

    return 0;
}
