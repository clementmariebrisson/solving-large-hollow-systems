#include "projet.h"

double somme_relaxation (vector< vector<double> > A, vector<double> xk,int i){
  double sum=0;
  int taille=A.size();
  for (int j=0;j<taille;j++){
    if (j!=i){
      sum+=A[i][j]*xk[j];
    }
    }
  return sum;
}

bool test_relaxation(vector<double> xk, vector<double> xk_plus1, int k){
  int taille=xk.size();
  double norme_2=0;
  if (k>0){
  for (int i=0;i<taille;i++){
    xk_plus1[i]-=xk[i];
  }
  for (int i=0;i<taille;i++){
    norme_2+=pow(xk_plus1[i],2);
  }
  if (sqrt(norme_2)<=pow(10,-2)){
    cout<<"E_2 = "<< sqrt( (1/taille) * norme_2 ) << endl;
    return true;
  }
}
  return false;
}


void Relaxation_methode (vector < vector<double> > A, vector<double> B){
  clock_t debut, fin ;
  debut = clock();
  double w;
  int k=0;
  cout<<"Veuillez entrer w :"<<endl;
  cin>>w;
  int taille= A.size();
  vector<double> xk(taille);
  vector<double> xk_plus1(taille);
  for (int i=0;i<taille;i++){
    xk[i]=0;
    xk_plus1[i]=0;
  }
  while (test_relaxation(xk,xk_plus1,k)==false ){
  for (int i=0;i<taille;i++){
      xk[i]=xk_plus1[i];
  }
  for (int i=0;i<taille;i++){
  xk_plus1[i]=w*(B[i]-somme_relaxation(A,xk_plus1,i))/A[i][i]+(1-w)*xk[i];
  }

  k++;
  }
  cout<<"Voici le  vecteur solution :"<<endl;
  cout<<" | ";
  for(int i=0;i<taille;i++){
    cout<<xk_plus1[i]<<" | "  ;
  }cout<<endl;
  cout<<"Il y a eu "<<k<<" itérations pour avoir une solution à 10^-7 près."<<endl;

  //temps CPU :
  fin = clock();
  double temps;
  temps = ((double)fin-debut) / CLOCKS_PER_SEC;
  cout<<"Temps CPU : "<<temps<<endl;

  //Erreur inf :
  double max=(xk_plus1[0]-xk[0]);
  for(int i=0;i<taille;i++){
    if(abs(xk_plus1[i]-xk[i])>max){
      max = abs(xk_plus1[i]-xk[i]) ;
    }
  }
  cout<<"Erreur_inf = max( ||xk+1 - xk ||inf )= "<< max << endl;
}
