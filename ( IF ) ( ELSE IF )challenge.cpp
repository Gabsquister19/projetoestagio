#include <iostream> // Entrada e saída de dados
#include <locale.h> // Para trabalhar com acentos 

using namespace std; // Organização de pastas e poder usar o cout, cin e endl

int main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	double valorEntrada;
	string nome, sexo;
	
	valorEntrada = 12;
	
	cout << "Digite seu nome: \n";
	cin >> nome;

	
	cout << "Digite seu sexo: \n";
	cin >> sexo;
	
	
	if(sexo == "Masculino" ){
		
		cout << "\n\n -------- Comprovante de entrada  ----------\n\n";
		cout << "Nome: " << nome << endl;
		cout << "Valor entrada: " <<  valorEntrada << endl << endl;
		cout << "-------- Aproveite o show --------------" << endl << endl;
		
	}else if(sexo == "Ferminino" ){
		
		valorEntrada = valorEntrada / 2;
		
		cout << "\n\n -------- Comprovante de entrada  ----------\n\n";
		cout << "Nome: " << nome << endl;
		cout << "Valor entrada: " <<  valorEntrada << endl << endl;
		cout << "-------- Aproveite o show --------------" << endl << endl;
		
		
	}else{
		
		cout << "\n\nVocê nao digitou um sexo válido";
	}
	

	
	
	
	
	
	
	
	system("pause");
	
	return 0;
}









