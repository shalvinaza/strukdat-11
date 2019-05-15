/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi: Program tree
Tahun    : 2019
*/
#include<iostream>
#include<windows.h>
using namespace std;

struct Simpul {
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createTree (Tree& root){
    root = NULL;
}
void createSimpul (pointer& pBaru){
    pBaru = new Simpul;
    cout << "Masukkan satu angka : "; cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}
void insertBST (Tree& root, pointer pBaru){
    if(root == NULL){
        root = pBaru;
    }
    else if(pBaru->info < root->info){
        insertBST(root->left,pBaru);
    }
    else if(pBaru->info >= root->info){
        insertBST(root->right,pBaru);
    }
    else {
        cout << "\nDATA SUDAH ADA\n";
    }
}
void preOrder(Tree root){
    if(root != NULL){
        cout << root->info << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder (Tree root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->info << endl;
        inOrder(root->right);
    }
}
void postOrder(Tree root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << endl;
    }
}
int height(Tree root){
    if (root == NULL){
        return 0;
    }
    else {
        int leftDepth = height(root->left);
        int rightDepth = height(root->right);
        if(leftDepth > rightDepth){
            return(leftDepth + 1);
        }
        else {
            return (rightDepth + 1);
        }
    }
}
void printGivenLevel(Tree root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->info << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
void kedalaman(Tree root){
    int h = height(root);
    for(int i = 1; i<=h; i++){
        cout << "Kedalaman "<<i-1<< " : ";
        printGivenLevel(root,i);
        cout << endl;
    }
}
void tingkat(Tree root){
    int h = height(root);
    for(int i = 1; i<=h; i++){
        cout << "Kedalaman "<<i<< " : ";
        printGivenLevel(root,i);
        cout << endl;
    }
}
void anak(Tree root, pointer pBaru){
    pBaru = root;
    if(pBaru != NULL){
        cout << "Ayah\t : " << pBaru->info << endl;
        if(pBaru->left == NULL){
            cout << "Kiri\t : Tidak ada\n";
        }
        else {
            cout << "Kiri\t : " << pBaru->left->info << endl;
        }
        if(pBaru->right == NULL){
            cout << "Kanan\t : Tidak ada\n";
        }
        else{
            cout << "Kanan\t : "<< pBaru->right->info << endl;
        }
        cout << endl;
        anak(root->left,pBaru);
        anak(root->right,pBaru);
    }
}
main (){
    Tree t;
    pointer p;
    int n, menu, key, ketemu;
    char pilih;

    createTree(t);
    do {
        start:
        cout << "1. Insert BST\n";
        cout << "2. Pre Order\n";
        cout << "3. In Order\n";
        cout << "4. Post Order\n";
        cout << "5. Kedalaman\n";
        cout << "6. Level\n";
        cout << "7. Anak\n";
        cout << "8. Keluar\n";
        cout << "Pilih menu (1-10) : "; cin >> menu;
        system("cls");
        if (menu < 1 || menu >8)
            goto start;
    switch(menu) {
    case 1 :
        cout << "Masukkan banyak data : "; cin >> n;
        for(int i=0; i<n; i++){
        createSimpul(p);
        insertBST(t,p);
        system("cls");
        }
        break;
    case 2 :
        preOrder(t);
        break;
    case 3 :
        inOrder(t);
        break;
    case 4 :
        postOrder(t);
        break;
    case 5 :
        kedalaman(t);
        break;
    case 6 :
        tingkat(t);
        break;
    case 7 :
        anak(t,p);
        break;
    case 8 :
        exit(0);
        break;
    }cout << "\nApakah anda ingin mengulang program (y/n) : "; cin >> pilih;
    system("cls");
    }while(pilih == 'Y' || pilih == 'y');
}
