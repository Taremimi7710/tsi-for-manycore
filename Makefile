#Makefile for TSI
#Ver1.00 - 2019-10-04

#Use Your C Compiler
CC = icc

#Compiler flags.
CFLAGS = -w

tsi : main.o getmem.o getmodel.o gettemp.o getthread.o getusage.o termout.o termmem.o
	$(CC) $(CFLAGS) main.o getmem.o getmodel.o gettemp.o getthread.o getusage.o termout.o termmem.o -o tsi

main.o : main.c
	$(CC) -c $(CFLAGS) main.c 

getmem.o: getmem.c
	$(CC) -c $(CFLAGS) getmem.c

getmodel.o : getmodel.c
	$(CC) -c $(CFLAGS) getmodel.c

gettemp.o : gettemp.c
	$(CC) -c $(CFLAGS) gettemp.c

getthread.o : getthread.c
	$(CC) -c $(CFLAGS) getthread.c

getusage.o : getusage.c
	$(CC) -c $(CFLAGS) getusage.c

termout.o : termout.c
	$(CC) -c $(CFLAGS) termout.c

termmem.o : termmem.c
	$(CC) -c $(CFLAGS) termmem.c

.PHONY: clear
clear: 
	rm *.o
