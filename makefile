obj =$(patsubst %.c,%.o,$(wildcard *.c))
apc.exc : $(obj)
	gcc -o apc.exe $(obj)

clean:
	rm *.exe *.o
