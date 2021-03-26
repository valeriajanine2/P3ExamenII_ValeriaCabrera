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

vector<Dato> convertirTokens(vector<string> tokens) {
	vector<Dato> data;

	for(int i = 0; i < tokens.size(); i++) {

		char aux;
		string token = tokens.at(i);
		aux = token[0];
		Dato d;
		char tipo;
		
		if(i==0){
			d.c_tipo=aux;
			aux=tipo;
		}
		
		if(aux=='+'||aux=='-'||aux=='*'||aux=='/'){
			//es un operador
			DatoValor dv;
			dv.operador=aux;
			d.valor=dv;
		}else{
			if(tipo=='I'||tipo=='i'){
				DatoValor dv;
				dv.i_dato=(int)aux;
				d.valor=dv;
			}else if(tipo=='F'||tipo=='f'){
				DatoValor dv;
				dv.i_dato=(float)aux;
				d.valor=dv;
			}else if(tipo=='B'||tipo=='b'){
				DatoValor dv;
				dv.i_dato=(unsigned int)aux;
				d.valor=dv;
			}
		}

		data.push_back(d);
	}

	return data;
}

int main(int argc, char** argv) {
	//leer el archivo de texto
	ifstream leer_texto("entradas.txt",ios::in);
	string linea="";

	while(getline(leer_texto,linea)) {


		//imprimir los tokens
		vector<string> line;
		line=tokenizer(linea);
		vector<Dato> datos;
		datos =	convertirTokens(line);
		for(int i = 0; i < datos.size(); i++) {
			Dato d;
			d = datos.at(i);
			cout<<d.c_tipo<<endl;
		}

		cout<<"--------------------------"<<endl;

	}

	leer_texto.close();
	return 0;
}