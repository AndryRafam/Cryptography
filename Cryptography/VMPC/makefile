Main.exe : VMPC.o Main.o
		 gcc -Wall VMPC.o Main.o -o Main.exe

VMPC.o : VMPC.c VMPC.h
	    gcc -c VMPC.c

Main.o : Main.c VMPC.h
	    gcc -c Main.c
