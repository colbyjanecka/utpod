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


int UtPod::addSong(Song const &s){
    if(s.getSize()<=0||s.getArtist()==""||s.getTitle()==""){
        return NOT_FOUND;
    }
    if(s.getSize()>this->getRemainingMemory()){
        return NO_MEMORY;
    }

    UtPod::SongNode * temp = new SongNode;

    (temp->s).setSize(s.getSize());
    (temp->s).setTitle(s.getTitle());
    (temp->s).setArtist(s.getArtist());

    temp->next = songs;
    this->songs = temp;

    return SUCCESS;
}


int UtPod::removeSong(Song const &s) {
    if(songs == NULL){
        return NOT_FOUND;
    }
    Song tempSong = s;
    SongNode *ptr = songs;
    SongNode *tail = songs;

    if(ptr->s == tempSong){
        songs = ptr->next;
        delete (ptr);
        return SUCCESS;
    }
    ptr = ptr->next;

    while(ptr!=NULL){
        if(ptr->s == tempSong){
            tail->next = ptr->next;
            delete  (ptr);
            return SUCCESS;
        }
        ptr = ptr ->next;
        tail = tail->next;
    }
    return NOT_FOUND;
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


int UtPod::getRemainingMemory() {
    SongNode *ptr = songs;

    int count =0;
    while( ptr != NULL){
        count += ptr->s.getSize();
        ptr = ptr->next;
    }

    return (podMemSize-count);
}


void UtPod::sortSongList() {
    for(SongNode *p =songs ;p!=NULL;p=p->next){
        for(SongNode *w = p->next ;w!=NULL;w=w->next){
            if(w->s < p->s){
                swap(w,p);
            }
        }
    }
}

void UtPod::swap(SongNode *s1, SongNode *s2) {
    Song temp;
    temp.setTitle(s1->s.getTitle()  );
    temp.setArtist(s1->s.getArtist()  );
    temp.setSize(s1->s.getSize()  );

    s1->s.setTitle(s2->s.getTitle());
    s1->s.setArtist(s2->s.getArtist());
    s1->s.setSize(s2->s.getSize());

    s2->s.setTitle(temp.getTitle());
    s2->s.setArtist(temp.getArtist());
    s2->s.setSize(temp.getSize());

}






