# Projet algorithme numérique

Tout le contenu du fichier readme.md est basé sur le fichier Version2.c  

## Question 1 :
Je dévisse la matrice sur 4 parties comme cette image représente tout dépend la valeur de m et n .
![alt text](https://github.com/Aymen-Moulehi/Projet-Algorithme-Num-rique/blob/main/capture/capture2.png)
##
On trouve alors 4 boucles for pour chaque partie en assurant que la valeur de chaque nombre au diagonale égale  somme de la ligne correspond 

```c
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
```

## Question 2 :
Cette procédure permet l’affichage d’une matrice carrée
```c
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

```
## Question 3 :
Cette procédure permet le remplissage du vecteur
```c

void Saisie_V(float *vect,unsigned n){
    unsigned i;
    for(i=0;i<n;i++){
        vect[i]=get_random_number();
    }
}
```
## Question 4 :
Cette procédure permet l’ affichage d'un vecteur 
```c
void Affiche_V(float *vect,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf(" %f |",vect[i]);
       

    }
    printf("\n");
}
```
## Question 5 :
Résoudre le système par la méthode d’élimination de Gauss
# Etape de triangularisation


```c
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
```
# Résolution d’un système triangulaire dont la matrice est triangulaire supérieure demi-bande
```c
void gauss(float **mat,unsigned n,unsigned m){
    unsigned i,j,p ; 
    for(p=0;p<n-1;p++){
        for(i=p+1;i<n;i++){
            mat[i][p] /= mat[p][p] ;
            for(j=max(p+1,i-m);j<=min(n-1,i+m+1);j++){
                mat[i][j] = mat[i][j] - mat[i][p]*mat[p][j];
            }
        }
    }

}
```
## Programme principale (main): 
```c
int main(){

    unsigned i,j;
    unsigned n=4 ;
    unsigned m=1 ;
    
    //vecteur X
    float *x ;
    x = (float*)calloc(n,sizeof(float));
    //vecteur B
    float b[4]={22,45,69,12};
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
    gauss(mat,n,m);
    affiche_matrice(mat,n);


    printf("\n Le résultat de notre Système \n");
    resolution_sup(mat,b,x,n,m);

    Affiche_V(x,n);

    printf("\n :) \n");

    return 0;
}
```

# Résultats d'exécution
![alt text](https://github.com/Aymen-Moulehi/Projet-Algorithme-Num-rique/blob/main/capture/capture1.png)
