#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;
class Song {
    private:
        string title;
        string artist;
        int memSize;

        static const int MAX_MEMSIZ = 512;

    public:
        Song();
        Song(string artist, string title, int memSize);
        string getTitle () const;
        void setTitle (string t);
        string getArtist () const;
        void setArtist (string a);
        int getMemSize () const;
        void setMemSize (int ms);
        void printS ();
        bool operator == (Song const &rhs);
        bool operator > (Song const &rhs);
};

#endif