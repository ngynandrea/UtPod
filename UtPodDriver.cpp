#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    cout<< "CONSTRUCT UT POD" << endl;
    UtPod t;
    cout<< "TOTAL MEMORY: " << t.getTotalMemory() << endl;
    cout << "----------------------------------------------------" << endl;

    Song s1("Taylor Swift", "All Too Well", 24);
    cout<< "ADD SONG: ";
    s1.printS();
    int result = t.addSong(s1);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = " << result << endl;
    t.showSongList();
    cout << "----------------------------------------------------" << endl;

    Song s2("Khalid", "Saturday Nights", 0);
    cout<< "ADD SONG: ";
    s2.printS();
    result = t.addSong(s2);
    cout << "Expected result = -1" << endl;
    cout << "Actual result = "<< result << endl;
    t.showSongList();
    cout << "----------------------------------------------------" << endl;

    Song s3("Oh Wonder", "Drive", 488);
    cout<< "ADD SONG: ";
    s3.printS();
    result = t.addSong(s3);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t.showSongList();
    cout << "----------------------------------------------------" << endl;

    Song s4("Taylor Swift", "Wildest Dreams", 4);
    cout<< "ADD SONG: ";
    s4.printS();
    result = t.addSong(s4);
    cout << "Expected result = -1" << endl;
    cout << "Actual result = "<< result << endl;
    t.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout<< "CLEAR MEMORY" << endl;
    t.clearMemory();
    t.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout<< "CONSTRUCT UT POD WITH MEMORY SIZE 120" << endl;
    UtPod t2(120);
    cout<< "TOTAL MEMORY: " << t2.getTotalMemory() << endl;
    cout << "----------------------------------------------------" << endl;

    Song s5("Noah Kahan", "Come Down", 24);
    cout<< "ADD SONG: ";
    s5.printS();
    result = t2.addSong(s5);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    Song s6("Noah Kahan", "Come Down", 5);
    cout<< "ADD SONG: ";
    s6.printS();
    result = t2.addSong(s6);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout << "GET REMAINING MEMORY "<< t2.getRemainingMemory() << endl;
    cout << "----------------------------------------------------" << endl;

    Song s7("Noah Kahan", "Passenger", 8);
    cout<< "ADD SONG: ";
    s7.printS();
    result = t2.addSong(s7);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout<< "ADD SONG: ";
    s7.printS();
    result = t2.addSong(s7);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout<< "ADD SONG: ";
    s1.printS();
    result = t2.addSong(s1);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout << "SHUFFLE " << endl;
    t2.shuffle();
    t2.showSongList();
    cout << "SORT" << endl;
    t2.sortSongList();
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout<< "DELETE SONG: ";
    s5.printS();
    result = t2.removeSong(s5);
    cout << "Expected result = 0" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;

    cout<< "DELETE SONG: ";
    s5.printS();
    result = t2.removeSong(s5);
    cout << "Expected result = -1" << endl;
    cout << "Actual result = "<< result << endl;
    t2.showSongList();
    cout << "----------------------------------------------------" << endl;


}