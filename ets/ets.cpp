#include <iostream>
#include <string.h>
using namespace std;

struct Node{
	char nama[20];
	Node *left, *right, *parent;
};

Node *root, *newNode;

// create New Tree
void initTree( char nama[] )
{
    root = new Node();
    strcpy(root->nama, nama);
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << nama << " berhasil dibuat menjadi root." << endl;
}

Node *insertLeft(char nama[], Node *node){

      newNode = new Node();
      strcpy(newNode->nama, nama);
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << nama << " berhasil ditambahkan ke anak kiri " << newNode->parent->nama << endl;
      return newNode;
}

Node *insertRight(char nama[], Node *node){
	newNode = new Node();
	strcpy(newNode->nama, nama);
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->parent = node;
	node->right = newNode;
	cout << "\nNode " << nama << " berhasil ditambahkan di anak kanan " << newNode->parent->nama << endl;
	return newNode;
}

void update(char nama[], Node *node){
	char temp[20];
	strcpy(temp, node->nama);
	strcpy(node->nama, nama);
	cout << "\nNode " << temp << " berhasil diubah menjadi " << node->nama <<"\n";
}

void preOrder(Node *node = root){
	if (node != NULL){
		cout << node->nama << ", ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(Node *node = root){
	if(node != NULL){
		inOrder(node->left);
		cout << node->nama << ", ";
		inOrder(node->right);
	}
	
}

void postOrder(Node *node = root){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		cout << node->nama << ", ";
	}
}


int main(){
	//Root
	initTree("Opah");
	//Level 1
	Node *nodeRos, *nodeUpin, 
	//Level 2
	*nodeMeymey, *nodeFizi, *nodeIpin, *nodeOpet,
	//Level 3
	*nodeRaju, *nodeSusanti, *nodeJasmin, *nodeTokDalang, *nodeIjat, *nodeApin, 
	//Level 4
	*nodeMuthu, *nodeSaleh, *nodeDzul, *nodeEhsan, *nodeHamza, *nodePatrick, 
	//Level 5
	*nodeJarjit, *nodeMail, *nodeJake, *nodePaul, 
	//Level 6
	*nodeAhTong, *nodeSpeed;
	
	
	//Level 1
	nodeRos = insertLeft("Ros", root);
	nodeUpin = insertRight("Upin", root);
	
	//level 2
	nodeMeymey = insertLeft("Meymey", nodeRos);
	nodeFizi = insertRight("Fizi", nodeRos);
	nodeIpin = insertLeft("Ipin", nodeUpin);
	nodeOpet = insertRight("Opet", nodeUpin);
	
	//Level 3
	nodeRaju = insertLeft("Raju", nodeMeymey);
	nodeSusanti = insertRight("Susanti", nodeMeymey);
	nodeJasmin = insertLeft("Jasmin", nodeIpin);
	nodeTokDalang = insertRight("TokDalang", nodeIpin);
	nodeIjat = insertLeft("Ijat", nodeOpet);
	nodeApin = insertRight("Apin", nodeOpet);
	
	//Level 4
	nodeMuthu = insertLeft("Muthu", nodeRaju);
	nodeSaleh = insertRight("Saleh", nodeRaju);
	nodeDzul = insertLeft("Dzul", nodeSusanti);
	nodeEhsan = insertRight("Ehsan", nodeSusanti);
	nodeHamza = insertLeft("Hamza", nodeTokDalang);
	nodePatrick = insertRight("Patrick", nodeTokDalang);
	
	//Level 5
	nodeJarjit = insertLeft("Jarjit", nodeSaleh);
	nodeMail = insertRight("Mail", nodeSaleh);
	nodeJake = insertLeft("Jake", nodePatrick);
	nodePaul = insertRight("Paul", nodePatrick);
	
	//Level 6
	nodeAhTong = insertLeft("Ah Tong", nodeJarjit);
	nodeSpeed = insertRight("Speed", nodeJarjit);
	
	//Sebelum direname
	cout << "\npreOrder: \n";
	preOrder(root);
	cout <<"\n";
	
	cout << "\ninOrder: \n";
	inOrder(root);
	cout <<"\n";
	
	cout << "\npostOrder: \n";
	postOrder(root);
	cout <<"\n";
	
	//Update/rename
	cout <<"\nUpdate anggota keluarga:";
	update("Sally", nodeSaleh);
	
	
	//Setelah direname
	cout << "\npreOrder: \n";
	preOrder(root);
	cout <<"\n";
	
	cout << "\ninOrder:\n";
	inOrder(root);
	cout <<"\n";
	
	cout << "\npostOrder: \n";
	postOrder(root);
}

