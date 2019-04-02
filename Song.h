#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Song {

private:
    string title;
    string artist;
    int size;

public:
    Song();
    Song(string artistIn, string titleIn, int sizeIn);

    void printSong();

    void setTitle(string titleIn) {
        title = titleIn;
    }

    void setArtist(string artistIn){
        artist = artistIn;
    }

    void setSize(int sizeIn){
        size = sizeIn;
    }

    string getTitle() const {
        return title;
    }

    string getArtist() const {
        return artist;
    }

    int getSize() const {
        return size;
    }
    void swap(Song &s2);


    bool operator !=(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator =(Song const &rhs);
    //~Song();
};

#endif