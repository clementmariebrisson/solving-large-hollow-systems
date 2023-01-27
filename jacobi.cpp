#include "projet.h"

/*vector< vector<double> > remplissage_matrice(){
  cout<<"Entrez taille matrice"<<endl;
  int taille;
  cin>>taille;
  vector< vector<double> > mat(taille, vector<double>(taille));
  cout<<"---Remplissage matrice---"<<endl;
  for (int i=0;i<taille;i++){
    for (int j=0;j<taille;j++){
      cin>>mat[i][j];
    }
  }
  return mat;
}*/

double somme( vector< vector<double> > A, vector<double> x,int i){
  double sum=0;
  int taille = A.size();
    for (int j=0;j<taille;j++){
      if (j!=i){
      sum+=A[i][j]*x[j];

    }
    }
  return sum;
}

void affichage_( vector<double> vec){
  cout<<"-Vecteur solution-"<<endl;
  int taille=vec.size();
  for (int i=0;i<taille;i++){
    cout<<vec[i]<<" ; ";
  }cout<<endl;
}

void Jacobi (vector< vector<double> > mat,vector<double> b ){
  int taille=mat.size();
  //vector<double> b(taille);
  vector<double> x(taille);    //Correspond a x(k)
  vector<double> x_1(taille);  //Correspond a x(k+1)
  vector<double> x_(taille);   //Pour le calcul de l'erreur
  /////////////////////////
  for (int i=0;i<taille;i++){
    x[i]=0;                    //Remplissage vecteur de 0 pour eviter initialisation aléatoire
  }
  int but;
  cout<<"---Entrez Nombre itérations souhaitées"<<endl;
  cin>>but;
  /////////////////////////
  for (int k=0;k<but;k++){
    for (int i=0;i<taille;i++){
        x_1[i]=(b[i]-somme(mat,x,i))/mat[i][i];

    }
    for (int i=0;i<taille;i++){
      x_[i]=x[i];
      x[i]=x_1[i];                 //Suite sous forme de tableau on remplit x(k)=x(k+1).......................
    }

  }
  cout<<"---Itération numéro :"<<but<<endl;
  affichage_(x_1);
  //Erreur inf :
  double max=(x_1[0]-x_[0]);
  for(int i=0;i<taille;i++){
    if(abs(x_1[i]-x_[i])>max){
      max = abs(x_1[i]-x_[i]) ;
    }
  }
  cout<<"Erreur_inf = max( ||xk+1 - xk ||inf )= "<< max << endl;
}
