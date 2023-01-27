#include "projet.h"

int main(){
  int n, m;
  cout<<"Entrer n et m pour définir le maillage de la matrice du Laplacien 2D."<<endl;
  cin>>n>>m;
  n = n*m;
  n = sqrt ( n );
  vector< vector < double > > A (n*n,vector < double > (n*n));
  A=matrice_laplacien(n);
  cout<<""<<endl;
  cout<<"La matrice du Laplacien 2D :"<<endl;
  for(int i=0;i<n*n;i++){
    for(int j=0;j<n*n;j++){
      cout<< A[i][j] <<" ";
    }cout<<endl;
  }

  //Cholesky :
  cout<< setw(15)<<""<<endl;
  cout<< setw(20) << " "
      << setw(15) << "Exécution de l'algorithme de Cholesky :" <<endl;
  if (symetrique(A)==0){
    cout<<"La matrice A n'est pas symétrique : Cholesky ne peut pas être appliqué."<<endl;
  }
  else {
    cout<<"La matrice A symetrique : on peut appliquer Cholesky."<<endl;
    cholesky(A);
    }

  //Relaxation
  cout<< setw(15)<<""<<endl;
  cout<< setw(20)<< ""
      << setw(15)<<"Execution de la relaxation :"<<endl;
  vector<double> B(n*n);
  int j;
  for (int i=0;i<n*n;i++){
    if( (i-n) > 0 ){
      j = i - n ;
      B[i] = ( i*i + j*j ) * sin(i*j);
    }
    else{
      j=0;
      B[i] = ( i*i + j*j ) * sin(i*j);;
    }
  }
  cout << "Vecteur B : ";
  for (int i=0;i<n*n;i++){
    cout<< B[i]<<" ";
  }cout<<" "<<endl;
  Relaxation_methode_creux(A,B);

  //A = LU :
  cout<< setw(15)<<""<<endl;
  cout<< setw(20)<< ""
      << setw(15)<<"Execution de A = L * U :"<<endl;
  vector<vector<double>>L(n*n,vector<double>(n*n));
  vector<vector<double>>U(n*n,vector<double>(n*n,0));//U=0;
  for(int i=0;i<n*n;i++){
    L[i][i]=1;  //L = Id(n)
  }
  clock_t debut, fin ;
  debut = clock();
  decomp_lu(A,L,U);  //décomposition L U :
  vector<double> x(n*n,0); //initialisation vecteur solution
  re_sys_lu(A,B,x); //résolution du système Ax=b grâce à decomp_lu:
  //temps CPU :
  fin = clock();
  double temps;
  temps = ((double)fin-debut) / CLOCKS_PER_SEC;
  cout<<"Temps CPU A = L * U: "<<temps<<endl;

  //JACOBI :
  cout<< setw(15)<<""<<endl;
  cout<< setw(20)<< ""
      << setw(15)<<"Execution de JACOBI :"<<endl;
  debut=clock();
  Jacobi (A,B);
  fin = clock();
  temps = ((double)fin-debut) / CLOCKS_PER_SEC;
  cout<<"Temps CPU Jacobi : "<<temps<<endl;
}
