#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


double getScore() {
    double score;
    do {
        cout << "Enter a score between 0 and 10: ";
        cin >> score;
        if (score < 0 || score > 10) {
            cout << "Invalid score. Please enter a score between 0 and 10." << endl;
        }
    } while (score < 0 || score > 10);
    return score;
}


double findLowest(const vector<double>& scores) {
    return *min_element(scores.begin(), scores.end());
}


double findHighest(const vector<double>& scores) {
    return *max_element(scores.begin(), scores.end());
}

double calculateAverage(vector<double> scores) {
    if (scores.size() < 3) return 0;

    double lowest = findLowest(scores);
    double highest = findHighest(scores);

    scores.erase(remove(scores.begin(), scores.end(), lowest), scores.end());
    if(lowest == highest){
        scores.erase(remove(scores.begin(), scores.end(), highest), scores.end());
    } else {
         scores.erase(remove(scores.begin(), scores.end(), highest), scores.end());
    }


    double sum = accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}

int main() {
    cout << "This program calculates a performer's score." << endl;
    cout << "Five judges will each contribute a score, the highest and lowest scores will be dropped, and the remaining three will be averaged." << endl;

    vector<double> scores;
    for (int i = 1; i <= 5; ++i) {
        cout << "Score from judge " << i << ": ";
        scores.push_back(getScore());
    }

    double averageScore = calculateAverage(scores);

    cout << "The performer's final score is: " << averageScore << endl;

    return 0;
}