#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;

    Song::Song() {
        title= "";
        artist = "";
        memSize = 0;
    }

    Song::Song(string artist, string title, int memSize ){
        this->title = title;
        this->artist = artist;
        this->memSize = memSize;
    }

    string Song::getTitle() const {
        return title;
    }

    void Song::setTitle(string t) {
        title = t;
    }

    string Song::getArtist() const {
        return artist;
    }

    void Song::setArtist(string a) {
        artist = a;
    }

    int Song::getMemSize() const {
        return memSize;
    }

    void Song::setMemSize(int ms) {
        memSize = ms;
    }

    void Song::printS() {
        cout << getTitle() << " , " << getArtist() << " , " << getMemSize() << endl;
    }
    bool Song::operator > (Song const &rhs) {

        if (artist != rhs.artist)
            return (artist > rhs.artist);
        else
            if (title != rhs.title)
                return title > rhs.title;
            else
                return memSize > rhs.memSize;


    }
    bool Song::operator ==(Song const &rhs) {
        return (title == rhs.title && artist == rhs.artist && memSize == rhs.memSize);
    }