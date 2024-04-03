main: searchAlgo.o sortAlgo.o helpers.o main.o
	gcc -g -o main main.o helpers.o sortAlgo.o searchAlgo.o

searchAlgo.o: searchAlgo.c searchAlgo.h structDef.h
	gcc -c searchAlgo.c

sortAlgo.o: sortAlgo.c sortAlgo.h structDef.h
	gcc -c sortAlgo.c

helpers.o: helpers.c helpers.h structDef.h
	gcc -c helpers.c

main.o: main.c helpers.h sortAlgo.h searchAlgo.h structDef.h
	gcc -c main.c
clean:
	rm *.o main
