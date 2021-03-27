#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
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

vector<Dato> convertirTokens(vector<string> tokens) {
	vector<Dato> data;
	//verificar que tipo de dato es
	if(tokens.at(0)=="I" || tokens.at(0)=="i") {
		
		Dato d;
		char aux;
		string token = tokens.at(0);
		aux = token[0];
		d.c_tipo=aux;
		data.push_back(d);

		for(int i = 1; i < tokens.size(); i++) {
			string tok = tokens.at(i);
			if(tok=="+"||tok=="-"||tok=="/"||tok=="*") {
				Dato dato;
				char aux2;
				aux2=tok[0];
				dato.valor.operador=aux2;
				data.push_back(dato);
			} else {
				Dato dato;
				int aux2;
				aux2=stoi(tok);
				dato.valor.i_dato=aux2;
				data.push_back(dato);
			}
		}

	} else if(tokens.at(0)=="F" || tokens.at(0)=="f") {
		
		Dato d;
		char aux;
		string token = tokens.at(0);
		aux = token[0];
		d.c_tipo=aux;
		data.push_back(d);

		for(int i = 1; i < tokens.size(); i++) {
			string tok = tokens.at(i);
			if(tok=="+"||tok=="-"||tok=="/"||tok=="*"){
				Dato dato;
				char aux2;
				aux2=tok[0];
				dato.valor.operador=aux2;
				data.push_back(dato);
			}else{
				Dato dato;
				float aux2;
				aux2=stof(tok);
				dato.valor.f_dato=aux2;
				data.push_back(dato);
			}
		}

	} else if(tokens.at(0)=="B" || tokens.at(0)=="b") {
		
		Dato d;
		char aux;
		string token = tokens.at(0);
		aux = token[0];
		d.c_tipo=aux;
		data.push_back(d);

		for(int i = 1; i < tokens.size(); i++) {
			string tok = tokens.at(i);
			if(tok=="+"||tok=="-"||tok=="/"||tok=="*"){
				Dato dato;
				char aux2;
				aux2=tok[0];
				DatoValor dataValue;
				dataValue.operador=aux2;
				dato.valor=dataValue;
				data.push_back(dato);
			}else{
				Dato dato;
				unsigned int aux2;
				aux2=stoul(tok);
				dato.valor.ui_dato=aux2;
				data.push_back(dato);
			}
		}
		
	}

	return data;
}

Dato evaluarOperacion(vector<Dato> datos){
	//para los ints
	/*
	vector<char> operadores;
	if(datos.at(0)==(Dato)'I' || datos.at(0)=='I'){
		stack<int> pila;
		for(int i = 1; i < datos.size(); i++){
			if(datos.at(i)=='+'||datos.at(i)=='-'||datos.at(i)=='*'||datos.at(i)=='/'){
				char aux = datos.at(i);
				
			}
		}	
	}
	*/
	//para los floats
	
	
	
	//para los binarios
}

int main(int argc, char** argv) {
	//leer el archivo de texto
	ifstream leer_texto("entradas.txt",ios::in);
	string linea="";

	while(getline(leer_texto,linea)) {

		vector<string> line;
		line=tokenizer(linea);
		vector<Dato> datos;
		datos =	convertirTokens(line);

	}

	leer_texto.close();
	return 0;
}