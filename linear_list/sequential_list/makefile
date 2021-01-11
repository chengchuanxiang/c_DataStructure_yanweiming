objects = main.o sqList_test.o sequential_list.o
main : $(objects)
	cc -o main $(objects)
main.o : main.c sqList_test.h
	cc -c main.c
sqList_text.o : sqList_test.c sqList_test.h sequential_list.h ../../predefined/predefined.h
	cc -c sqList_test.c	
sequential_list : sequential_list.c sequential_list.h
	cc -c sequential_list.c

clean:
	rm main $(objects)
