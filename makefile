out:main.o ADD.o show.o modify.o sort.o delete.o save.o load.o
	cc main.c ADD.c show.c modify.c sort.c delete.c save.c load.c
main.o:main.c
	cc -c main.c
