#include <iostream> // Entrada e sa�da de dados
#include <locale.h> // Para trabalhar com acentos 

using namespace std; // Organiza��o de pastas e poder usar o cout, cin e endl

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
		
		cout << "\n\nVoc� nao digitou um sexo v�lido";
	}
	

	
	
	
	
	
	
	
	system("pause");
	
	return 0;
}









