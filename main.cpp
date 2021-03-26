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
	Dato d;
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
				DatoValor dataValue;
				dataValue.operador=aux2;
				dato.valor=dataValue;
				data.push_back(dato);
			} else {
				Dato dato;
				int aux2;
				aux2=stoi(tok);
				DatoValor dataValue;
				dataValue.i_dato=aux2;
				dato.valor=dataValue;
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
				DatoValor dataValue;
				dataValue.operador=aux2;
				dato.valor=dataValue;
				data.push_back(dato);
			}else{
				Dato dato;
				float aux2;
				aux2=stof(tok);
				DatoValor dataValue;
				dataValue.f_dato=aux2;
				dato.valor=dataValue;
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
				float aux2;
				aux2=stoul(tok);
				DatoValor dataValue;
				dataValue.ui_dato=aux2;
				dato.valor=dataValue;
				data.push_back(dato);
			}
		}
		
	}



	return data;
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
		
		for(int i = 0; i < datos.size(); i++){
			Dato d;
			d=datos.at(i);
			cout<<d.c_tipo<<endl;
		}

		cout<<"---------------"<<endl;
	}

	leer_texto.close();
	return 0;
}