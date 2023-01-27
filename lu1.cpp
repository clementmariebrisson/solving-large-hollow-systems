#include "projet.h"
void affichage(vector<vector <double> > mat){
  int taille=mat.size();
  for(int i=0;i<taille;i++){
    for(int j=0;j<taille;j++){
      cout<<mat[i][j]<<" ";
    }cout<<" "<<endl;
  }
}

void decomp_lu(vector<vector<double>>mat,vector<vector<double>>& L,vector<vector<double>>& U){
  int n=mat.size();
  vector<vector<double>>A;
  A=mat;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      L[j][i]=mat[j][i]/mat[i][i];
    }
    for(int j=i;j<n;j++){
      U[i][j]=mat[i][j];
    }
    for(int j=i+1;j<n;j++){
      for(int k=i+1;k<n;k++){
        mat[j][k]-=L[j][i]*U[i][k];
      }
    }
  }
  U[n-1][n-1]=mat[n-1][n-1];

  //Vérification de la décomposition A = L * U :
  vector<vector<double>>LU(n,vector<double>(n));
  vector<vector<double>>res(n,vector<double>(n));
  LU=prod_mat(L,U);
  double sum=0.0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      res[i][j]=A[i][j]-LU[i][j]; //calcul de A - L*U
      sum+=abs(res[i][j]); //calcul de ||A - L*U ||
    }
  }
  cout<<"||A - L*U || = "<<sum<<endl;
  if(sum<0.1){cout<<"On a bien A = L*U"<<endl;}
  else{cout<<"error"<<endl;}
}
vector< double > prod_mat_vec(vector< vector<double> > A, vector <double> vec){
  int taille;
  taille=vec.size();
  vector<double> res(taille,0);
  for(int i=0;i<taille;i++){
    for(int j=0;j<taille;j++){
      res[i]+=vec[j]*A[j][i];
    }
  }
  return res;
}
void re_sys_lu(vector<vector<double>>mat,vector<double>b,vector<double>x){
  //initialisation des matrices :
  int n=mat.size();
  vector<vector<double>>L(n,vector<double>(n));
  vector<vector<double>>U(n,vector<double>(n,0));//U=0;
  for(int i=0;i<n;i++){
    L[i][i]=1;  //L = Id(n)
  }
  decomp_lu(mat,L,U);
  if(sqrt(n)<4){
    cout<<"la matrice L :"<<endl;  affichage(L);//affichage de L
    cout<<"la matrice U :"<<endl;  affichage(U);//affichage de U
  }
  //Résolution du système L*y = b où y = U*x :
  //DESCENTE:
  vector<double>y(n);
  y[0]=b[0];
  y[1]=b[1]-L[1][0]*y[0];
  double sum=0.0;
  for(int i=1;i<n;i++){
    sum=0.0;
    for(int j=0;j<i;j++){
      sum+=L[i][j]*y[j];
    }
    y[i]=(b[i]-sum)/L[i][i];
  }
  //Résolution du système U*x = y :
  //REMONTEE :
  double sum1=0.0;
  x[n-1]=y[n-1]/U[n-1][n-1];
  for(int i=n-2;i>=0;i--){
    sum1=0.0;
    for(int j=n-1;j>i;j--){
      sum1 += U[i][j]*x[j];
    }
    x[i]=(y[i] - sum1)/U[i][i];
  }
  if(sqrt(n)<4){
    cout<<"Voici le vecteur solution x, du système Ax=b : "<<endl;
    for(int i=0;i<n;i++){
      cout<<x[i]<<endl;
    }
  }
}
