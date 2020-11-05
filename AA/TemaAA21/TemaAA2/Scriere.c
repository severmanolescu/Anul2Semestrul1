//#include <stdio.h>
//#include <stdlib.h>
//
//void main(void)
//{
//	int i = 0;
//
//	FILE* g;
//	g = fopen("INPUT.DAT", "wb");
//
//	i = 8;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 6;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 11;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 5;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 7;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 10;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 13;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 4;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 9;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 12;
//	fwrite(&i, 1, sizeof(int), g);
//
//	i = 14;
//	fwrite(&i, 1, sizeof(int), g);
//
//	return 0;
//}
////#include <stdio.h>
////#include <stdlib.h>
////#include <time.h>
////
////#define N 5000
////
////unsigned int tab[N]; // variabilele globale sunt initializate automat pe zero
////
////
////// returneaza true sau false
////int cauta(unsigned int num) {
////	int i;
////	for (i = 0; i < N; i++) {
////		if (tab[i] == num) return 1; // true, gasit
////	}
////	return 0; // false, numar negasit
////}
////
////int main(void) {
////	FILE* fp;
////	int i;
////	unsigned int num;
////
////	fp = fopen("INPUT.DAT", "wb");
////	if (fp == NULL) {
////		perror("fopen()");
////		return -1;
////	}
////
////	srand(time(NULL)); // Initializare generator de numere pseudo-random
////
////	for (i = 0; i < N; i++) {
////		num = rand() % 10000;
////		if (cauta(num)) { i--; continue; }
////		else tab[i] = num;
////	}
////
////	for (i = 0; i < N; i++) {
////		if (fwrite(&tab[i], sizeof(unsigned int), 1, fp) == 0) {
////			printf("Eroare la scriere\n");
////			return -1;
////		}
////	}
////
////	fclose(fp);
////
////}

///*   if (balanta == -2 && Balansare(arb->FiuDrept) < 0)
 //   {
 //       printf("123");
 //       return RotireDreapta2(arb, arb);
 //   }

 //   if (balanta == 2 && Balansare(arb->FiuStang) > 0)
 //   {
 //       
 //     */  return RotireStanga2(arb, arb);
 //   }

//struct Arbore* RotireStanga2(struct Arbore* a, struct Arbore* arb) {
//
//    struct Arbore* arbL = arb->FiuStang;
//    struct Arbore* arbLR = arbL->FiuDrept;
//
//    arbL->FiuDrept = arb;
//    arb->FiuStang = arbLR;
//
//    arb->inaltime = inaltime(arb);
//    arbL->inaltime = inaltime(arb->FiuStang);
//
//    if (arb == a)
//        a = arbL;
//
//    return arbL;
//
//}

//struct Arbore* RotireDreapta2(struct Arbore* a, struct Arbore* arb)
//{
//    // Exemplu:
//    // Inainte de Rotire:            Dupa rotire:
//    //        arb                        arbDStanga
//    //       /   \                     /      \
//    //      x  arbDreapta          arb    arbDreapta
//    //          /   \               /   \     /   \
//    //   arbDStanga  y             x   NULL  aux   y
//    //       /
//    //     aux
//
//    struct Arbore* arbDreapta  = arb->FiuDrept;
//    struct Arbore* arbDStanga = arbDreapta->FiuStang;
//    struct Arbore* aux   = arbDStanga->FiuDrept;
//
//    arbDStanga->FiuStang = arb;
//    arb->FiuDrept   = NULL;
//    arbDStanga->FiuDrept = arbDreapta;
//    arbDreapta->FiuStang  = aux;
//
//    arbDStanga->inaltime = Maxim(inaltime(arbDStanga->FiuStang), inaltime(arbDStanga->FiuDrept)) + 1;
//    arbDreapta->inaltime = Maxim(inaltime(arbDreapta->FiuStang), inaltime(arbDreapta->FiuDrept)) + 1;
//
//    if (aux != NULL)
//        aux->inaltime = Maxim(inaltime(aux->FiuStang), inaltime(aux->FiuDrept)) + 1;
//
//    arb->inaltime  = Maxim(inaltime(arb->FiuStang), inaltime(arb->FiuDrept)) + 1;
//
//    if (arb == arbDStanga)
//        return arbDreapta;
//
//    return arbDStanga;
//}

