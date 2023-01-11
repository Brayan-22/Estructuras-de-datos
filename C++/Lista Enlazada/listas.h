#ifndef LISTA_H
#define LISTA_H
template<typename T>
struct nodo{
	T info;
	nodo<T> *sig;
};
template<typename T>
class Lista{
	nodo<T> *cab;
	int tam;
	public:
		Lista(){
			cab=NULL;
			tam=0;
		}
		bool lista_vacia();
		int tam_lista();
		void insertar_final(T elem);
		bool eliminar(int pos);
		void insertar_pos(T elem,int pos);
};
//¿Lista vacia?
template<typename T>
bool Lista<T>::lista_vacia(){
	return (tam==0)?true:false;
}
//Tamaño de la lista
template<typename T>
int Lista<T>::tam_lista(){
	return tam;	
}
//insertar un elemento al final de la lista
template<typename T>
void Lista<T>::insertar_final(T elem){
	nodo<T> *p=new nodo<T>;
	p->info=elem;
	p->sig=NULL;
	if(cab==NULL){
		cab=p;
		tam++;
	}else{
		nodo<T> *aux=cab;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=p;
		tam++;
	}
}
//eleminar un elemento segun su posicion
template<typename T>
bool Lista<T>::eliminar(int pos){
	nodo<T> *aux=cab;
	if(lista_vacia()){
		return false;
	}else if(pos==1){
		cab=aux->sig;
		delete aux;
		tam--;
		return true;
	}else if(pos>=tam){
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		delete aux;
		tam--;
		return true;
	}else{
		for(int i=1;i<pos-1;i++){
			aux=aux->sig;
		}
		nodo<T> *aux1=aux->sig;
		aux->sig=aux1->sig;
		delete aux1;
		tam--;
		return true;
	}
}
//insertar un elemento en una posicion
template<typename T>
void Lista<T>::insertar_pos(T elem,int pos){
	nodo<T> *p=new nodo<T>;
	nodo<T> *aux=cab;
	p->info=elem;
	if(pos==tam){
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		p->sig=NULL;
		aux->sig=p;
		tam++;
	}else if(pos==1){
		p->sig=cab;
		cab=p;
		tam++;
	}else{
		for(int i=1;i<pos-1;i++){
			aux=aux->sig;
		}
		p->sig=aux->sig;
		aux->sig=p;
		tam++;
	}
}


#endif
