#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> mGenreSum;
    vector<vector<int>> vFinData;
    for (int i = 0; i < genres.size(); i++) {
        vFinData.push_back({-plays[i], i });
        if (mGenreSum.find(genres[i]) == mGenreSum.end()) {
            mGenreSum[genres[i]] = plays[i];
        }
        else {
            mGenreSum[genres[i]] += plays[i];
        }
    }
    vector<pair<string, int>> vGenreSum(mGenreSum.begin(), mGenreSum.end());
    sort(vGenreSum.begin(), vGenreSum.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    unordered_map<string, int> mGenreIdx;
    int tIdx = 0;
    for (int i = 0; i < vGenreSum.size(); i++)
    {
        mGenreIdx[vGenreSum[i].first] = tIdx;
        tIdx += 1;   
    }
    for (int i = 0; i < genres.size(); i++) {
        vFinData[i].push_back(mGenreIdx[genres[i]]);
    }
    sort(vFinData.begin(), vFinData.end(), [](const vector<int>& a, vector<int>& b) {
        if (a[2] != b[2]) return a[2] < b[2];
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    unordered_map<int, int> mGenreCnt;
    for (int i = 0; i < vFinData.size(); i++)
    {   
        if (mGenreCnt.find(vFinData[i][2]) == mGenreCnt.end()){
            answer.push_back(vFinData[i][1]);
            mGenreCnt[vFinData[i][2]] = 1;
        }
        else {
            if (mGenreCnt[vFinData[i][2]] == 1) {
                mGenreCnt[vFinData[i][2]] += 1;
                answer.push_back(vFinData[i][1]);
            }
        }
    }
    return answer;
}