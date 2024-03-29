container.exe: container-driver.o
	g++ container.o container-driver.o -o container.exe

container-driver.o: container.o
	g++ -c container-driver.cpp -o container-driver.o

container.o: container.cpp
	g++ -c container.cpp -o container.o

clean:
	rm *.o
	rm *.exe
