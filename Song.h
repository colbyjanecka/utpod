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
        Song(string title, string artist, int size);

        void printSong();

        //~Song();
};

#endif
