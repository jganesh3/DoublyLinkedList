Playlist : Playlist.o DoublyLinkedList.o 
	       g++ -o Playlist Playlist.o DoublyLinkedList.o 

playlist.o: Playlist.cpp Playlist.h 
	        g++ -c Playlist.cpp

clean: 
	rm *.o Playlist