//struct Arbore* LLRotation(struct Arbore* a, struct Arbore* arb) {
//
//    struct Arbore* arbL = arb->FiuStang;
//    struct Arbore* arbLR = arbL->FiuDrept;
//
//    arbL->FiuDrept = arb;
//    arb->FiuStang = arbLR;
//
//    arb->inaltime = inaltime(arb);
//    arbL->inaltime = inaltime(arb->FiuStang);
//
//    if (arb == a)
//        a = arbL;
//
//    return arbL;
//
//}
//
//// LR Rotation
//struct Arbore* LRRotation(struct Arbore* a, struct Arbore* arb) {
//
//    struct Arbore* arbL = arb->FiuStang;
//    struct Arbore* arbLR = arbL->FiuDrept;
//
//    arbL->FiuDrept = arbLR->FiuStang;
//    arb->FiuStang = arbLR->FiuDrept;
//    arbLR->FiuStang = arbL;
//    arbLR->FiuDrept = arb;
//
//    arb->inaltime = inaltime(arb);
//    arbL->inaltime = inaltime(arbL);
//    arbLR->inaltime = inaltime(arbLR);
//
//    if (arb == a)
//        a = arbLR;
//
//    return arbLR;
//
//}
//
//// RR Rotation

//
//// RL Rotation
//struct Arbore* RLRotation(struct Arbore* a, struct Arbore* arb) {
//
//    struct Arbore* arbDreapta = arb->FiuDrept;
//    struct Arbore* arbDStanga = arbDreapta->FiuStang;
//
//    arbDreapta->FiuStang = arbDStanga->FiuDrept;
//    arb->FiuDrept = arbDStanga->FiuStang;
//    arbDStanga->FiuStang = arb;
//    arbDStanga->FiuDrept = arbDreapta;
//
//    arb->inaltime = inaltime(arb);
//    arbDreapta->inaltime = inaltime(arbDreapta);
//    arbDStanga->inaltime = inaltime(arbDStanga);
//
//    if (arb == a)
//        a = arbDStanga;
//
//    return arbDStanga;
//
//}
//
//struct Arbore* deleteNode(struct arbore* a, struct Arbore* arb, int cheie) {
//
//    // If there's no node to be deleted
//    if (arb == NULL)
//        return NULL;
//
//    // If the node is a leaf node
//    if (arb->FiuStang == NULL && arb->FiuDrept == NULL) {
//        // If it's the a node, make a NULL after deletion
//        if (arb == a)
//            a = NULL;
//        //// Free the memory
//        free(arb);
//        return NULL;
//    }
//
//    // If value to be deleted is lesser, go to FiuStang subtree
//    if (cheie < arb->cheie)
//        arb->FiuStang = deleteNode(a, arb->FiuStang, cheie);
//
//    // If value to be deleted is greater, go to FiuDrept subtree
//    else if (cheie > arb->cheie)
//        arb->FiuDrept = deleteNode(a, arb->FiuDrept, cheie);
//
//    // Deleting the node once it's found
//    else {
//        // Delete from the subtree which has greater inaltime
//        if (inaltime(arb->FiuStang) > inaltime(arb->FiuDrept)) {
//
//            // Find the inorder predecessor for FiuStang subtree
//            struct Arbore* inPre = ValoareMaxima(arb->FiuStang);
//            arb->cheie = inPre->cheie;
//            arb->FiuStang = deleteNode(a, arb->FiuStang, inPre->cheie);
//
//        }
//        else {
//
//            // Find the inorder successor for FiuDrept subtree
//            struct Arbore* inSuc = ValoareMaxima(arb->FiuStang);
//            arb->cheie = inSuc->cheie;
//            arb->FiuDrept = deleteNode(a, arb->FiuDrept, inSuc->cheie);
//
//        }
//    }
//
//    // Set new inaltime
//    arb->inaltime = 1 + inaltime(arb);
//
//    if (Balansare(arb) == 2 && Balansare(arb->FiuStang) == 1)
//        return LLRotation(a, arb);
//
//    else if (Balansare(arb) == 2 && Balansare(arb->FiuStang) == -1)
//        return LRRotation(a, arb);
//
//    else if (Balansare(arb) == 2 && Balansare(arb->FiuStang) == 0)
//        return LLRotation(a, arb);
//
//    else if (Balansare(a, arb) == 2 && Balansare(arb->FiuDrept) == 1)
//        return RotireDreapta2(a, arb); 
//
//    else if (Balansare(a, arb) == 2 && Balansare(arb->FiuDrept) == -1)
//        return RLRotation(a, arb);
//
//    else if (Balansare(a, arb) == 2 && Balansare(arb->FiuDrept) == 0)
//        return RotireDreapta2(a, arb);  	//R 0 Rotation
//
//    return arb;
//
//}