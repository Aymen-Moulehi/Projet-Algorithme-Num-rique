#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h> 



//Cette fonction permet de générer un nombre entre 0 et 100 .
float get_random_number(){
    return rand()%100 ;
}

//Cette fonction retourne le minimum entre deux nombre .
int min(int x ,int y){
    if(x<y)
    return x ;
    return y ;
}

//Cette fonction retourne le maximum entre deux nombre
int max(int x ,int y){
    if(x>y)
    return x ;
    return y ;
}

int valeurAbsolue(int x){
    if(x>=0)
    return x;
    return x * -1 ;
}
//Cette procédure permet l’affichage d’une matrice carrée
void affiche_matrice(float **mat,unsigned n){
    printf("\n\n-------------------------------------------------------------------------------------------------------------------------\n");
    unsigned i;
    unsigned j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]>9)
            printf("     %f     |",mat[i][j]);
            else
            printf("     %f      |",mat[i][j]);
        }
        
    printf("\n-------------------------------------------------------------------------------------------------------------------------\n");
        
    }
}

//Cette procédure permet de saisie une matrice à structure bande
void Saisie_M(float **mat,unsigned n,unsigned m){

    unsigned i,j ;
    for(i=0;i<n;i++){
        for(j=max(0,i-m+1);j<=min(n-1,n-(n-m)+i-1);j++){
            
            mat[i][j]= get_random_number() ;

        }

    }
}

void resolution_bande_superieure(float **mat,float *b,float *x,unsigned n,unsigned m){
    unsigned i,j,k ;
    for(k=0;k<n;k++){
        i=n-k-1;
        for(j=i;j<min(n,m+i);j++){
            x[i] = x[i] + mat[i][j]*x[j];
        }
        x[i] = (b[i] - x[i])/mat[i][i] ;
    }
}


void gauss(float **mat,unsigned n,unsigned m){
    unsigned i,j,p ; 
    for(p=0;p<n-1;p++){
        for(i=p+1;i<n;i++){
            for(j=max(p+1,i-m+1);j<=min(n-1,n-(n-m)+i-1);j++){
                mat[i][j] = mat[i][j] - mat[i][p]*mat[p][j] / mat[p][p] ;
            }
        }
    }

}








int main(){

    unsigned i ;
    unsigned j ;
    unsigned k = 0 ;
    unsigned n=4 ;
    unsigned m=2 ;
    float *x ;
    float valeurs[16]= {34,33,0,0,33,70,33,0,0,33,72,33,0,0,33,37} ;
    float b[4] = {22,45,69,12};
    float **mat = (float**)malloc(sizeof(float*)*n);

    for(i=0;i<n;i++){
        mat[i]=(float*)malloc(sizeof(float)*n);
        for(j=0;j<n;j++){
            mat[i][j]=valeurs[k];
            k++;
        }
    }
  
    affiche_matrice(mat,n);
    gauss(mat,n,m);

    affiche_matrice(mat,n);

    x = (float*)calloc(n,sizeof(float));
    resolution_bande_superieure(mat,b,x,n,m);

    for(i=0;i<n;i++){
        printf("%f ",x[i]);
    }  



}