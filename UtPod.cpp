#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "UtPod.h"

using namespace std;

    UtPod::UtPod() {
        memSize = MAX_MEMORY;
        songs = NULL;
        songCount = 0;
    }

    UtPod::UtPod(int size) {
        if (size > MAX_MEMORY || size <= 0)
            memSize = MAX_MEMORY;
        else
            memSize = size;
        songs = NULL;
        songCount = 0;
    }

    int UtPod::addSong(Song const &s) {
        if (s.getMemSize() > getRemainingMemory() ||  s.getMemSize() == 0 || s.getTitle() == "" || s.getArtist() == "")
            return -1;
        else {
            SongNode *temp = new SongNode();
            temp->s = s;
            temp->next = songs;
            songs = temp;
            songCount ++;
            return 0;
        }
    }

    int UtPod::removeSong(Song const &s){
        bool found = false;
        struct SongNode *temp = songs;
        struct SongNode *follow_temp = NULL;
        while(temp != NULL  && !found) {
            if (temp->s ==  s) {
                found = true;
            }
            else {
                follow_temp = temp;
                temp = temp->next;
            }
        }
        if (found) {
            if (follow_temp == NULL) {
                songs = temp->next;
            }
            else {
                follow_temp->next = temp->next;
            }
            delete (temp);
            songCount --;
            return 0;
        }
        else
            return -1;

    }



    void UtPod::shuffle() {
        if (songs != NULL) {

            unsigned int currentTime = (unsigned) time(0);
            srand(currentTime);
            long s1;
            long s2;
            for (int c = 0; c < songCount; c++) {
                s1 = rand() %songCount;
                s2 = rand() %songCount;
                struct SongNode *temp1 = songs;
                for (int k = 0; k < s1; k++) {
                    temp1 = temp1->next;
                }
                struct SongNode *temp2 = songs;
                for (int k = 0; k < s2; k++) {
                    temp2 = temp2->next;
                }
                swap(temp1, temp2);
            }
        }
    }

    void UtPod::showSongList(){
        cout << "Song List" << endl;
        struct SongNode *temp = songs;
        while(temp != NULL) {
          (temp->s).printS();
            temp = temp->next;
        }
    }

    void UtPod::sortSongList() {
        struct SongNode *fhead = songs;
        int c = 1;
        while (fhead != NULL) {
            struct SongNode *temp = fhead;
            struct SongNode *b = temp;
            if (temp != NULL) {
                Song best = temp->s;
                for (int k = c; k < songCount; k++) {
                    temp = temp->next;
                    if (best > temp->s) {
                     b = temp;
                     best = temp->s;
                    }
                }
                swap(b, fhead);
                fhead = fhead->next;
                c++;
            }
        }
    }

    void UtPod::clearMemory() {
        struct SongNode *temp;
        while (songs != NULL) {
            temp = songs;
            songs = temp->next;
            delete(temp);
        }
    }

    int UtPod::getRemainingMemory() {
        struct SongNode *temp = songs;
        int sumMem = 0;
        while(temp != NULL) {
            sumMem += (temp->s).getMemSize();
            temp = temp->next;
        }
        return memSize- sumMem;
    }

    void UtPod::swap(SongNode *s1, SongNode *s2) {
        Song temp = s1->s;
        s1->s = s2->s;
        s2->s = temp;
    }


    UtPod::~UtPod(){
        clearMemory();
    }