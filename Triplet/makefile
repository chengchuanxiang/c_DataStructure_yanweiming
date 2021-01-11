objects = main.o Triplet.o Triplet_text.o
main : $(objects)
	cc -o main $(objects)
main.o : main.c Triplet_text.h
	cc -c main.c
Triplet.o : Triplet.c Triplet.h
	cc -c Triplet.c
Triplet_text.o : Triplet_text.c Triplet.h
	cc -c Triplet_text.c

clean :
	rm main $(objects)
