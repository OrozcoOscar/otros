/*
########################
Libreria Full multitarea
######################## 
Oscar Orozco Pacheco 
31/05/19
*/
#include "iostream"
#include "stdlib.h"
#include "locale.h"
#include "windows.h"
#include "conio.h"
#include "string"
#include "cstdlib"
#include "sstream"
using namespace std;
//-----------------------------------------------------------------------------------------------------//
/////////////////////////Funciones independientes///////////////////////////////////////////////////////
//-----------------------------------------------------------------------------------------------------//
/* 
# Cambia el color de la consola
# Ej:
# color(3)->azul claro;
# color(4)->rojo oscuro;

*/
void color(int c){
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),c);
}

/* 
# devuelve la longitud de un numero 
# Ej:
# cout<<size(n);
*/
long size(long n){
	int i=1;
	while(n>=10){	
	n=n/10;//dividimos n entre diez hasta q n < 10 
	i++;
	}
return i;
}
/* 
# Combierte un string a int
# Ej:
# to_int(n);
*/
int to_int(string n){
	return atoi(n.c_str());
}
/* 
# Combierte int  string 
# Ej:
# to_string(n);
*/
string to_string(int n){
	ostringstream temp;
	temp << n;
	return temp.str();
}
/* 
# limpia la consola
# Ej:
# clear();
*/
void clear(){
system("cls");
}
/* 
# Informa sobre un error
# Ej:
# error("Comando erroneo");
*/
void error(string m){
	system("color c");
	system("title Comando Erroneo");
	cout<<m;
	system("pause>null");
	clear();
	
}
/* 
# Pregunta algo al usuario y retorna la respuesta
# Ej:
# pregunta("Continuar [s] ,[n]");
*/
string pregunta(string m){ 
	color(3);
	string op;
	system("title Que desea hacer");
	cout<<m;
	cin>>op;
return op;
	
}
/* 
# Obliga a la consola a trabajar en cierto idioma
# Ej:
# idioma("spanish");
*/
void idioma(char *i){
	setlocale(LC_ALL, i);
}
/* 
# Obliga a la consola a trabajar en cierto idiomaRetorna un vect con el numero en unidaes decenas centenas...
# Ej:
# *puntero=desc(n);
*/
int *desc(int n){
	int mod=10,ceros=1,s=size(n),*v=new int[s];
	while(n>=1){
		v[s-1]=(n%mod)*ceros;
		n/=mod;
		ceros*=10;
		s--;
	}
	return v;
}
//-----------------------------------------------------------------------------------------------------//
//////////////////////////////Funciones dependientes///////////////////////////////////////////////////
//-----------------------------------------------------------------------------------------------------//
/* 
# devuelve un vect con los dijitos de un numero 
# Ej:
# *p=dijitos(n);
*/
int *dijitos(int n){
	int *v=new int[size(n)],i=size(n)-1,aux=n;
	while(i>=0){
	v[i]=aux%10;//obtenemos el ultimo numero de aux y lo guardamos en el vect 
	aux/=10;//quitamos el ultimo numero de aux
	i--;
}
return v;
}
/* 
# devuelve 1 si el numero es feliz,0 si no  lo es
# Ej:
# if(numerofeliz(n)){
#  Code...
# }else{
#  Code..
#} 
*/
int numerofeliz(int n){
	if(n==1){
		return 1;
	}else{
		
	int v[size(n)],s=0;
	int *p=dijitos(n);
	static int ant=n;
	if(n>ant){
			return 0;
	}else{
		for(int i=0;i<size(n);i++){
		s+=p[i]*p[i];
		}
	}
	
	}
		
}
/* 
# devuelve 1 si el numero es curioso,0 si no  lo es
# Ej:
# if(curioso(n)){
#  Code...
# }else{
#  Code..
#} 
*/
int curioso(int n){
	int aux=n;
	if(size(aux)>1){
		while(size(aux)>1){
			aux%=10;
		}
	}
	if((n*n)%10==aux){
			return 1;
	}else{
			return 0;
	}
}
/* 
# Retorna un vect con todos los divisores de un numero 
# Ej:
# *puntero =divisores(n);

*/
int *divisores(int n){
int w=0,p=1;
if(w==0){
	for(int i=1; i<n;i++){
	 if(n%i==0)w++;//contamos cuantos divisores tiene el numero
	 }
}

 int *v = new int[w];//creamos un vect y se lo asignamos a el puntero
 v[0]=w;//guardamos en la primera posicion la longitud del vect
	 for(int b=1; b<n;b++){
	 if(n%b==0){
	 v[p]=b;//guardamos los divisores
	 p++;	
	 
	 }
	 }

	 return v;
}
/* 
# devuelve la suma de los divisores de un numero
# Ej:
# sumaDiv(vect,1);
#  se le pasa un vector y se empieza a sumar desde la posicion 1 sabiendo q en la posicion 0 debe estar 
#  la longitud el vect
*/
int sumaDiv(int p[],int ini){
	if(ini==p[0]+1){
		return 0;
	}else{
		return p[ini]+sumaDiv(p,ini+1);
	}

}
/* 
# devuelve 1 si el numero es ambicioso,0 si no  lo es
# Ej:
# if(ambicioso(n)){
#  Code...
# }else{
#  Code..
#} 
*/
int ambicioso(int n){
	if(sumaDiv(divisores(n),1)>n){
		return 0;
	}else if(sumaDiv(divisores(n),1)==sumaDiv(divisores(sumaDiv(divisores(n),1)),1)){
		return 1;
	}else{
			return 0;
	}
}

