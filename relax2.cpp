#include "projet.h"

double somme_relaxation_creux (int taille, vector< vector<double> > A_creux, vector<double> xk,int i){
  double sum=0.0;
  for (int j=0;j<taille;j++){
    if (j!=i){
      for(int k = 0 ; k<taille ; k++ ){
        if(A_creux[k][1]==i){
          if(A_creux[k][2]==j){
            sum+=A_creux[k][0]*xk[j];
          }
          else{
            sum+=0*xk[j];
          }
        }
        else{
          sum+=0*xk[j];
        }
      }
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
  if (sqrt(norme_2)<=pow(10,-7)){
    cout<<"E_2 = "<< sqrt( (1/taille) * norme_2 ) << endl;
    return true;
  }
}
  return false;
}


void Relaxation_methode_creux (vector < vector<double> > A, vector<double> B){
  cout<<"Version creuse."<<endl;
  clock_t debut, fin ;
  debut = clock();
  double w;
  int k=0;
  cout<<"Veuillez entrer w :"<<endl;
  cin>>w;
  int taille= A.size();
  vector< vector<double> > A_creux(taille, vector<double>(3));
  vector< double> Diag_A(taille);
  for (int i=0;i<taille;i++){
    Diag_A[i]=A[i][i];
    for (int j=0;j<taille;j++){
      if(A[i][j] != 0){
        A_creux[i][0]=A[i][j];
        A_creux[i][1]=i;
        A_creux[i][2]=j;
      }
    }
  }
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
  xk_plus1[i]=w*(B[i]-somme_relaxation_creux(taille, A_creux,xk_plus1,i))/Diag_A[i]+(1-w)*xk[i];
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
