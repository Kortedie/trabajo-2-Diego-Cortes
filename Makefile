ARCHIVO = "ips.txt" # $(OBJS)
SENAL = 4 # $(BINARY)


all: ipMain

ipMain: main.o
	g++ main.o -o infoip -lpthread
	./infoip $(ARCHIVO) $(SENAL)

main.o: main.cpp
	@g++ -c main.cpp

clean:
	rm -f ipInfoThread *.o
