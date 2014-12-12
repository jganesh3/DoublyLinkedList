/**
 * @file Playlist.cpp   Implementation of a Playlist for music.
 * 
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger
 * @date 2/1/13
 */

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Playlist.h"
using namespace std;

/**
 * Process a playlist command.
 *
 * Gets an entire line from cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 */
void Playlist::processCommand() {
   string s;
   getline(cin, s);                             // get everything to endl
   string command = s.substr(0, s.find(' '));   // get first word in string
   
   if (command == "appendSong") processAppendSong(s);
   else if (command == "playCurrent") processPlayCurrent();
   else if (command == "gotoSong") processGotoSong(s);
   else if (command == "gotoFirstSong") processGotoFirstSong();
   else if (command == "gotoLastSong") processGotoLastSong();
   else if (command == "insertBefore") processInsertBefore(s);
   else if (command == "insertAfter") processInsertAfter(s);
   else if (command == "removeSong") processRemoveSong(s);
   else if (command == "nextSong") processNextSong();
   else if (command == "prevSong") processPrevSong();
   else if (command == "playForward") processPlayForward();
   else if (command == "playReverse") processPlayReverse();
}

/**
 * Process the appendSong command.
 *
 * Appends the specified song to the end of the playlist. Receives the command
 * line as a string. Removes the command from the beginning, plus one space,
 * leaving just the name of the song. Passes the song to the DLL append
 * function. When done the current song is the one that was appended.
 *
 * @param s Command line with the command, followed by the song name.
 */
void Playlist::processAppendSong(string& s) {
   s.erase(0, s.find(' ')+1);                   // remove command leaving song
   dll.append(s);
}

/**
 * Process the insertBefore command.
 *
 * Inserts the specified song before the current song. Receives the command line
 * as a string. Removes the command from the beginning, plus one space, leaving
 * just the name of the song. Passes the song to the DLL insertBefore function.
 * When done the current song is the one that was inserted.
 *
 * * @param s Command line with the command, followed by the song name.
 */
void Playlist::processInsertBefore(string& s) {
   s.erase(0, s.find(' ')+1);                   // remove command leaving song
   dll.insertBefore(s);
}

/**
 * Process the insertAfter command.
 *
 * Inserts the specified song after the current song. Receives the command line
 * as a string. Removes the command from the beginning, plus one space, leaving
 * just the name of the song. Passes the song to the DLL insertAfter function.
 * When done the current song is the one that was inserted.
 *
 * * @param s Command line with the command, followed by the song name.
 */
void Playlist::processInsertAfter(string& s) {
   s.erase(0, s.find(' ')+1);                   // remove command leaving song
   dll.insertAfter(s);
}

/**
 * Process the removeSong command.
 *
 * Removes the specified song from the playlist. Receives the command line as
 * a string. Removes the command from the beginning, plus one space, leaving
 * just the name of the song. Passes the song to the DLL remove function. If
 * the song is not found, the current song remains unchanged. If the song is
 * removed, the following song, if one exists, becomes the current song. If
 * there is no following song, then the previous song, if one exists, becomes
 * the current song. Otherwise, the playlist is now empty.
 *
 * * @param s Command line with the command, followed by the song name.
 */
void Playlist::processRemoveSong(string& s) {
   s.erase(0, s.find(' ')+1);                   // remove command leaving song
   dll.remove(s);
}

/**
 * Process the playCurrent command.
 *
 * Plays (prints to cout) the current song, if there is one.
 */
void Playlist::processPlayCurrent() {
   cout << endl << "playing current: ";
   if (!dll.empty()) cout << dll.getData() << endl;
}

/**
 * Process the gotoSong command.
 *
 * Makes the specified song the current song. Receives the command line as
 * a string. Removes the command from the beginning, plus one space, leaving
 * just the name of the song. Passes the song to the DLL find function. If the
 * specified song is not found, the current song is unchanged.
 *
 * * @param s Command line with the command, followed by the song name.
 */
void Playlist::processGotoSong(string& s) {
   s.erase(0, s.find(' ')+1);                   // remove command leaving song
   dll.find(s);
}

/**
 * Process the gotoFirstSong command.
 *
 * Makes the first song in the playlist, if any, the current song.
 */
void Playlist::processGotoFirstSong() {
   dll.begin();
}

/**
 * Process the gotoLastSong command.
 *
 * Makes the last song in the playlist, if any, the current song.
 */
void Playlist::processGotoLastSong() {
   dll.end();
}

/**
 * Process the nextSong command.
 *
 * Makes the next song in the playlist the current song. If the current song
 * is already the last song then it is unchanged.
 */
void Playlist::processNextSong() {
   dll.next();
}

/**
 * Process the prevSong command.
 *
 * Makes the previous song in the playlist the current song. If the current
 * song is already the first song then it is unchanged.
 */
void Playlist::processPrevSong() {
   dll.prev();
}

/**
 * Process the playForward command.
 *
 * Beginning with the current song, and progressing through the playlist to
 * the last song, each song is played (printed to cout). When finished, the
 * last song is the current song.
 */
void Playlist::processPlayForward() {
   cout << endl << "playing forward: " << endl;
   if (!dll.empty())
      do {
         cout << dll.getData() << endl;
      }
      while (dll.next());
}

/**
 * Process the playReverse command.
 *
 * Beginning with the current song, and progressing through the playlist in
 * reverse order to the first song, each song is played (printed to cout).
 * When finished, the first song is the current song.
 */
void Playlist::processPlayReverse() {
   cout << endl << "playing reverse: " << endl;
   if (!dll.empty())
      do {
         cout << dll.getData() << endl;
      }
      while (dll.prev());
}

/**
 * The Playlist main loop will process command lines until eof.
 */  
void Playlist::mainLoop() {
   while (!cin.eof()) processCommand();         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}

