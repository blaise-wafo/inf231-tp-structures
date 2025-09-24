#include <stdio.h>
#include <stdlib.h>

// ========================== FONCTIONS ==========================

// 1. Somme de matrices
void sommeMatrices(int m, int n) {
    int A[50][50], B[50][50], C[50][50];
    printf("Entrez la matrice A (%dx%d):\n", m, n);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
    printf("Entrez la matrice B (%dx%d):\n", m, n);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&B[i][j]);

    for(int i=0;i<m;i++) for(int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];

    printf("Somme A+B :\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) printf("%d ",C[i][j]);
        printf("\n");
    }
}

// 2. Produit de matrices
void produitMatrices(int m, int n, int p) {
    int A[50][50], B[50][50], C[50][50];
    printf("Entrez la matrice A (%dx%d):\n", m, n);
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
    printf("Entrez la matrice B (%dx%d):\n", n, p);
    for(int i=0;i<n;i++) for(int j=0;j<p;j++) scanf("%d",&B[i][j]);

    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            C[i][j]=0;
            for(int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];
        }
    }
    printf("Produit A*B :\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++) printf("%d ",C[i][j]);
        printf("\n");
    }
}

// 3. Recherche séquentielle
void rechercheSeq(int n) {
    int T[100], x;
    printf("Entrez %d elements du tableau:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&T[i]);
    printf("Entrez l'element a chercher: ");
    scanf("%d",&x);

    int trouve=0;
    for(int i=0;i<n;i++){
        if(T[i]==x){ trouve=1; break; }
    }
    if(trouve) printf("%d est present.\n",x);
    else printf("%d n'est pas present.\n",x);
}

// 4. Multiplication avec uniquement +1
void multAvecPlus(int a, int b) {
    int produit=0;
    for(int i=0;i<b;i++) produit+=a;
    printf("%d x %d = %d\n",a,b,produit);
}

// 5. Tester si tableau est trié
void testTrie(int n) {
    int T[100];
    printf("Entrez %d elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&T[i]);

    int trie=1;
    for(int i=0;i<n-1;i++){
        if(T[i]>T[i+1]){ trie=0; break; }
    }
    if(trie) printf("Le tableau est trie.\n");
    else printf("Le tableau n'est pas trie.\n");
}

// 6. Médiane
void mediane(int n) {
    int T[100];
    printf("Entrez %d elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&T[i]);

    // tri simple
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(T[j]>T[j+1]){
                int tmp=T[j]; T[j]=T[j+1]; T[j+1]=tmp;
            }
        }
    }

    if(n%2==1) printf("Mediane = %d\n",T[n/2]);
    else printf("Mediane = %.2f\n",(T[n/2-1]+T[n/2])/2.0);
}

// 7. Inverser un tableau
void inverser(int n) {
    int T[100];
    printf("Entrez %d elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&T[i]);

    for(int i=0;i<n/2;i++){
        int tmp=T[i]; T[i]=T[n-1-i]; T[n-1-i]=tmp;
    }
    printf("Tableau inverse:\n");
    for(int i=0;i<n;i++) printf("%d ",T[i]);
    printf("\n");
}

// 8. Produit vectoriel (vecteurs 3D)
void produitVectoriel() {
    int u[3], v[3], r[3];
    printf("Entrez le vecteur U(x y z): "); for(int i=0;i<3;i++) scanf("%d",&u[i]);
    printf("Entrez le vecteur V(x y z): "); for(int i=0;i<3;i++) scanf("%d",&v[i]);

    r[0]=u[1]*v[2]-u[2]*v[1];
    r[1]=u[2]*v[0]-u[0]*v[2];
    r[2]=u[0]*v[1]-u[1]*v[0];

    printf("U x V = (%d, %d, %d)\n",r[0],r[1],r[2]);
}

// 9. Produit vecteur x matrice
void vecteurMatrice(int n, int p) {
    int V[50], M[50][50], R[50];
    printf("Entrez le vecteur V de taille %d:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&V[i]);
    printf("Entrez la matrice (%dx%d):\n",n,p);
    for(int i=0;i<n;i++) for(int j=0;j<p;j++) scanf("%d",&M[i][j]);

    for(int j=0;j<p;j++){
        R[j]=0;
        for(int i=0;i<n;i++) R[j]+=V[i]*M[i][j];
    }
    printf("Resultat V*M : ");
    for(int j=0;j<p;j++) printf("%d ",R[j]);
    printf("\n");
}

// ========================== PROGRAMME PRINCIPAL ==========================
int main() {
    int choix;
    do {
        printf("\n==== MENU TP STRUCTURES DE DONNEES II ====\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle\n");
        printf("4. Multiplication avec + seulement\n");
        printf("5. Tester si tableau trie\n");
        printf("6. Mediane\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel\n");
        printf("9. Produit vecteur x matrice\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d",&choix);

        switch(choix){
            case 1: {int m,n; printf("Entrez m et n: "); scanf("%d%d",&m,&n); sommeMatrices(m,n); break;}
            case 2: {int m,n,p; printf("Entrez m,n,p: "); scanf("%d%d%d",&m,&n,&p); produitMatrices(m,n,p); break;}
            case 3: {int n; printf("Taille du tableau: "); scanf("%d",&n); rechercheSeq(n); break;}
            case 4: {int a,b; printf("Entrez a et b: "); scanf("%d%d",&a,&b); multAvecPlus(a,b); break;}
            case 5: {int n; printf("Taille du tableau: "); scanf("%d",&n); testTrie(n); break;}
            case 6: {int n; printf("Taille du tableau: "); scanf("%d",&n); mediane(n); break;}
            case 7: {int n; printf("Taille du tableau: "); scanf("%d",&n); inverser(n); break;}
            case 8: produitVectoriel(); break;
            case 9: {int n,p; printf("Entrez n et p: "); scanf("%d%d",&n,&p); vecteurMatrice(n,p); break;}
            case 0: printf("Fin du programme.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while(choix!=0);
    return 0;
}
