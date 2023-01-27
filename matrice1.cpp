#include "projet.h"

vector< vector < double > > matrice_laplacien(int n){
  vector< vector < double > > A (n*n,vector < double > (n*n));
  vector< vector < double > > D (n,vector < double > (n));
  vector< vector < double > > I (n,vector < double > (n));
  for(int i=0;i<n;i++){
    I[i][i]=-1;
    D[i][i]=4;
    if(i!=n-1){
      D[i+1][i]=-1;
      D[i][i+1]=-1;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
          for(int l=0;l<n;l++){
              A[j+n*l][i+n*k]=I[i][j];
            }
          }

    }
  }
  for(int j=0;j<n;j++){
    for(int k=0;k<n;k++){
      A[(n)*(n)-1-j][k]=0;
      A[k][(n)*(n)-1-j]=0;

      }
    }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        A[k*n+i][k*n+j]=D[i][j];
      }
    }
  }

  // coefficients non nuls
  int nnz=0;
  for(int i=0;i<n*n;i++){
    for(int j=0;j<n*n;j++){
      if( A[i][j] != 0) {
        nnz++;
      }
    }
  }
  //nnz= n*n - nnz;
  cout<<"La matrice A contient "<<nnz<<" coefficients non nuls."<<endl;

  //Place mémoire de la matrice :
  const auto size { sizeof(A) };
  cout << "Place mémoire : " << size << endl;
  return A;
}
