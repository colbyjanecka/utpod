#include "UtPod.h"

using namespace std;

UtPod::UtPod(){

    podMemSize = MAX_MEMORY;
    songs=NULL;

}

UtPod::UtPod(int size) {
    if(size>=MAX_MEMORY||size<=0)
        podMemSize = MAX_MEMORY;
    else
        podMemSize = size;
}

UtPod::~UtPod(){

    SongNode *p = songs;

    while(songs != NULL) {
        p = songs;
        songs = songs->next;
        delete p;
    }
}

void UtPod::showSongList(){
    if(songs==NULL){
        return;
    }
    SongNode *pt = songs;
    while(pt!=NULL){
        pt->s.printSong();
        pt = pt->next;
    }
}
