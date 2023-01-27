#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

//Fonctions matrice1.cpp :
vector< vector < double > > matrice_laplacien(int n);

//Fonctions relax2.cpp :
bool test_relaxation(vector<double> xk, vector<double> xk_plus1, int k);
double somme_relaxation_creux (vector< vector<double> > A, vector<double> xk,int i);
void Relaxation_methode_creux (vector < vector<double> > A, vector<double> B);

//Fonctions cholesky.cpp :
vector< vector<double> > remplissage (vector< vector<double> >& vec);
bool symetrique (vector< vector<double> > vec);
void Affichage (vector< vector<double> > vec);
void cholesky( vector< vector<double> > vec);
void exercice1(vector< vector<double> > A);
double sum(vector< vector<double> > vec,int j,int z);
vector<vector<double>> prod_mat(vector<vector<double>> L,vector<vector<double>> U);

//Fonctions LU1.cpp :
void affichage(vector<vector <double> > mat);
void decomp_lu(vector<vector<double>>mat,vector<vector<double>>& L,vector<vector<double>>& U);
void re_sys_lu(vector<vector<double>>mat,vector<double>b,vector<double>x);

//Fonctions Jacobi.cpp :
void Jacobi (vector< vector<double> > mat,vector<double> b );
double somme( vector< vector<double> > A, vector<double> x,int i);
vector< vector<double> > remplissage_matrice();
void affichage_( vector<double> vec);
