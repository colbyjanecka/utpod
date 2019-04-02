#include "Song.h"

using namespace std;

Song::Song(string artistIn, string titleIn, int sizeIn){
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




bool Song::operator==(Song const &rhs) {
    if((artist == rhs.artist) && (title == rhs.title) &&( size == rhs.size)){
        return true;
    } else {
        return false;
    }
}

bool Song::operator!=(Song const &rhs) {
    if((artist != rhs.artist) || (title != rhs.title) ||( size != rhs.size)){
        return true;
    } else {
        return false;
    }
}

bool Song::operator=(Song const &rhs) {
    artist = rhs.getArtist();
    title = rhs.getTitle();
    size = rhs.getSize();
    return true;
}

bool Song::operator>(Song const &rhs) {
    if(artist.compare(rhs.artist)>0){
        return true;
    }
    if(title.compare(rhs.title)>0){
        return true;
    }
    if(size>rhs.size){
        return true;
    }
    if(artist.compare(rhs.artist)<0){
        return false;
    }
    if(title.compare(rhs.title)<0){
        return false;
    }
    if(size<rhs.size){
        return false;
    }

        return false;
}

bool Song::operator<(Song const &rhs) {
    if(artist.compare(rhs.artist)>0){
        return false;
    }
    if(title.compare(rhs.title)>0){
        return false;
    }
    if(size>rhs.size){
        return false;
    }
    if(artist.compare(rhs.artist)<0){
        return true;
    }
    if(title.compare(rhs.title)<0){
        return true;
    }
    if(size<rhs.size){
        return true;
    }

    return true;
}
