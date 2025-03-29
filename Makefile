CC = clang
MCFLAGS = -static -nostdlib -nostartfiles -nodefaultlibs
RFLAGS = -s
DFLAGS = -g
OUTD = eog
OUTR = eo
IN = eo.c

debug : $(OUTD)

$(OUTD) : $(IN)
	$(CC) $(DFLAGS) $(MCFLAGS) -o $(OUTD) $(IN)
	gdb ./$(OUTD)

run : $(OUTR)

$(OUTR) : $(IN)
	$(CC) $(RFLAGS) $(MCFLAGS) -o $(OUTR) $(IN)
	./$(OUTR) e 8 102

clean :
	rm -rf $(OUTD) $(OUTR)
