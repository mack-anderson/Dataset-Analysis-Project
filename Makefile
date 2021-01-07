all: babiesQuery babyQuery babyQuery.o removeCommas.o reduceSpace.o chop.o

babyQuery: babyQuery.o removeCommas.o reduceSpace.o chop.o
	gcc -ansi -Wall -o babyQuery babyQuery.o removeCommas.o reduceSpace.o chop.o

babiesQuery: babiesQuery.o removeCommas.o reduceSpace.o chop.o
	gcc -ansi -Wall -o babiesQuery babiesQuery.o removeCommas.o reduceSpace.o chop.o

babyQuery.o:
	gcc -ansi -Wall -c babyQuery.c

babiesQuery.o:
	gcc -ansi -Wall -c babiesQuery.c

removeCommas.o:
	gcc -ansi -Wall -c removeCommas.c

chop.o: chop.c
	gcc -ansi -Wall -c chop.c

reduceSpace.o: reduceSpace.c
	gcc -ansi -Wall -c reduceSpace.c

clean:
	rm -f *.o
	rm babyQuery
	rm babiesQuery
