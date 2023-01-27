all : projet

projet : cholesky.o relax2.o matrice1.o lu1.o jacobi.o main.o
	g++ -Wall cholesky.o relax2.o matrice1.o lu1.o jacobi.o main.o -o projet

cholesky.o : cholesky.cpp projet.h
	g++ -Wall -c cholesky.cpp

relax2.o : relax2.cpp projet.h
	g++ -Wall -c relax2.cpp

matrice1.o : matrice1.cpp projet.h
	g++ -Wall -c matrice1.cpp

lu1.o : lu1.cpp projet.h
	g++ -Wall -c lu1.cpp

jacobi.o : jacobi.cpp projet.h
	g++ -Wall -c jacobi.cpp

main.o : main.cpp projet.h
	g++ -Wall -c main.cpp

clean :
	rm -f *.o TTP