/* 
# Retorna un vect con los valores binarios de un numero 
# Ej:
# *puntero =binario(n);
# sabiendo q en la posicion 0 esta la longitud el vect
*/

int *binario(int n){
	int v[n],w=0;
	
while(n!=0){
		v[w]=n%2;
		n/=2;
		w++;
}
	int *b=new int[w+1];//crea un vector y se lo asigna al puntero
	b[0]=w;
	
	for(int e=0;e<w;e++)b[w-e]=v[e];

	return b;
}
//*/
/*/-------------------------------
/*///-----------------------------------
/* 
# devuelve 1 si el numero es malvado,0 si no  lo es
# Ej:
# if(malvado(n)){
#  Code...
# }else{
#  Code..
#} 
*/

int malvado(int n){
	int*p=binario(n);
		for(int e=0;e<=*p;e++){
			if(*(p+e)==1&&*(p+e+1)==1){
				return 1;
			}
		
		}
		return 0;
}
//*/

/* 
# Guarda cadena de caracteres en una variable
# Ej:
# variable=textInCin();
*/
string textInCin(){
	   string text;
	   getline(cin,text);
	   return text;
}
/* 
# Confirma si un numero x es primo(1) o no(0) 
# Ej:
# if(primo(n)){
#	cout<<"Es primo ";
# }else{
#	cout<<"No es primo ";
# }
*/
long primo(long n){
	int cont =1;
	for(int i=2; i<n+1;i++){
	 if(n%i== 0)cont++;
	 }
(cont<=2)?cont=1:cont=0;
return cont;
}
/* 
# Imprime todos los divisores de un numero 
# Ej:
# cout<<divisores(n);

*/
long divisores(long n){
	cout<<"Divisores de "<<n<<" : 1 ";
	for(int i=2; i<n;i++){
	 if(n%i==0)cout<<i<<" ";
	 }
}

/* 
# Rellena un vector int (se debe usar punteros)
# Ej;
# ->int *puntero = rvect(size,mensaje);
# int *puntero = rvect(4,"Ingrese el valor ");
*/
int *fillVectInt(int s,string t){
	int *v = new int[s];
    for(int i = 0; i < s; i++){
    	cout<<t<<" ["<<i+1<<"] ";cin>>v[i];
	}
 return v;
} 
/* 
# Ordena un vector 
# Ej;
# ->int *puntero = orderVect(vector,size,direccion);
# int *puntero = orderVect(v,4,0);
*/
int *orderVect(int vect[],int s,int d){
	int *v=vect;
	if(d==0){
		for(int i=1;i<s;i++){
		for(int e=0;e<s-1;e++){
		if(v[i]<v[e]){
		int a=v[i];
		v[i]=v[e];
		v[e]=a;
		}
		}
}
}
else if(d==1){
		for(int i=1;i<s;i++){
		for(int e=0;e<s-1;e++){
		if(v[i]>v[e]){
		int a=v[i];
		v[i]=v[e];
		v[e]=a;
		}
		}
}
}else{
	cout<<"\n Ingresa (1) o (0) para ordenar ascendente o descendentemente \n";
}

 return v;
}
/* 
# Devuelbe un numero random 
# Ej;
# ->random(inicio,fin);
# 
*/
long random(int a,int b){
	return a+(rand() %b);
}


/* 
# Rotar un vector 
# Ej;
# ->int *puntero = rotateVect(vector,size,direccion);
# int *puntero = rotateVect(v,4,0);
*/
int *rotateVect(int vect[],int s,int d){
	int *v=vect,aux[s];
if(d==0){
	aux[s-1]=v[0];
	for(int a=s-2;a>=0;a--){
	aux[a]=v[a+1];
}
	for(int a=0;a<s;a++){
	v[a]=aux[a];
}
}
else if(d==1){
	aux[0]=v[s-1];
	for(int a=s-1;a>=1;a--){
	aux[a]=v[a-1];	
}

	for(int a=0;a<s;a++){
	v[a]=aux[a];
}
}else{
	cout<<"\n Ingresa (1) o (0) para rotar ascendente o descendentemente \n";
}
return v;
}

