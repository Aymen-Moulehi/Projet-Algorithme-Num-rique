#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h> 



//Cette fonction permet de générer un nombre entre 0 et 100 .
float get_random_number(){
    srand(time(NULL));
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

//Cette fonction permet de retourner la valeur absolue d’un nombre .
int valeurAbsolue(int x){
    if(x>=0)
    return x;
    return x * -1 ;
}

//Cette procédure permet de saisie une matrice à structure bande
void Saisie_M(float **mat,unsigned n,unsigned m){

    unsigned i,j ;

    for(i=0 ;i<n-m-1 ;i++){
        for(j=i+1 ; j<=i+m ; j++){
            mat[i][j]=get_random_number();
            mat[i][i]+=mat[i][j]+1;
        }
    }

    for(i=n-m-1 ;i<n ;i++){
        for(j=i+1 ; j<n ; j++){
            mat[i][j]=get_random_number();
            mat[i][i]+=mat[i][j]+2;
        }
    }

    for(i=1 ;i<=m ;i++){
        for(j=0 ; j< i ; j++){
            mat[i][j]=get_random_number();
            mat[i][i]+=mat[i][j]+3;
        }
    }

    for(i=m+1 ;i<n ;i++){
        for(j=i-m ; j<=i-1 ; j++){
            mat[i][j]=get_random_number();
            mat[i][i]+=mat[i][j]+4;
        }
    }
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

//Cette procédure permet le remplissage du vecteur
void Saisie_V(float *vect,unsigned n){
    unsigned i;
    for(i=0;i<n;i++){
        vect[i]=get_random_number();
    }
}

//Cette procédure permet l’ affichage d'un vecteur 
void Affiche_V(float *vect,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf(" %f |",vect[i]);
       

    }
    printf("\n");
}


void resolution_sup(float **M , float *b, float *x , unsigned n,unsigned m)
{
    int i,j;
    for(i=n-1;i>=0;i--){
        x[i]=b[i];
        for(j=i+1;j<min(n,m+i);j++){
            x[i]-=M[i][j]*x[j];

        }
        x[i]=x[i]/M[i][i];
    }
}


void gauss(float **mat,float *b,unsigned n,unsigned m){
    unsigned i,j,p ; 
    for(p=0;p<n-1;p++){
        for(i=p+1;i<n;i++){
            mat[i][p] /= mat[p][p] ;
            b[i]/= mat[p][p] ;

            for(j=max(p+1,i-m);j<=min(n-1,i+m+1);j++){
                mat[i][j] = mat[i][j] - mat[i][p]*mat[p][j];
            }
            
            b[i]= b[i]-mat[i][p] * b[p] ;
            
        }
        
    }

}








int main(){

    unsigned i,j;
    unsigned n=3 ;
    unsigned m=1 ;
    
    //vecteur X
    float *x ;
    x = (float*)calloc(n,sizeof(float));
    //vecteur B
    float b[4]={22,45,69};
    //Matrice M
    float **mat = (float**)malloc(sizeof(float*)*n);
    
    for(i=0;i<n;i++){
        mat[i]=(float*)calloc(n,sizeof(float));
    }


    Saisie_M(mat,n,m);
    printf("\n remplissage de la matrice est terminé");
    printf("\n\n\n Matrice M \n m = %d \n n = %d \n",m,n);
    affiche_matrice(mat,n);
    printf("\n Applique de Gause voici le résultat");
    gauss(mat,b,n,m);
    Affiche_V(b,n);
    affiche_matrice(mat,n);


    printf("\n Le résultat de notre Système \n");
    resolution_sup(mat,b,x,n,m);

    Affiche_V(x,n);

    printf("\n :) \n");

    return 0;
}