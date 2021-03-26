#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

union DatoValor {
	unsigned int ui_dato;
	int i_dato;
	float f_dato;
	char operador;
};

struct Dato {
	char c_tipo;
	DatoValor valor;
};

vector<string> tokenizer(string linea) {
	//usar delimitador , para separar los elementos

	vector<string> result;

	string delim = ",";
	size_t pos = 0;
	string token;
	string::size_type sz;
	while((pos = linea.find(delim))!=string::npos) {
		token = linea.substr(0,pos);
		result.push_back(token);
		linea.erase(0,pos + delim.length());
	}
	result.push_back(linea);
	
	return result;
}

int main(int argc, char** argv) {
	//leer el archivo de texto
	ifstream leer_texto("entradas.txt",ios::in);
	string linea="";

	while(getline(leer_texto,linea)) {
		
		vector<string> line;
		line=tokenizer(linea);
		for(int i = 0; i < line.size(); i++){
			cout<<"token "<<i<<" : "<<line.at(i)<<endl;
		}
		
		cout<<"--------------------------"<<endl;
	}
	
	leer_texto.close();
	return 0;
}