///////////buscar uun car dentro de otro y retorna la pocicion ///////////////////
int search(string a,string b){
	int est=-1;
	int e=0;
	for(int i=0;i<a.length();i++){
		if(a[i]==b[e]){
				if(e==0 and i<a.length()-1 and b.length()>1){
					est=i;
				}
		
			e++;
				if(e==b.length())i=a.length();
		}else{
			est=-1;
			e=0;
		}
		
		
	}
	return est;
}

int digitos(int num,int aux){
	if(num/10 == 0) return aux;
	return digitos(num/10,aux+1);
}

long pot(int num, int exp){
	if(exp==0) return 1;
	return num*pot(num,exp-1);
}
long to_bin(long num,long mult){
	if(num < 2) return num*mult;
	return (num%2)*mult + to_bin(num/2, mult*10);
}
long to_num(long num,int cont){
	if(num/10 == 0) return num*pot(2,cont);
	return (num%10)*pot(2,cont) + to_num(num/10, cont+1);
}
bool malvadoYodioso(long bin,int aux){
	if(bin/10 == 0){
		if(aux%2==0) return true;
		else return false;
	}
	if(bin%10 == 1) return malvadoYodioso(bin/10,aux+1);
	else return  malvadoYodioso(bin/10,aux);
}
bool curioso(long num){
	if(num%10 == pot(num,2)%10) return true;
	else return false;
}
bool perfecto(long num,int aux,int i){
	if(i <= num/2){
		if(num%i == 0) aux+=i;
		return perfecto(num,aux,i+1);
	}else{
		if(aux == num) return true;
		else return false;
	}
}
bool semiperfecto(long num,int aux,int i){
	if(i <= num/2){
		if(num%i == 0) aux+=i;
		return semiperfecto(num,aux,i+1);
	}else{
		if(aux >= num) return true;
		else return false;
	}
}
bool ambicioso(long num,int aux,int i){
	if(i <= num/2){
		if(num%i == 0) aux+=i;
		return ambicioso(num,aux,i+1);
	}else{
		if(perfecto(aux,0,1)) return true;
		else return false;
	}
}
long poderoso(long num,int dist,int iter){
	if(dist == 1) return pot(num, iter);
	else{
		long aux=1;
		for(int i=0; i<dist-1; i++) aux*= 10;
		return pot(num/aux, iter) + poderoso(num%aux,dist-1,iter+1);
	}
}
bool ispoderoso(long num,int dist,int iter){
	if(num == poderoso(num,dist,iter)) return true;
	else return false;
}
bool feliz(long num,int i){
	if(num == 1) return true;
	else if(i == 0) return false;
	else{
		int digito,suma=0;
		while (num != 0) {
			digito = num % 10;
			suma += pot(digito,2);
			num /= 10;
		}
		return feliz(suma,i-1);
	}
}
long narcista(long num, int dist){
	if(num/10 == 0) return pot(num,dist);
	return pot((num%10),dist) + narcista(num/10,dist);
}
bool isnarcista(long num, int dist){
	if(num == narcista(num,dist)) return true;
	return false;
}
long sumadivisores(long num,long aux,int i){
	if(i <= num/2){
		if(num%i == 0) aux+=i;
		return sumadivisores(num,aux,i+1);
	}
	else return aux;
}
bool isprimo(long num,long aux,int i){
	if(i <= num/2){
		if(num%i == 0) aux+=i;
		return isprimo(num,aux,i+1);
	}else{
		if(aux == 1) return true;
		else return false;
	}
}
bool issociable(long original,long num,int iter){
	if(original == sumadivisores(num,0,1)) return true;
	else if(iter == 1) return false;
	else return issociable(original, sumadivisores(num,0,1), iter-1);
}
int apariciones(string text,char n){
    int c=0;
     for(int i=0;i<text.length();i++){
        if(text[i]==n){
            c++;
        }
    }
    return c;
}

/*
int main(){
    int c=apariciones("h:o:l:a",':')+1;
string vect[c];
split("h:o:l:a",':',vect);

for(int i=0;i<c;i++)cout<<vect[i]<<" ";
}*/
void split(string text,char n,string *vect ){
    string aux="";

    int e=0;
    for(int i=0;i<text.length();i++){
                if(text[i]==n){
                    vect[e]=aux;
                    e++;
                    aux="";
                }else{
                  aux+=text[i];
                }
                if(apariciones(text,n)==e){
                    vect[e]=aux;
                    aux="";
                }
       }
       
  
}