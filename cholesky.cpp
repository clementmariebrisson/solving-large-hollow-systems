#include "projet.h"

vector< vector<double> > remplissage (vector< vector<double> >& vec){
  cout<<"Remplissage matrice A :"<<endl;
  int t=vec.size();
  for (int i=0;i<t;i++){
    for (int j=0;j<t;j++){
      cin>>vec[i][j];
    }
  }
  return vec;
}
vector<vector<double>> prod_mat(vector<vector<double>> L,vector<vector<double>> U){
  int taille=L.size();
  vector< vector <double> > res(taille,vector<double>(taille));
  for(int i=0;i<taille;i++){
    for(int j=0;j<taille;j++){
      res[i][j]=0;
      for(int k=0;k<taille;k++){
        res[i][j]+=L[i][k]*U[k][j];
      }
    }
  }
  return res;
}
bool symetrique (vector< vector<double> > vec){
  int t=vec.size();
  for (int i=0;i<t;i++){
    for (int j=0;j<t;j++){
      if (vec[i][j]!=vec[j][i]){
        return false;
      }
    }
  }
  return true;
}

void Affichage (vector< vector<double> > vec){
  cout<<"Affichage Matrice LLt :"<<endl;
  int t=vec.size();
  for (int i=0;i<t;i++){
    for (int j=0;j<t;j++){
      if(abs(vec[i][j])<0.1){
        cout<<0<<" ";
      }
      else{
        cout<<vec[i][j]<<" ";
      }
    }cout<<endl;
  }
}

void cholesky( vector< vector<double> > vec);

double sum(vector< vector<double> > vec,int j,int z){
  double s=0;
  for (int i=0;i<j;i++){
    s=s+pow(vec[z][i],2);
  }
  return s;
}


void cholesky( vector< vector<double> > A){
  clock_t debut, fin ;
  debut = clock();
  int n=A.size();
 vector< vector<double> > L(n, vector<double> (n));
 L[0][0]=sqrt(A[0][0]);
 for (int i = 0; i < n; i++) {
     for (int j = 0; j <= i; j++) {
         double sum = 0;

         if (j == i) // somme des diagonales
         {
             for (int k=0; k<j; k++){
                 sum += pow(L[j][k], 2);
               }

             L[j][j] = sqrt(A[j][j]-sum);
         } else {
             // calcul de L(i, j) grace a L(j, j)
             for (int k=0;k<j;k++)
                 sum+=(L[i][k]*L[j][k]);
             L[i][j]=(A[i][j]-sum)/L[j][j];
         }
     }
 }
cout<<setw(5)<<" Triangulaire inférieure"<<endl;
     for (int i=0; i<n; i++) {
          // Transposée de la Triangulaire inférieure
          for (int j=0;j<n;j++)
              cout << setw(4) << L[i][j] << "\t";
          cout << endl;
      }
cout<<setw(5)<<"Transposée"<<endl;
 vector<vector<double>>Lt(n,vector<double>(n));
     for (int i=0;i<n;i++) {
          // Transposée de la Triangulaire inférieure
       for (int j=0;j<n;j++){
	      Lt[i][j]=L[j][i];
              cout << setw(4) << L[j][i] << "\t";
       }
          cout << endl;
      }
      fin = clock();
      double temps;
      temps = ((double)fin-debut) / CLOCKS_PER_SEC;
      cout<<"Temps CPU : "<<temps<<endl;
     //Vérification de la décomposition A = L * Lt:
          //Norme 2 :
  vector<vector<double>>LLt(n,vector<double>(n));
  vector<vector<double>>res(n,vector<double>(n));
  LLt=prod_mat(L,Lt);
  double sum=0.0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      res[i][j] = pow(A[i][j]-LLt[i][j] , 2 ); //calcul de A - L*Lt
      res[i][j] = sqrt( res[i][j] );
      sum+=res[i][j]; //calcul de ||A - L*Lt ||
    }
  }
  cout<<"||A - L*Lt ||2 = "<<sum<<endl;
  if(sum<0.1){cout<<"On a bien A = L*Lt"<<endl;}
  else{cout<<"   "<<endl;}
              //Norme infinie :
  double norme_inf = abs( A[0][0] - LLt[0][0] );
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      res[i][j] = abs( A[i][j] - LLt[i][j] );
      if(res[i][j]>norme_inf){
        norme_inf = res[i][j];
      }
    }
  }
  cout<<"||A - L*Lt ||inf = "<<norme_inf<<endl;
  if(sqrt(n)<4){Affichage(LLt);}
}
