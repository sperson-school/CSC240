#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string director;
    int releaseYear;
    string rating;

public:
    Movie(string t, string d, int y, string r) {
        title = t;
        director = d;
        releaseYear = y;
        rating = r;
    }

    void printMovie() {
        cout << "=== Movie Information ===" << endl;
        cout << "Title:        " << title << endl;
        cout << "Director:     " << director << endl;
        cout << "Release Year: " << releaseYear << endl;
        cout << "Rating:       " << rating << endl;
        cout << "=========================" << endl << endl;
    }
};

int main() {
    // value semantics
    Movie movie1("Inception", "Christopher Nolan", 2010, "PG-13");

    // reference semantics
    Movie* movie2 = new Movie("The Matrix", "Lana Wachowski", 1999, "R");

    movie1.printMovie();
    movie2->printMovie();

    return 0;
}
