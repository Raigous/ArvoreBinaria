#ifndef ARVORE
#define ARVORE

#include <stdlib.h>
#include <string>

#define max(n1,n2) (n1 > n2 ? n1 : n2)
#define height(n) (n == NULL ? 0 : n->h)

using namespace std;

template<typename T>
class Arvore{

	struct Node{
		T info;
		struct Node *l;
		struct Node *r;
		struct Node *p;

		unsigned int h;
	};
 public:
  Arvore();
  ~Arvore();
  Arvore(const Arvore<T> *a);
  unsigned int getCount() const;
	unsigned int getHeight() const;


	void insert(T o);
	void remove();
	void balance();
	std::string toString();
	
 protected:
  struct Node *root; 
	unsigned int count;
	std::string toStringAux(const struct Node *no);
};

template<typename T>
Arvore<T>::Arvore(){
  root = NULL; 
	count= 0;
}

template<typename T>
Arvore<T>::Arvore(const Arvore<T> *a){
	
}

template<typename T>
unsigned int Arvore<T>::getHeight() const{
	return height(root);
}

template<typename T>
unsigned int Arvore<T>::getCount() const{
	return count;
}

template<typename T>
std::string Arvore<T>::toString(){
	return toStringAux(root);
}

template<typename T>
std::string Arvore<T>::toStringAux(const Node *no){

	std::string str = "";
	
	if (no != NULL){
		str += "(";
		
		str += toStringAux(no->l);

		str += no->info;

		str += toStringAux(no->r);

		str += ")";
	}

	return str;
}

template<typename T>
Arvore<T>::~Arvore(){
  
}

template<typename T>
void Arvore<T>::remove(){
}

template<typename T>
void Arvore<T>::insert(T o){
	Node *no = root;
	
	if (root == NULL){
		root = (struct Node*) malloc(sizeof(struct Node));
		root->p = NULL;
		root->l = NULL;
		root->r = NULL;
		root->info = o;
		root->h = 1;
	}

	else
		while(1){
			if (o < no->info){
				
				if (no->l == NULL){
					no->l =	(struct Node*) malloc(sizeof(struct Node));
					no->l->info = o;
					no->l->l = NULL;
					no->l->r = NULL;
					no->l->p = no;
					
					no = no->l;
					break;
				}
				no = no->l;
				continue;
			}

			if (o > no->info){
				
				if (no->r == NULL){
					no->r =	(struct Node*) malloc(sizeof(struct Node));
					no->r->info = o;
					no->r->l = NULL;
					no->r->r = NULL;
					no->r->p = no;
					
					no = no->l;
					break;
				}

				no = no->r;
				continue;
			 }

			return;
			break;
		}

	while(no != NULL){
		no->h = max(height(no->l),height(no->r)) + 1;
		no = no->p;
	}
}

template<typename T>
void Arvore<T>::balance(){
	
}

#endif
