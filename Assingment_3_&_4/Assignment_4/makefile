meq: main.o system.o event.o cpu.o pipeline.o cache.o membus.o
	g++ main.o system.o event.o cpu.o pipeline.o cache.o membus.o -o meq

main.o: main.cpp
	g++ -c main.cpp

system.o: system.cpp
	g++ -c system.cpp

event.o: event.cpp
	g++ -c event.cpp

cpu.o: cpu.cpp
	g++ -c cpu.cpp
	
pipeline.o: pipeline.cpp
	g++ -c pipeline.cpp

cache.o: cache.cpp
	g++ -c cache.cpp

membus.o: membus.cpp
	g++ -c membus.cpp

clean:
	rm *.o meq
