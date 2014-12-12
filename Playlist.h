/**
 * @file Playlist.h   Declaration of a Playlist for music.
 * 
 * @brief
 *    Implementation of Playlist for music, where a doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger
 * @date 2/1/13
 */

#ifndef CSCI_311_PLAYLIST_H
#define CSCI_311_PLAYLIST_H

class Playlist {
public:
   void mainLoop();                    // process commands until done
private:
   DoublyLinkedList dll;               // playlist stored in doubly linked list
   
   void processCommand();              // read and process one playlist command
   void processAppendSong(string&);    // appends song to playlist
   void processInsertBefore(string&);  // insert song before current position
   void processInsertAfter(string&);   // insert song after current position
   void processRemoveSong(string&);    // removes the specified song
   void processPlayCurrent();          // "plays" song at the current position
   void processGotoSong(string&);      // sets the current position to song
   void processGotoFirstSong();        // goes to the first song
   void processGotoLastSong();         // goes to the last song
   void processNextSong();             // go to next song
   void processPrevSong();             // go to previous song
   void processPlayForward();          // "play" all songs from current to end
   void processPlayReverse();          // "play" all songs from current to start
};

#endif // CSCI_311_PLAYLIST_H