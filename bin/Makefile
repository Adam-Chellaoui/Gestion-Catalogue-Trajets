FLAGS = -ansi -pedantic -Wall -std=c++11 -g

Trajet+: main.o Trajet.o CelluleTrajet.o ListeChainee.o TrajetSimple.o TrajetCompose.o Catalogue.o
	g++ $(FLAGS) $^ -o $@

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

Trajet.o: Trajet.cpp
	g++ $(FLAGS) -c Trajet.cpp
	
TrajetSimple.o: Trajet.cpp TrajetSimple.cpp
	g++ $(FLAGS) -c $^	

CelluleTrajet.o: CelluleTrajet.cpp
	g++ $(FLAGS) -c CelluleTrajet.cpp

ListeChainee.o: ListeChainee.cpp
	g++ $(FLAGS) -c ListeChainee.cpp

TrajetCompose.o:Trajet.cpp TrajetCompose.cpp
	g++ $(FLAGS) -c $^
	
Catalogue.o: Catalogue.cpp 
	g++ $(FLAGS) -c Catalogue.cpp	

clean:
	rm *.o Programme
