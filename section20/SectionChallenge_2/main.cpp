// Section 20 - Challenge 2
//  Lists - My solution

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(25) << std::left << s.name
       << std::setw(35) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Playing :" << std::endl;
    std::cout << song << std::endl;

}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    
    std::cout << std::endl;

    for (auto it : playlist) {
        std::cout << it << std::endl;
    }

    std::cout << "Current song : " << std::endl;
    std::cout << current_song << std::endl;
}

int main() {
    char ch;        // to store user's choice

    // list of Song class object
    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
        
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist,*current_song);

    while (true) {
        display_menu();

        std::cin >> ch;
        ch = ::toupper(ch);

        switch (ch)
        {
            case 'F':
                std::cout << "\nPlaying First song..." << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
                
                break;
        
            case 'N':
                std::cout << "\nPlaying Next song..." << std::endl;
                
                if (current_song == --std::end(playlist)) {
                    current_song = std::begin(playlist);
                }
                else {
                current_song = ++current_song;
                }

                play_current_song(*current_song);
                
                break;

            case 'P':
                std::cout << "\nPlaying Previous song..." << std::endl;
                
                if (current_song == std::begin(playlist)) {
                    current_song = --std::end(playlist);
                }
                else {
                current_song = --current_song;
                }

                play_current_song(*current_song);
                
                break;

            case 'A': {
                std::string name;
                std::string artist;
                int rating;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

                std::cout << "\nAdding and Playing new song..." << std::endl;
                std::cout << "Enter song name : ";
                getline(std::cin, name);
                std::cout << "Enter song artist : ";
                getline(std::cin, artist);
                std::cout << "Enter your rating (1-5) : ";
                std::cin  >> rating;
                
                playlist.emplace(current_song, name, artist, rating);
                
                --current_song;
                play_current_song(*current_song);
                
                break;
            }
            case 'L':
                display_playlist(playlist,*current_song);
                break;

            case 'Q':
                return 0;

            default:
                std::cout << "Invalid choice..." << std::endl;
                break;
        }
    }

    return 0;
}
