all: war run

war: card.o driver.o standardDeck.o NonStandardDeck.o deck.o
	g++ card.o driver.o standardDeck.o NonStandardDeck.o deck.o -o war

card.o: card.cpp
	g++ -c card.cpp -o card.o
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

standardDeck.o: standardDeck.cpp
	g++ -c standardDeck.cpp -o standardDeck.o

NonStandardDeck.o: NonStandardDeck.cpp
	g++ -c NonStandardDeck.cpp -o NonStandardDeck.o

deck.o: deck.cpp
	g++ -c deck.cpp -o deck.o

clean:
	rm -rf *.o war

run:
	./war
