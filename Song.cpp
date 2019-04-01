#include "Song.h"

using namespace std;

Song::Song(string titleIn, string artistIn, int sizeIn){
    title = titleIn;
    artist = artistIn;
    size = sizeIn;
}

Song::Song(){
    title=" ";
    artist=" ";
    size=NULL;
}

void Song::printSong(){
    cout << title << ", \t by: " << artist << ", \t size: " << size << " MB" << endl;
}
